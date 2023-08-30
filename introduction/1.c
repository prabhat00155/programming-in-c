/* Program to capitalise all the letters in the input.
 * Author: Prabhat Roy
 */

#include <stdio.h>

int main()
{
    int ch;
    while ((ch = getchar()) != EOF) {
        if (ch >= 'a' && ch <= 'z')
            ch -= 32;
        putchar(ch);
    }
    return 0;
}
