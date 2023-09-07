/* Program which accepts two file names as command-line arguments and
 * prints the first line where they differ.
 * Author: Prabhat Roy
 */

#include <stdio.h>
#include <string.h>

#define MAXLEN 120

int main(int argc, char *argv[])
{
    FILE *fp1, *fp2;
    char line1[MAXLEN], line2[MAXLEN], *lp1, *lp2;
    int flag = 1;
    if (argc != 3) {
        printf("Incorrect number of command-line arguments passed (Require two file names)\n");
        return 1;
    }
    fp1 = fopen(argv[1], "r");
    if (!fp1) {
        printf("Can't open %s\n", argv[1]);
        return 1;
    }
    fp2 = fopen(argv[2], "r");
    if (!fp2) {
        fclose(fp1);
        printf("Can't open %s\n", argv[2]);
        return 1;
    }
    while (flag) {
        lp1 = fgets(line1, MAXLEN, fp1);
        lp2 = fgets(line2, MAXLEN, fp2);
        if (lp1 && lp2) {
            if (strncmp(lp1, lp2, MAXLEN)) {
                printf("%s\n%s\n", lp1, lp2);
                flag = 0;
            }
        } else if (lp1) {
            printf("%s\n", lp1);
            flag = 0;
        } else if (lp2) {
            printf("%s\n", lp2);
            flag = 0;
        } else {
            flag = 0;
        }
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}
