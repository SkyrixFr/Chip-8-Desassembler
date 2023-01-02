#include <stdint.h>
#include <stdlib.h>
#include "fileSize.h"

void disassembleRomChip8(uint8_t *codebuffer, int16_t programCounter) {
    uint8_t *code = &codebuffer[programCounter];
    
    uint8_t firstnib = (code[0] >> 4);
    uint8_t secondnib = code[0] & 0x0f;
    uint8_t thirdnib = (code[1] >> 4);
    uint8_t fourthnib = (code[1] & 0x0f);

    printf("%04x %02x %02x ", programCounter, code[0], code[1]);

    switch (firstnib)
    {
        case 0x00:
        {
            switch(thirdnib)
            {
            case 0x0e:
            {
                switch(fourthnib)
                {
                    case 0x00:
                    {
                        printf("CLS");
                    }
                    break;
                    case 0x0e:
                    {
                        printf("RET");
                    }
                    break;
                }
            }
            break;
            default:
            {
                printf("%-10s 0x%02x 0x%02x", "DEPR", code[0], code[1]);
            }
            break;
            }
        }
        break;
        case 0x01:
        {
            printf("%-10s 0x0%01x%02x", "JMP", secondnib, code[1]);
        }
        break;
        case 0x02:
        {
            printf("%-10s #$%01x%02x", "CALL", secondnib, code[1]);
        }
        break;
        case 0x03:
        {
            printf("%-10s V%01x,0x%02x", "CMP", secondnib, code[1]);
        }
        break;
        case 0x04:
        {
            printf("%-10s V%01x,0x%02x", "CMPN", secondnib, code[1]);
        }
        break;
        case 0x05:
        {
            printf("%-10s V%01x,V%01x", "CMP", secondnib, thirdnib);
        }
        break;
        case 0x06:
        {
            printf("%-10s V%01X,0x%02x", "SET", secondnib, code[1]);
        }
        break;
        case 0x07:
        {
            printf("%-10s V%01X,0x%02x", "ADD", secondnib, code[1]);
        }
        break;
        case 0x08:
        {
            switch(fourthnib)
            {
                case 0x00:
                {
                    printf("%-10s V%01X,V%01x", "MOV", secondnib, thirdnib);
                }
                break;
                case 0x01:
                {
                    printf("%-10s V%01X,V%01x", "OR", secondnib, thirdnib);
                }
                break;
                case 0x02:
                {
                    printf("%-10s V%01X,V%01x", "AND", secondnib, thirdnib);
                }
                break;
                case 0x03:
                {
                    printf("%-10s V%01X,V%01x", "XOR", secondnib, thirdnib);
                }
                break;
                case 0x04:
                {
                    printf("%-10s V%01X,V%01x", "ADD", secondnib, thirdnib);
                }
                break;
                case 0x05:
                {
                    printf("%-10s V%01X,V%01x", "SUB", secondnib, thirdnib);
                }
                break;
                case 0x06:
                {
                    printf("%-10s V%01X,V%01x", "SHR", secondnib, thirdnib);
                }
                break;
                case 0x07:
                {
                    printf("%-10s V%01X,V%01x", "SUBN", secondnib, thirdnib);
                }
                break;
                case 0x0e:
                {
                    printf("%-10s V%01X,V%01x", "SHL", secondnib, thirdnib);
                }
                break;
                
            }
        }
        break;
        case 0x09:
        {
            printf("%-10s V%01X,V%01x", "SNE", secondnib, thirdnib);
        }
        break;
        case 0x0a:
        {
            printf("%-10s I,0x0%01x%02x", "SET", secondnib, code[1]);
        }
        break;
        case 0x0b:
        {
            printf("%-10s V%01X,0x0%01x%02x", "JP", 0, secondnib ,code[1]);
        }
        break;
        case 0x0c:
        {
            printf("%-10s V%01X,V%01x", "SHL", secondnib, thirdnib);
        }
        break;
        case 0x0d:
        {
            printf("%-10s V%01X,V%01x,%01x", "DRW", secondnib, thirdnib, fourthnib);
        }
        break;
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

    argc;

    int pc = 0x200;
    while (pc < (filesize+0x200))
    {
        disassembleRomChip8(buffer, pc);
        pc += 2;
        printf ("\n");
    }
    return 0;
}
