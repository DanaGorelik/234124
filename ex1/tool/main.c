#include "AsciiArtTool.h"
#include <stdio.h>
#include <string.h>
#define ARG_NUM 4
#define AT_SIGN_ASCII '@'
#define SPACE_ASCII ' '


char switchChar (char character);

int main(int argc, char** argv) {
    if (argc != ARG_NUM) {
        return 0;
    }
    char* flag = argv[1];
    FILE* source = fopen(argv[2], "r") ;
    if(!source) {
        return 0;
    }

    FILE* target = fopen(argv[3], "w");
    if(!target) {
        fclose(source);
        return 0;
    }
    if((strcmp(flag, "-e") != 0) && (strcmp(flag, "-i") != 0)) {
        fclose(source);
        fclose(target);
        return 0;
    }
    if(strcmp(flag, "-e") == 0) {
        RLEList list = asciiArtRead(source);
        if (list == NULL) {
            fclose(source);
            fclose(target);
            return 0;
        }
        asciiArtPrintEncoded(list, target);
        RLEListDestroy(list);
    }
    if(strcmp(flag, "-i") == 0) {
        RLEList list = asciiArtRead(source);
        if (list == NULL) {
            fclose(source);
            fclose(target);
            return 0;
        }
        if(RLEListMap(list, switchChar) == RLE_LIST_SUCCESS) {
            asciiArtPrint(list, target);
            RLEListDestroy(list);
        }

    }
    fclose(source);
    fclose(target);
    return 0;
}

char switchChar (char character)
{
    if (character == SPACE_ASCII) {
        return AT_SIGN_ASCII;
    }
    else if (character == AT_SIGN_ASCII) {
        return SPACE_ASCII;
    }
    return character;
}


