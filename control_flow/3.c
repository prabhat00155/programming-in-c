/* Program to implement a function stringlen, that returns the length of
 * the string passed to it.
 * Author: Prabhat Roy
 */

#include <stdio.h>

int stringlen(char []);

int main()
{
    printf("length of %s = %d\n", "hello", stringlen("hello"));
    printf("length of %s = %d\n", "123", stringlen("123"));
    printf("length of %s = %d\n", "", stringlen(""));
    printf("length of %s = %d\n", "foo bar", stringlen("foo bar"));
    printf("length of %s = %d\n", "C", stringlen("C"));
    return 0;
}

int stringlen(char str[])
{
    int i = 0;
    while (str[i++] != '\0');
    return i - 1;
}
