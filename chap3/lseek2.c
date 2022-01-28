#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define CREAT_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

char    buf1[]      =   "1234567890";
char    buf2[]      =   "ABCDEFGHIJ";

int
main()
{
    char* *fname    =   "ssu_hole.txt";
    int     fd;

    
}