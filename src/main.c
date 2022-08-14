#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "fileSize.h"

void disassembleRomChip8(uint8_t *codebuffer) {
    printf("TEST");
}

int main(int argc, char** argv) {
    FILE *fp = fopen(argv[1], "rb");
/*    long filesize = findFileSize(argv[1]);
    printf("%d", filesize);*/

    return 0;
}
