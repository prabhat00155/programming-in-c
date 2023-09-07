/* Program to implement a function strconcat(s, t), that appends string t to
 * the end of string s.
 * Author: Prabhat Roy
 */

#include <stdio.h>

void strconcat(char *, const char *);

int main()
{
    char s[32] = "Hello ";
    printf("strconcat(%s, %s) = ", s, "world");
    strconcat(s, "world");
    printf("%s\n", s);
    return 0;
}

void strconcat(char *s, const char *t)
{
    /* Get to the end of string s */
    while (*s++);
    /* Decrement s in order to override the \0 at the end */
    s--;
    /* Copy all the character to t to s including the \0 at the end */
    while ((*s++ = *t++));
}
