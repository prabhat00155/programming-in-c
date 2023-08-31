/* Program to convert a string containing digits to integer.
 * Author: Prabhat Roy
 */

#include <stdio.h>

int atoi(const char []);

int main()
{
    printf("%s = %d\n", "123", atoi("123"));
    printf("%s = %d\n", "-123", atoi("-123"));
    printf("%s = %d\n", "0", atoi("0"));
    printf("%s = %d\n", "+230", atoi("+230"));
    return 0;
}

int atoi(const char string[])
{
    int value, multiplier = 1, index = 0;
    if (string[0] == '-')
        multiplier = -1;
    if (string[0] == '-' || string[0] == '+')
        index = 1;
    for (value = 0; string[index] != '\0'; index++) {
        if (string[index] < '0' || string[index] > '9') {
            printf("Invalid string! String should be a valid integer.\n");
            return 0;
        }
        value = value * 10 + string[index] - '0';
    }
    return value * multiplier;
}
