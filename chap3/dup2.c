#include    <unistd.h>
#include    <stdio.h>
#include    <stdlib.h>
#include    <sys/stat.h>
#include    <string.h>
#include    <fcntl.h>

int
main(void)
{
    int fd1, ret;

    char message[32]    =   "STDERR from fd1\n");

    if(fd1 < 0)
    {
        printf("file open error\n");
        exit(EXIT_FAILURE);
    }

    printf("file open\n");

    ret =   dup2(fd1, STDOUT_FILENO);

    print("fd1 : %d, ret : %d\n", fd1, ret);

    ret     =   dup2(STDERR_FILENO, fd1);

    write(fd1, message, strlen(message));

    close(fd1);
}