/* Program to remove all comments from a C program.
 * Author: Prabhat Roy
 */

#include <stdio.h>

int main()
{
    int cur, prev = -1, inside_comment = 0;
    while ((cur = getchar()) != EOF) {
        if (prev == '/') {
            if (cur == '*') {
                inside_comment = 1;
            } else if (cur == '/') {
                putchar(prev);
                prev = cur;
                continue;
            } else {
                putchar(prev);
            }
        }
        if (!inside_comment && cur != '/')
            putchar(cur);
        if (inside_comment && prev == '*' && cur == '/') {
            cur = -1;
            inside_comment = 0;
        }
        prev = cur;
    }
    return 0;
}
