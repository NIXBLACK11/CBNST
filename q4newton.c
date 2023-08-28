#include<stdio.h>
#include<math.h>

float f(float x)
{
    return (x*x*x)-(5*x)+(1);
    // return (x*x*x)-(x)-1;
}

float df(float x)
{
    return (3*x*x)-(5);
}

int main()
{
    float x0, x1;
    do
    {
        printf("Enter the value of x1, x2:");
        scanf("%f %f", &x0, &x1);
    } while ((f(x0)*f(x1)>0));
    
    float allowedError, temp;
    printf("\nEnter the allowed error:");
    scanf("%f", &allowedError);

    float x = (x1+x0)/2;

    float value;
    do
    {
        value = x - (f(x)/df(x));
        temp = x;
        printf("\nFor the value is %f and the f(x) is :%f", x, value);
        x = value;
    } while (fabs(value-temp)>allowedError);
    
    printf("\nThe value of x is:%f", x);
    printf("\nThe absolute error is:%f", value);
}