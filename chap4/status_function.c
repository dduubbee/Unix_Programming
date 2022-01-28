/*
** #include    <sys/stat.h>
** #include    <time.h>
** 
** struct stat
** {
**     mode_t          st_mode;        //  file type & mode(permission)
**     ino_t           st_ino;         //  i-node number (serial number)
**     dev_t           st_dev;         //  device number (file system)
**     dev_t           st_rdev;        //  device number for special files
**     nlink_t         st_nlink;       //  number of links
**     uid_t           st_uid;         //  user ID of owner
**     gid_t           st_gid;            // group ID of owner
**     off_t           st_size;        //  size in bytes, for regular files
**     struct timespec st_atim;        // time of last access
**     struct timespec st_mtim;    //  time of last modification
**     struct timespec st_ctime;   //  time of last file status change
**     __blksize_t     st_blksize; // best I/O block size
**     __blkcnt_t      st_blocks;  // number of dist blocks allocated
** };
** 
** struct tm{
**     int tm_sec;
**     int tim_min;
**     int tm_hour;
**     int tm_mday;
**     int tm_mon;
**     int tm_year;
**     int tm_wday;
**     int tm_yday;
** 
**     int tm_isdat;
** };
** 
** struct timespec
** {
**     time_t  tv_sec;      // seconds
**     long    tv_nsec;     // nano seconds
** }
** 
** 
** 
** 
** int stat(const char *restrict pathname, struct stat *restrict buf);
** The stat function returns a structure of information about named file
** 
** int fstat(int fd, struct stat *buf)
** The stat function returns a structure of information about named file by fd
** 
** int lstat(const char *restrict pathname, struct stat *restrict buf);
** When pathname is for the symbolic link, lstat returns information about the symbolic link, not the file a directory hierarchy.
** 
** int fststat(int fd, const *restric pathname, struct stat *restrict buf, int flag);
** The fstat function provides a way to return the file statistics for a pathname controls whether symbolic links are followd.
** If AT_SYMLINK_NOFOLLOW is set, the function will not follow the symbolic link.
*/


