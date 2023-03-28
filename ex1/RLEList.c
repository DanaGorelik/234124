#include "RLEList.h"
#include <stdlib.h>
#include <stdio.h>
#define EMPTY_CHAR '\0'
#define NULL_PTR -1
#define INITIALIZE_NUM_TIMES 0
#define NEW_NODE_NUM_TIMES 1
#define DECIMAL 10
#define EXTRA_SPACE 2

struct RLEList_t {
    char character;
    int numTimes;
    struct RLEList_t *next;
};

static int sizeOfNumFunc(int num);
static int sizeOfStringFunc(RLEList list);

RLEList RLEListCreate() {
    RLEList new = malloc(sizeof(*new));
    if (!new) {
        return NULL;
    }
    new->character = EMPTY_CHAR;
    new->numTimes = INITIALIZE_NUM_TIMES;
    new->next = NULL;
    return new;
}

void RLEListDestroy(RLEList list) {
    if (list == NULL) {
        return;
    }
    while (list) {
        RLEList tmp = list;
        list = list->next;
        free(tmp);
    }
}

RLEListResult RLEListAppend(RLEList list, char value) {
    if (list == NULL || value == EMPTY_CHAR) {
        return RLE_LIST_NULL_ARGUMENT;
    }
    RLEList new;
    if (list->next == NULL) {
        new = malloc(sizeof(*new));
        if (!new) {
            return RLE_LIST_OUT_OF_MEMORY;
        }
        list->next = new;
        new->character = value;
        new->numTimes = NEW_NODE_NUM_TIMES;
        new->next = NULL;
        return RLE_LIST_SUCCESS;
    }
    while (list->next != NULL) {
        list = list->next;
    }
    if (list->character == value) {
        (list->numTimes)++;
        return RLE_LIST_SUCCESS;
    } else {
        new = malloc(sizeof(*new));
        if (!new) {
            return RLE_LIST_OUT_OF_MEMORY;
        }
        list->next = new;
        new->character = value;
        new->numTimes = NEW_NODE_NUM_TIMES;
        new->next = NULL;
        return RLE_LIST_SUCCESS;
    }
}

int RLEListSize(RLEList list)
{
    int count = 0;
    RLEList ptr = list;
    if (list == NULL) {
        free(ptr);
        return NULL_PTR;
    }
    while (ptr != NULL)
    {
        count += ptr->numTimes;
        ptr = ptr->next;
    }
    free(ptr);
    return count;
}

RLEListResult RLEListRemove(RLEList list, int index) {
    RLEList previousPtr = list;
    if (list == NULL) {
        return RLE_LIST_NULL_ARGUMENT;
    }
    if (index < 0) {
        return RLE_LIST_INDEX_OUT_OF_BOUNDS;
    }
    if (index > (RLEListSize(list)) - 1)
    {
        return RLE_LIST_INDEX_OUT_OF_BOUNDS;
    }
    list = list->next;
    while (index >= 0 && index >= list->numTimes) {
        index -= list->numTimes;
        list = list->next;
        previousPtr = previousPtr->next;
    }

    if (list->numTimes == 1) {
        RLEList toDelete = list;
        list = previousPtr;
        if (toDelete->next != NULL && list->character == toDelete->next->character) {
            list->numTimes += toDelete->next->numTimes;
            if(toDelete->next->next != NULL) {
                list->next = toDelete->next->next;
                toDelete->next->next = NULL;
                free(toDelete->next);
                toDelete->next = NULL;
                free(toDelete);
                return RLE_LIST_SUCCESS;
            }
            toDelete->next = NULL;
            free(toDelete->next);
            list->next = NULL;
            free(toDelete);
            return RLE_LIST_SUCCESS;
        }
        list->next = toDelete->next;
        toDelete->next = NULL;
        free(toDelete);
        return RLE_LIST_SUCCESS;
    }
    list->numTimes--;
    return RLE_LIST_SUCCESS;
}

char RLEListGet(RLEList list, int index, RLEListResult *result) {
    char character;
    if (list == NULL) {
        if(result == NULL) {
            return 0;
        }
        *result = RLE_LIST_NULL_ARGUMENT;
        return 0;
    }
    if (index > RLEListSize(list) - 1 || index < 0) {
        if(result == NULL) {
            return 0;
        }
        *result = RLE_LIST_INDEX_OUT_OF_BOUNDS;
        return 0;
    }
    list = list->next;
    while (list != NULL) {
        if (index > list->numTimes) {
            index -= list->numTimes;
            list = list->next;
        } else {
            if (index == list->numTimes) {
                list = list->next;
                character = list->character;
            }
            else
                character = list->character;
            if (result == NULL) {
                return character;
            }
            *result = RLE_LIST_SUCCESS;
            return character;
        }
    }
    return 0;
}

char* RLEListExportToString(RLEList list, RLEListResult* result) {
    RLEList tmp = list;
    if (!list) {
        *result = RLE_LIST_NULL_ARGUMENT;
        return NULL;
    }
    list = list->next;
    //check size of string to return
    int countSize = sizeOfStringFunc(list);
    char *strToPrint = malloc(countSize * sizeof(*strToPrint));
    if (!strToPrint) {
        return NULL;
    }
    tmp = tmp->next;
    int index = 0;
    while (tmp != NULL) {
        strToPrint[index] = tmp->character;
        int tmpOfNum = tmp->numTimes;
        //check size of num
        int sizeOfNum = sizeOfNumFunc(tmp->numTimes);
        int tmpSizeOfNum = sizeOfNum;
        while (tmpOfNum > 0) {
            strToPrint[index + tmpSizeOfNum] = '0' + tmpOfNum % DECIMAL;
            tmpOfNum /= DECIMAL;
            tmpSizeOfNum--;
        }
        index += (sizeOfNum + 1);
        strToPrint[index] = '\n';
        index++;
        tmp = tmp->next;
    }
    strToPrint[index] = EMPTY_CHAR;
    if (result == NULL) {
        return strToPrint;
    }
    *result = RLE_LIST_SUCCESS;
    return strToPrint;
}

RLEListResult RLEListMap(RLEList list, MapFunction map_function) {
    if (list == NULL) {
        return RLE_LIST_NULL_ARGUMENT;
    }
    if (map_function == NULL) {
        return RLE_LIST_NULL_ARGUMENT;
    }
    RLEList startList = list;
    RLEList newList = RLEListCreate();
    RLEList startNewList = newList;
    if (newList == NULL) {
        return RLE_LIST_ERROR;
    }
    while (list != NULL) {
        for (int i = 0; i < list->numTimes; i++) {
            RLEListAppend(newList, list->character);
        }
        list = list->next;
    }
    list = startList;
    int len = RLEListSize(list) - 1;
    for (int i = len; i >= 0; i--) {
        RLEListRemove(list, i);
    }
    while (newList != NULL) {
        for (int i = 0; i < newList->numTimes; i++) {
            char character = newList->character;
            char newCharacter = map_function(character);
            RLEListAppend(list, newCharacter);
        }
        newList = newList->next;
    }
    newList = startNewList;
    RLEListDestroy(newList);
    return RLE_LIST_SUCCESS;
}

static int sizeOfNumFunc(int num) {
    int sizeOfNum = 0;
    while (num > 0) {
        num = (num)/DECIMAL;
        sizeOfNum++;
    }
    return sizeOfNum;
}

static int sizeOfStringFunc(RLEList list)
{
    int countSize = 1;
    while (list != NULL) {
        int tmpNumTimes = list->numTimes;
        int sizeOfNum = 0;
        while (tmpNumTimes > 0) {
            tmpNumTimes = (tmpNumTimes) / DECIMAL;
            sizeOfNum++;
        }
        countSize += sizeOfNum + EXTRA_SPACE;
        list = list->next;
    }
    return countSize;
}
