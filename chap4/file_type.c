#include    <sys/stat.h>
#include    <stdio.h>
#include    <stdlib.h>

/*
** ------------------------------------------------------------
** |        MACRO           |           Type of file          |
** ------------------------------------------------------------
** | S_ISREG()              |           regular file          |
** ------------------------------------------------------------
** | S_ISDIR()              |          directory file         |
** ------------------------------------------------------------
** | S_ISCHR()              |     character special file      |
** ------------------------------------------------------------
** | S_ISBLK()              |      block special file         |
** ------------------------------------------------------------
** | S_ISFIFO()             |          pipe of fifo           |
** ------------------------------------------------------------
** | S_ISLNK()              |          symbolic link          |
** ------------------------------------------------------------
** | S_ISSOCK()             |              socket             |
** ------------------------------------------------------------
** 
**                  IPC type macros
** 
** ------------------------------------------------------------
** |        MACRO            |          Type of object         |
** ------------------------------------------------------------
** |    S_TYPEISMQ()         |      message queue              |
** ------------------------------------------------------------
** |    S_TYPEISSEM()        |      semaphore                  |
** ------------------------------------------------------------
** |    S_TYPEISSHM()        |      shared memory object       |
** ------------------------------------------------------------
** 
*/

int
main(int argc, char *argv[])
{
    int             i;
    struct stat     buf;
    char            *ptr;

    for(i = 1; i < argc; i++)
    {
        printf("%s : ", argv[i]);
        if(lstat(argv[i], &buf) < 0)
        {
            perror("lstat error");
            continue;
        }
        if(S_ISREG(buf.st_mode))
        {
            ptr = "regular";
        }else if(S_ISDIR(buf.st_mode))
            ptr = "directory";
        else if(S_ISCHR(buf.st_mode))
            ptr = "character special";
        else if(S_ISFIFO(buf.st_mode))
            ptr = "fifo";
    }
    exit(EXIT_SUCCESS);
}
