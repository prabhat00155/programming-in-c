/* Program to input multiple lines of text and sort them in
 * lexicographical order.
 * Author: Prabhat Roy
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXCHARS 128
#define MAXLINES 32

int readline(char *, int);
void sort(char * [], int);

int main()
{
    int i, curlen, j;
    char buffer[MAXCHARS];
    char *lines[MAXLINES];
    for (i = 0; i < MAXLINES; i++) {
        curlen = readline(buffer, MAXCHARS);
        if (curlen == 0)
            break;
        lines[i] = (char *) malloc((curlen + 1) * sizeof(char));
        strcpy(lines[i], buffer);
    }
    sort(lines, i);
    printf("Lexicographically sorted input:\n");
    for (j = 0; j < i; j++) {
        printf("%s\n", lines[j]);
        free(lines[j]);
    }
    return 0;
}

int readline(char *line, int max)
{
    int ch, len = 0;
    while (len < max - 1 && (ch = getchar()) != '\n' && ch != EOF) {
        line[len++] = ch;
    }
    line[len] = '\0';
    return len;
}

void sort(char *lines[], int n)
{
    int i, j, min;
    char *tmp;
    for (i = 0; i < n - 1; i++) {
        for (min = i, j = i + 1; j < n; j++)
            /* strcmp returns -1 if first arg < second arg */
            if (strcmp(lines[j], lines[min]) < 0)
                min = j;
        tmp = lines[i];
        lines[i] = lines[min];
        lines[min] = tmp;
    }
}
