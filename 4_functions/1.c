/* Program to implement a function strrindex(s, t), which returns the position
 * of rightmost occurrence of string t in string s, or -1 if there is none. 
 * Author: Prabhat Roy
 */

#include <stdio.h>

int strrindex(char [], char []);
int stringlen(char []);

int main()
{
    printf("strrindex(%s, %s) = %d\n", "hello world", "orl", strrindex("hello world", "orl"));
    printf("strrindex(%s, %s) = %d\n", "hello world", "lo", strrindex("hello world", "lo"));
    printf("strrindex(%s, %s) = %d\n", "hello world", "olo", strrindex("hello world", "olo"));
    printf("strrindex(%s, %s) = %d\n", "foooooo ooo", "o", strrindex("foooooo ooo", "oooo"));
    return 0;
}

int strrindex(char s[], char t[])
{
    int i, j;
    i = stringlen(s) - 1;
    j = stringlen(t) - 1;
    while (i >= 0) {
        if (s[i] == t[j]) {
            i--;
            j--;
            if (j < 0)
                return i + 1;
        }
        else if (j != stringlen(t) - 1) {
            j = stringlen(t) - 1;
        } else {
            i--;
        }
    }
    return -1;
}

int stringlen(char str[])
{
    int i = 0;
    while (str[i++]);
    return i - 1;
}
