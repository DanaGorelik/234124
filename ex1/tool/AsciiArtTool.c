#include "AsciiArtTool.h"
#include <stdlib.h>
#include <stdio.h>
#define EMPTY_CHAR '\0'

RLEList asciiArtRead(FILE* in_stream) {
    if (in_stream==NULL)
        return NULL;
    RLEList newList = RLEListCreate();
    if (!newList)
    {
        return 0;
    }
    char character = EMPTY_CHAR;
    while((character = (char)fgetc(in_stream)) != EOF){
        RLEListAppend(newList, character);
    }
    return newList;
}

RLEListResult asciiArtPrint(RLEList list, FILE *out_stream) {
    if (list == NULL) {
        return RLE_LIST_NULL_ARGUMENT;
    }
    int RLELen = RLEListSize(list);
    for (int i = 0; i < RLELen; i++) {
        RLEListResult result;
        char character = RLEListGet(list, i, &result);
        if(result != RLE_LIST_SUCCESS) {
            return RLE_LIST_NULL_ARGUMENT;
        }
        fputc(character, out_stream);
    }
    return RLE_LIST_SUCCESS;
}

RLEListResult asciiArtPrintEncoded(RLEList list, FILE *out_stream) {
    if (!list || !out_stream)
        return RLE_LIST_NULL_ARGUMENT;
    char* str = RLEListExportToString(list, NULL);
    if (fputs(str, out_stream) == EOF) {
        free(str);
        return RLE_LIST_NULL_ARGUMENT;
    }
    free(str);
    return RLE_LIST_SUCCESS;
}