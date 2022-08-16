#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "fileSize.h"

void disassembleRomChip8(uint8_t *codebuffer, int programCounter) {
    uint8_t *code = &codebuffer[programCounter];
    uint8_t firstnib = (code[0] >> 4);

    printf("%04x %02x %02x ", programCounter, code[0], code[1]);
    switch (firstnib)
    {
        case 0x00: printf("0 not done"); break;
        case 0x01: printf("1 not done"); break;
        case 0x02: printf("2 not done"); break;
        case 0x03: printf("3 not done"); break;
        case 0x04: printf("4 not done"); break;
        case 0x05: printf("5 not done"); break;
        case 0x06:
        {
            uint8_t reg = code[0] & 0x0f;
            printf("%-10s V%01X,#$%02x", "MVI", reg, code[1]);
        }
            break;
        case 0x07: printf("7 not done"); break;
        case 0x08: printf("8 not done"); break;
        case 0x09: printf("9 not done"); break;
        case 0x0a:
        {
            uint8_t addresshi = code[0] & 0x0f;
            printf("%-10s I,#$%01x%02x", "MVI", addresshi, code[1]);
        }
            break;
        case 0x0b: printf("b not handled yet"); break;
        case 0x0c: printf("c not handled yet"); break;
        case 0x0d: printf("d not handled yet"); break;
        case 0x0e: printf("e not handled yet"); break;
        case 0x0f: printf("f not handled yet"); break;
    }
}

int main(int argc, char** argv) {
    FILE *fp = fopen(argv[1], "rb");
    long filesize = findFileSize(argv[1]);
    printf("%ld\n", filesize);
    uint8_t *buffer=malloc(filesize+0x200);
    fread(buffer+0x200, filesize, 1, fp);
    fclose(fp);

    int pc = 0x200;
    while (pc < (filesize+0x200))
    {
        disassembleRomChip8(buffer, pc);
        pc += 2;
        printf ("\n");
    }
    return 0;
}
