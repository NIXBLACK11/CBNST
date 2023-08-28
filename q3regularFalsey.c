#include<stdio.h>

float f(float x)
{
    return (x*x*x)-(5*x)+(1);
    // return (x*x*x)-(x)-1;
}

int main()
{
    float x0, x1;
    do
    {
        printf("Enter the value of x1, x2:");
        scanf("%f %f", &x0, &x1);
    } while ((f(x0)*f(x1)>0));
    
    float allowedError;
    printf("\nEnter the allowed error:");
    scanf("%f", &allowedError);

    float value, x;
    do
    {
        x = x0-(((x1-x0)/(f(x1)-f(x0)))*f(x0));
        value = f(x);
        printf("\nFor range %f - %f the value is %f and the f(x) is :", x0, x1, x);
        if(value>0)
        {
            x1 = x;
        }
        else
        {
            x0 = x;
        }
        if(value<0)
            value = -value;
        printf("%f", value);
    } while (value>allowedError);
    
    printf("\nThe value of x is:%f", x);
    printf("\nThe absolute error is:%f", value);
}