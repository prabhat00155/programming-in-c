/* Program to implement a function that counts the number of non-zero
 * bits in a given non-negative integer.
 * Author: Prabhat Roy
 */

#include <stdio.h>

unsigned int count_bits(unsigned int);

int main()
{
    printf("Non-zero bits in %u = %u\n", 0, count_bits(0));
    printf("Non-zero bits in %u = %u\n", 1, count_bits(1));
    printf("Non-zero bits in %u = %u\n", 23, count_bits(23));
    printf("Non-zero bits in %u = %u\n", 7, count_bits(7));
    printf("Non-zero bits in %u = %u\n", 100, count_bits(100));
    return 0;
}

unsigned int count_bits(unsigned int n)
{
    int count = 0;
    for (; n > 0; n >>= 1)
        count += n & 1;
    return count;
}
