/* Program to display the filenames in the input directory.
 * Author: Prabhat Roy
 */

#include <stdio.h>
#include <dirent.h>

#define BUFSIZE 1024

int main(int argc, char *argv[])
{
    DIR *dp;
    struct dirent *entry;

    if (argc != 2) {
        printf("Incorrect number of command-line arguments (Need a directory path).\n");
        return 1;
    }

    dp = opendir(argv[1]);
    if (!dp) {
        printf("Error opening directory: %s\n", argv[1]);
        return 1;
    }
    while ((entry = readdir(dp)))
        printf("%s\n", entry->d_name);
    closedir(dp);

    return 0;
}
