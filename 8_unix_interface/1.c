/* Program to concatenate two files and give the output as the third file.
 * All the three file names must be taken as command-line arguments.
 * Author: Prabhat Roy
 */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#define BUFSIZE 1024

int main(int argc, char *argv[])
{
    int ifd1, ifd2, ofd;
    ssize_t nbytes;
    char buffer[BUFSIZE];

    if (argc != 4) {
        printf("Incorrect number of command-line arguments (Need three filenames).\n");
        return 1;
    }

    ifd1 = open(argv[1], O_RDONLY, 0);
    if (ifd1 == -1) {
        printf("Error opening %s\n", argv[1]);
        return 1;
    }
    ifd2 = open(argv[2], O_RDONLY, 0);
    if (ifd2 == -1) {
        printf("Error opening %s\n", argv[2]);
        close(ifd1);
        return 1;
    }
    ofd = creat(argv[3], 0755);
    if (ofd == -1) {
        printf("Error opening %s\n", argv[3]);
        close(ifd1);
        close(ifd2);
        return 1;
    }
    while ((nbytes = read(ifd1, buffer, BUFSIZE)) > 0)
        write(ofd, buffer, nbytes);
    while ((nbytes = read(ifd2, buffer, BUFSIZE)) > 0)
        write(ofd, buffer, nbytes);

    close(ifd1);
    close(ifd2);
    close(ofd);
    return 0;
}
