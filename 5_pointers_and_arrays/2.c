/* Program to implement a function strsuffix(s, t), which returns 1 if
 * the string t occurs at the end of string s, otherwise returns 0.
 * Author: Prabhat Roy
 */

#include <stdio.h>

int strsuffix(const char *, const char *);
int strlength(const char *);

int main()
{
    printf("strsuffix(%s, %s) = %d\n", "abcdef", "ef", strsuffix("abcdef", "ef"));
    printf("strsuffix(%s, %s) = %d\n", "abcdef", "lf", strsuffix("abcdef", "lf"));
    printf("strsuffix(%s, %s) = %d\n", "abcdef", "abcdef", strsuffix("abcdef", "abcdef"));
    printf("strsuffix(%s, %s) = %d\n", "abcdef", "f", strsuffix("abcdef", "f"));
    printf("strsuffix(%s, %s) = %d\n", "a", "f", strsuffix("a", "f"));
    printf("strsuffix(%s, %s) = %d\n", "", "abcf", strsuffix("", "abcf"));
    printf("strsuffix(%s, %s) = %d\n", "a", "a", strsuffix("a", "a"));
    printf("strsuffix(%s, %s) = %d\n", "", "", strsuffix("", ""));
    return 0;
}

int strsuffix(const char *s, const char *t)
{
    int slen = strlength(s), tlen = strlength(t);
    if (tlen > slen)
        return 0;
    /* Increment s pointer such that it has the same number of characters
     * to the end of string as t
     */
    s = s + slen - tlen;
    while (*s)
        if (*s++ != *t++)
            return 0;
    return 1;
}

int strlength(const char *s)
{
    int len = 0;
    while (*s++)
        len++;
    return len;
}
