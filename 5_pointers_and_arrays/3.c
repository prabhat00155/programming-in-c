/* Program to implement a function  strncompare(s, t, n) to compare up to n
 * characters of strings s and t. If the two strings match, it returns
 * 0. Otherwise, if the first mismatched character has lower value in
 * s, then it returns -1, else 1.
 */

#include <stdio.h>

int strncompare(const char *, const char *, int);

int main()
{
    printf("%s == %s (3) = %d\n", "hello", "world", strncompare("hello", "world", 3));
    printf("%s == %s (2) = %d\n", "", "", strncompare("", "", 2));
    printf("%s == %s (3) = %d\n", "", "world", strncompare("", "world", 3));
    printf("%s == %s (4) = %d\n", "hello", "", strncompare("hello", "", 4));
    printf("%s == %s (5) = %d\n", "hello", "hello", strncompare("hello", "hello", 5));
    printf("%s == %s (10) = %d\n", "hello", "hello world", strncompare("hello", "hello world", 10));
    printf("%s == %s (1) = %d\n", "whello", "world", strncompare("whello", "world", 1));
    return 0;
}

int strncompare(const char *s, const char *t, int n)
{
    int index;
    for (index = 0; index < n && *s && *t; index++, s++, t++) {
        if (*s < *t)
            return -1;
        if (*s > *t)
            return 1;
    }
    if (index < n && *s)
        return 1;
    if (index < n && *t)
        return -1;
    return 0;
}
