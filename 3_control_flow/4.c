/* Program to implement a function stringrev, that reverses the passed string
 * in-place (changes the original string).
 * Author: Prabhat Roy
 */

#include <stdio.h>

void stringrev(char []);

int main()
{
    char str1[] = "hello";
    char str2[] = "C";
    char str3[] = "foo bar";
    printf("reverse of %s = ", str1);
    stringrev(str1);
    printf("%s\n", str1);
    printf("reverse of %s = ", str2);
    stringrev(str2);
    printf("%s\n", str2);
    printf("reverse of %s = ", str3);
    stringrev(str3);
    printf("%s\n", str3);
    return 0;
}

void stringrev(char str[])
{
    int i = 0, j = 0;
    char tmp;
    while (str[j++] != '\0');
    /* We need j to index the last character (before '\0') */
    j -= 2;
    while (i < j) {
        tmp = str[j];
        str[j] = str[i];
        str[i] = tmp;
        i++;
        j--;
    }
}
