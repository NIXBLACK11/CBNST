#include<stdio.h>
#include<math.h>

float f(float x)
{
    // return (x*x*x)-(5*x)+(1);
    // return log(x) - cos(x);
    return pow(x, 3) - 7*pow(x, 2) - 14*x - 6;
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
        x = (x0+x1)/2;
        value = f(x);
        printf("\nf(x0) = %f and f(x1) = %f", f(x0), f(x1));
        printf("\nFor range %f - %f the value is %f and the f(x) is :", x0, x1, x);
        printf("%f", value);
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
    } while (value>allowedError);
    
    printf("\nThe value of x is:%f", x);
    printf("\nThe absolute error is:%f", value);
}