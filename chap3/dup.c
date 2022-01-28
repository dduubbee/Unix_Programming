#include    <unistd.h>
#include    <stdio.h>
#include    <stdlib.h>
#include    <sys/stat.h>
#include    <string.h>
#include    <fcntl.h>

/*
** int open(const char* pathname, int flags, [mode_t mode]);
** 
**     flags :
**             O_RDONLY    :   read-only
**             O_WRONLY    :   write-only
**             O_RDWR      :   read-write
**             O_CREAT     :   creating file
**             O_APPEND    :   opening file and set the file pointer at the end of file
**             O_TRUNC     :   opening file and set the file pointer in front of the file
** 
**     mod   :
**             S_IRWXU     :   0700
**             S_IRUSR     :   0400
**             S_IWUSR     :   0200
**             S_IXUSR     :   0100
** 
**             S_IRWXG     :   0070
**             S_IRGRP     :   0040
**             S_IWGRP     :   0020
**             S_IXUSR     :   0010
** 
**             S_IRWSO     :   0007
**             S_IROTH     :   0004
**             S_IWOTH     :   0002
**             S_IXOTH     :   0001
*/

/*
** int dup(int fd);
** : return the lowest availiable number of file descriptor
** 
** int dup2(int fd, int fd2);
** : if fd2 is already open, it is firset closed.
** : if fd == fd2 then return fd2 witout closing
** :
*/







int
main(void)
{
    int fd1, fd2;
    char message[32]    =   {"mesasage via fd2\n"};

    fd1     =   open("made_by_fd1", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);

    if(fd1 < 0)
    {
        printf("file open error\n");
        exit(EXIT_FAILURE);
    }

    fd2     =   dup(fd1);

    write(fd2, message, strlen(message));
    printf("fd1 : %d, fd2 : %d\n", fd1, fd2);

    close(fd1);
    close(fd2);
}