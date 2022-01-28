#include    <sys/types.h>
#include    <sys/stat.h>
#include    <fcntl.h>
#include    <string.h>
#include    <stdio.h>
#include    <unistd.h>
#include    <stdlib.h>

/*
** Authority
** rwx(4, 2, 1) :  read, write, execution
** owner - group - the other user
** 
*/

int
main(int argc, char **argv)
{
    int     fd  =   0;
    if(argc != 2)
    {
        printf("Usage %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    fd  =   open(argv[1], O_WRONLY)
}