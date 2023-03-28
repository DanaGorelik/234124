#ifndef EX1_NEW_ASCIIARTTOOL_H
#define EX1_NEW_ASCIIARTTOOL_H

#endif //EX1_NEW_ASCIIARTTOOL_H

#include "RLEList.h"

RLEList asciiArtRead(FILE* in_stream);
RLEListResult asciiArtPrint(RLEList list, FILE *out_stream);
RLEListResult asciiArtPrintEncoded(RLEList list, FILE *out_stream);