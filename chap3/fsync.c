#include    <sys/types.h>
#include    <sys/stat.h>
#include    <fcntl.h>
#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>
#include    <unistd.h>

/*
** int fsync(int fd);
** recording the log on file
** 
** int fdatasync(int fd);
** recording data on the file
*/



int
main(void)
{
    int     fd  =   open("TEXT", O_RDWR | O_CREAT, 0666);
    if(fd == -1)
    {
        perror("Failed to open file.\n");
        exit(EXIT_FAILURE);
    }

    // fsync()
    int ret     =   fsync(fd);
    if(ret == -1)
    {
        perror("Failed fsync().\n");
        exit(EXIT_FAILURE);
    }else{
        printf("Successed fsync()!\n");
    }

    // fdatasync()
    ret     =   fdatasync(fd);
    if(ret == -1)
    {
        perror("Failed fdatasync().\n");
        exit(EXIT_FAILURE);
    }else{
        printf("Successed fdatasync()!\n");
    }
    close(fd);
    exit(EXIT_SUCCESS);
}