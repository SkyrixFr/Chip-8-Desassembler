#include "fileSize.h"
#include <stdio.h>

int findFileSize(char filename[]) {
    FILE* fp = fopen("octoachip8story.ch8", "r");
    if (fp == NULL) {
        printf("File Not Found!\n");
        return -1;
    }

    fseek(fp, 0L, SEEK_END);

    // calculating the size of the file
    long int res = ftell(fp);

    // closing the file
    fclose(fp);

    return res;
}