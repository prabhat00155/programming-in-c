/* Program to print a temperature table which maps temperature values of
 * 0 – 100 Celsius to Fahrenheit (with increments of 10 on the Celsius scale).
 * Author: Prabhat Roy
 */

#include <stdio.h>

float c_to_f(float);

int main()
{
    float temp;
    for (temp = 0; temp <= 100; temp += 10)
        printf("%fºC = %fºF\n", temp, c_to_f(temp));
    return 0;
}

float c_to_f(float celsius)
{
    return celsius * 180 / 100 + 32;
}
