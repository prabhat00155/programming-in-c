/* Program to define a macro swap(t, x, y) that interchanges
 * two argument x and y, of type t.
 * Author: Prabhat Roy
 */

#include <stdio.h>

#define swap(t, x, y) { t tmp = x; x = y; y = tmp; }

int main()
{
    int a = 10;
    int b = 20;
    int m = 0;
    int n = 2;
    float x = 1.09;
    float y = -90e-1;

    printf("a = %d, b = %d\n", a, b);
    swap(int, a, b);
    printf("After swap: a = %d, b = %d\n", a, b);

    printf("m = %d, n = %d\n", m, n);
    swap(int, m, n);
    printf("After swap: m = %d, n = %d\n", m, n);

    printf("x = %f, y = %f\n", x, y);
    swap(float, x, y);
    printf("After swap: x = %f, y = %f\n", x, y);

    return 0;
}
