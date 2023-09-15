#include<stdio.h>
#include<math.h>

float f(float x)
{
    return log(cot(x));
}

int main()
{
    float x, allowedError;
    printf("Enter the allowed error: ");
    scanf("%f", &allowedError);
    printf("Enter the value of x: ");
    scanf("%f", &x);
    float value, temp;
    do
    {
        value = f(x);
        temp = x;
        printf("\nFor the value is %f and the f(x) is :%f", x, value);
        x = value;
    } while (fabs(value-temp)>allowedError);
    
    printf("\nThe value of x is:%f", x);
    printf("\nThe f(x) is :%f", f(x));
}