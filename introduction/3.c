/* Program to print power of 2 table, with powers ranging from 0 to 10. 
 * Author: Prabhat Roy
 */

#include <stdio.h>

int power(int , int);

int main()
{
    int i;
    for (i = 0; i <= 10; i++)
        printf("%d ^ %d = %d\n", 2, i, power(2, i));
    return 0;
}

int power(int base, int exponent)
{
    int result = 1;
    for (; exponent > 0; exponent--)
        result *= base;
    return result;
}
