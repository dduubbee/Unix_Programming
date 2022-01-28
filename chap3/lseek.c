
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

/**************************************************
 * OFF_T LSEEK(INT FD, OFF_T OFFSET, INT WHENCE); *
 *                   INT WHENCE                   *
 *        SEEK_SET    :   FRONT OF THE FILE        *
 *        SEEK_CUR    :   CURRENT LOCATION        *
 *        SEEK_END    :   END OF THE FILE         *
 **************************************************/

int main() {
	char *fname = "ssu_test.txt";
	int fd;
	off_t fsize;

	if ((fd = open(fname, O_RDONLY)) < 0) {
		fprintf(stderr, "open error for %s\n", fname);
		exit(1);
	}

	// SEEK_END(파일의 끝) 의 seek position 은 파일 size 와 같다.
	if ((fsize = lseek(fd, 0, SEEK_END)) < 0) {
		fprintf(stderr, "lseek error\n");
		exit(1);
	}

	printf("The size of <%s> is %ld bytes.\n", fname, fsize);
	exit(0);
}