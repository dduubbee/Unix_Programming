#include    <stdio.h>
#include    <stdlib.h>
#include    <fcntl.h>
#include    <unistd.h>
#include    <string.h>
#include    <sys/types.h>

/*
** int fcntl(int fd, int cmd, ... int args)
**
** The fcntl function can change the properties of a file that is already open
** Returns : depends on cmd if OK(see following), -1 on error
** 
** cmd :
**         F_DUPFD             :   Duplicate an existing descriptor
**         F_DUPFD_CLOEXEC     :   Duplicate an exsiting descriptor and set the close-on-exec that bans F_SETFD operation
**         F_GETFD             :   Return the file descriptor flags fo fd as the value of the function
**         F_SETFD             :   Set the file descriptor flags for fd. THe new flag value is set from the third argument(taken as an integer)
**         F_GETFL             :   Return the file status flags for fd as the vluae of the fucntion.
**         F_SETFL             :   Set the file status flags to the value of thee third argument
**         F_GETOWN            :   Get the process ID or process group ID currently receiving SIGIO and SIGURG signals
**         F_SETOWN            :   Wet the process ID or process group ID to receive the SIGIO and SIGURG signals.
** 
** 
** the cmd whose return is fd :
**         F_DUPFD             :   returns new file descriptor
**         F_GETFD             :   returns corresponding flags
**         F_GETFL             :   returns corresponding flags
**         F_GETOWN            :   returns corresponding ID
*/


int
main(int argc, char *argv[]))
{
    int     vals;

    if(argc != 2)
    {
        perror("usage : a.out <descripotr #>");
        exit(EXIT_FAILURE);
    }

    if((vals = fcntl(atoi(argv[1]), F_GETFL, 0)) < 0)
    {
        perror("fcntl error for fd\n");
        exit(EXIT_FAILURE);
    }

    switch(vals & O_ACCMODE)
    {
        case O_RDONLY :
            printf("read only\n");
            break;
        case O_WRONLY :
            printf("write only\n");
            break;
        case O_RDWR :
            printf("read wrtie\n");
            break;
        default :
            perror("error dump\n");
            exit(EXIT_FAILURE);
    }
    if(vals & O_APPEND)
    {
        printf(", append");
    }
    if(vals & O_NONBLOCK)
    {
        printf(", nonblocking");
    }
    if(vals & O_SYNC)
    {
        printf(", synchronous writes");
    }
    exit(EXIT_SUCCESS);

}