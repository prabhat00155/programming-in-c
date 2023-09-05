/* Program to convert hexadecimal digits (including an optional 0x or 0X)
 * into its equivalent integer value. Valid input characters are 0-9 and a-f
 * (or A-F).
 * Author: Prabhat Roy
 */

#include <stdio.h>

int hex_to_int(int);
int power(int, int);

int main()
{
    printf("%x (in hexadecimal) = %d (in decimal)\n", 0x12, hex_to_int(0x12));
    printf("%x (in hexadecimal) = %d (in decimal)\n", 0xf, hex_to_int(0xf));
    printf("%x (in hexadecimal) = %d (in decimal)\n", 23, hex_to_int(23));
    printf("%x (in hexadecimal) = %d (in decimal)\n", 0XF02A, hex_to_int(0XF02A));
    return 0;
}

int hex_to_int(int hex)
{
    int val, exponent;
    for (exponent = 0, val = 0; hex > 0; hex /= 16)
        val += power(16, exponent++) * (hex % 16);
    return val;
}

int power(int base, int exponent)
{
    int result = 1;
    while (exponent-- > 0)
        result *= base;
    return result;
}
