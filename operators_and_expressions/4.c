/* Program to implement a function squeeze(s1, s2), which deletes each
 * character in string s1 that matches any character in string s2.
 * You may assume that the input only contains lower case alphabets.
 * Author: Prabhat Roy
 */

#include <stdio.h>

void squeeze(char [], const char []);

int main()
{
    char str1[] = "helloworld";
    char str2[] = "lo";
    printf("squeeze(%s, %s) = ", str1, str2);
    squeeze(str1, str2);
    printf("%s\n", str1);
    return 0;
}

void squeeze(char str1[], const char str2[])
{
    int dict[26] = { 0 };
    int index, i = 0, j = 0;
    for (index = 0; str2[index] != '\0'; index++)
        /* Assumption: Only lower case alphabets present in str2 */
        dict[str2[index] - 'a']++;
    while (str1[j] != '\0') {
        if (dict[str1[j] - 'a'] > 0) {
            j++;
        }
        else {
            str1[i++] = str1[j++];
        }
    }
    str1[i] = '\0';
}

