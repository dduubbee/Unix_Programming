#include    <fcntl.h>
#include    <unistd.h>
#include    <stdio.h>
#include    <stdlib.h>

/*
**     ---------------------------------------
**     | mode   |        Descript            |
**     ---------------------------------------
**     | R_OK   | test for read permission   |
**     ---------------------------------------
**     | W_OK   | test for write permission  |
**     ---------------------------------------
**     | X_OK   | test for execute permission|
**     ---------------------------------------
** 
**     int access(const char *pathname, int mode);
** 
**     int faccessat(int fd, const char *pathname, int mode, int flag);
*/



/*
** int access(const char *pathname, int mode);
** 
** int faccessat(int fd, const char *pathnmae, int mode, int flag);
*/

int
main(int argc, char *argv[])
{
    int fd;
    if (argc != 2)
    {
        perror("usage : a.out <pathname>");
        exit(EXIT_FAILURE);
    }
    if (access(argv[1], R_OK) < 0)
    {
        perror("access error");
        exit(EXIT_FAILURE);
    }else{
        printf("read access OK\n");
    }

    if((fd = open(argv[1], O_RDONLY)) < 0)
    {
        perror("Open error");
        exit(EXIT_FAILURE);
    }else{
        printf("Open for reading OK\n");
    }

    close(fd);
    exit(EXIT_SUCCESS);

}