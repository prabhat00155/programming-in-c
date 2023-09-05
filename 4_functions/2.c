/* Program to implement a function atof(s), that converts string s to its
 * equivalent floating point value and returns the float. The function
 * should be able to handle scientific notations
 * (numbers containing e or E) like 123.5e-7. 
 * Author: Prabhat Roy
 */

#include <stdio.h>

float atof(char []);
float power(float, int);

int main()
{
    printf("atof(%s) = %f\n", "12", atof("12"));
    printf("atof(%s) = %f\n", "-12.03", atof("-12.03"));
    printf("atof(%s) = %f\n", "12.5e-4", atof("12.5e-4"));
    printf("atof(%s) = %f\n", "0.0", atof("0.0"));
    printf("atof(%s) = %f\n", "-1E3", atof("-1E3"));
    return 0;
}

float atof(char str[])
{
    int mult = 1, index = 0, decimal = 0, has_decimal = 0, e_val = 0, found_e = 0, e_mult = 1;
    float value = 0;
    if (str[0] == '-')
        mult = -1;
    if (str[0] == '-' || str[0] == '+')
        index = 1;
    for (; str[index]; index++) {
        if (str[index] >= '0' && str[index] <= '9') {
            if (!found_e) {
                value = value * 10 + str[index] - '0';
                if (has_decimal)
                    decimal++;
            }
            else
                e_val = e_val * 10 + str[index] - '0';
        }
        else if (str[index] == '.' && !has_decimal)
            has_decimal = 1;
        else if (!found_e && (str[index] == 'e' || str[index] == 'E')) {
            found_e = 1;
            if (str[index + 1] == '-')
                e_mult = -1;
            if (str[index + 1] == '-' || str[index + 1] == '+')
                index++;
        } else {
            printf("Invalid input!");
            return -1;
        }
    }
    return mult * value * power(10, -1 * decimal) * power(10, e_mult * e_val); 
}

float power(float base, int exponent)
{
    float value = 1;
    if (exponent < 0) {
        exponent *= -1;
        base = 1 / base;
    }
    for (; exponent > 0; exponent--)
        value *= base;
    return value;
}
