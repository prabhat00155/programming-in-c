/* Program to implement a function concat, which concatenates two strings.
 * The function takes two string arguments and the first argument will have
 * the resulting string.
 * Author: Prabhat Roy
 */

#include <stdio.h>

void concat(char [], const char []);

int main()
{
    char str1[30] = "hello ";
    char str2[] = "world";
    printf("Concatenation of '%s' and '%s' = ", str1, str2);
    concat(str1, str2);
    printf("'%s'\n", str1);
    return 0;
}

void concat(char str1[], const char str2[])
{
    int index1, index2;
    for (index1 = 0; str1[index1] != '\0'; index1++);
    for (index2 = 0; str2[index2] != '\0'; index2++, index1++)
        str1[index1] = str2[index2];
    str1[index1] = '\0';
}
