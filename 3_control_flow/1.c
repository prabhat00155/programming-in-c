/* Program to implement a function that takes a string as an argument,
 * removes all blank spaces (tabs, spaces, newlines) from the string.
 * Author: Prabhat Roy
 */

#include <stdio.h>

void remove_spaces(char []);

int main()
{
    char str[] = " Hello \t world \n";
    /* () act as a boundary for the text */
    printf("Input text = (%s)\n", str);
    /* Remove spaces from the string in-place */
    remove_spaces(str);
    printf("Output text = (%s)\n", str);
    return 0;
}

void remove_spaces(char str[])
{
    int i = 0, j = 0;
    if (str == NULL)
        return;
    while (str[j] != '\0') {
        if (str[j] == ' ' || str[j] == '\t' || str[j] == '\n')
            j++;
        else
            str[i++] = str[j++];
    }
    str[i] = '\0';
}
