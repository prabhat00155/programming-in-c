/* Program to remove trailing spaces from each line and to delete blank lines completely.
 * Author: Prabhat Roy
 */

#include <stdio.h>

int main()
{
    int ch, space_count = 0, char_count = 0;
    while ((ch = getchar()) != EOF) {
        if (ch == '\n') {
            if (char_count > 0)
                putchar(ch);
            char_count = 0;
            space_count = 0;
        } else if (ch == ' ') {
            space_count++;
        } else {
            while (space_count-- > 0)
                putchar(' ');
            space_count = 0;
            putchar(ch);
            char_count++;
        }
    }
}
