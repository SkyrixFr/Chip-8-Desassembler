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
                        printf("%-25s %s", "CLS", "Clears screen");
                    }
                    break;
                    case 0x0e:
                    {
                        printf("%-25s %s", "RET", "Return from a subroutine");
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
            printf("%-10s 0x0%01x%02x %-8s%s%01x%02x", "JMP", secondnib, code[1], "", "Jump to memory location 0x0", secondnib, code[1]);
        }
        break;
        case 0x02:
        {
            printf("%-10s 0x0%01x%02x %-8s%s%01x%02x", "CALL", secondnib, code[1], "", "Call subroutine at address 0x0", secondnib, code[1]);
        }
        break;
        case 0x03:
        {
            printf("%-10s V%01x,0x%02x %-7s%s%01x %s%02x", "CMP", secondnib, code[1], "", "Skip next instruction if V", secondnib, "is equal to 0x", code[1]);
        }
        break;
        case 0x04:
        {
            printf("%-10s V%01x,0x%02x %-7s%s%01x %s%02x", "CMPN", secondnib, code[1], "", "Skip next instruction if V", secondnib, "is not equal to 0x", code[1]);
        }
        break;
        case 0x05:
        {
            printf("%-10s V%01x,V%01x %-7s%s%01x %s%01x", "CMP", secondnib, thirdnib, "", "Skip next instruction if V", secondnib, "is equal to V", thirdnib);
        }
        break;
        case 0x06:
        {
            printf("%-10s V%01X,0x%02x %-7s%s%01x %s%02x", "SET", secondnib, code[1], "", "Set V", secondnib, "to 0x", code[1]);
        }
        break;
        case 0x07:
        {
            printf("%-10s V%01X,0x%02x %-7s%s%01x %s%01x %s%02x", "ADD", secondnib, code[1], "", "Set V", secondnib, "= V", secondnib, "+ 0x", code[1]);
        }
        break;
        case 0x08:
        {
            switch(fourthnib)
            {
                case 0x00:
                {
                    printf("%-10s V%01X,V%01x %-9s%s%01x %s%01x", "SET", secondnib, thirdnib, "", "Set V", secondnib, "= V", thirdnib);
                }
                break;
                case 0x01:
                {
                    printf("%-10s V%01X,V%01x %-9s%s%01x %s%01x", "OR", secondnib, thirdnib, "", "Performes a bitwise OR on V", secondnib, "and V", thirdnib);
                }
                break;
                case 0x02:
                {
                    printf("%-10s V%01X,V%01x %-9s%s%01x %s%01x", "AND", secondnib, thirdnib, "", "Performes a bitwise AND on V", secondnib, "and V", thirdnib);
                }
                break;
                case 0x03:
                {
                    printf("%-10s V%01X,V%01x %-9s%s%01x %s%01x", "XOR", secondnib, thirdnib, "", "Performes a bitwise XOR on V", secondnib, "and V", thirdnib);
                }
                break;
                case 0x04:
                {
                    printf("%-10s V%01X,V%01x %-9s%s%01x %s%01x %s%01x %s", "ADD", secondnib, thirdnib, "", "V", secondnib, "= V", secondnib, "+ V", thirdnib, "and puts the carry in VF");
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
        case 0x0e:
        {
            switch(thirdnib)
            {
                case 0x09:
                {
                    printf("%-10s V%01X", "SKP", secondnib);
                }
                break;
                case 0x0a:
                {
                    printf("%-10s V%01X", "SKNP", secondnib);
                }
                break;
            }
        }
        break;
        case 0x0f:
        {
            switch(thirdnib)
            {
                case 0x00:
                {
                    switch(fourthnib)
                    {
                        case 0x07:
                        {
                            printf("%-10s V%01X,DT", "LD", secondnib);
                        }
                        break;
                        case 0x0a:
                        {
                            printf("%-10s V%01X,K", "LD", secondnib);
                        }
                        break;
                    }
                }
                break;
                case 0x01:
                {
                    switch(fourthnib)
                    {
                        case 0x05:
                        {
                            printf("%-10s DT,V%01X", "LD", secondnib);
                        }
                        break;
                        case 0x08:
                        {
                            printf("%-10s ST,V%01X", "LD", secondnib);
                        }
                        break;
                        case 0x0e:
                        {
                            printf("%-10s I,V%01X", "ADD", secondnib);
                        }
                        break;
                    }
                }
                break;
                case 0x02:
                {
                    printf("%-10s F,V%01X", "LD", secondnib);
                }
                break;
                case 0x03:
                {
                    printf("%-10s B,V%01X", "LD", secondnib);
                }
                break;
                case 0x05:
                {
                    printf("%-10s [I],V%01X", "LD", secondnib);
                }
                break;
                case 0x06:
                {
                    printf("%-10s V%01X,[I]", "LD", secondnib);
                }
                break;
            }
        }
        break;
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
