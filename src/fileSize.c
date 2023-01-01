#include "fileSize.h"
#include <stdio.h>

int findFileSize(char filename[]) {
    FILE *chkExist = fopen(filename, "r");
    if (chkExist == NULL) {
        printf("File Not Found!\n");
        return -1;
    }

    fseek(chkExist, 0L, SEEK_END);

    // calculating the size of the file
    long int res = ftell(chkExist);

    // closing the file
    fclose(chkExist);

    return res;
}