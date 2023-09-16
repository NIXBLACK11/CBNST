#include<stdio.h>
#include<math.h>

float f(float x)
{
    // return sqrt((sin(x)*sin(x))+1);
    return sqrt((((x+1)*(x+1))+sin(x))/sin(x));
}
float df(float x)
{
    // return -2/sin(2*x);
    // return sin(2*x)/2*(pow((sin(x)*sin(x))-1, (1/2)));
}

int main()
{
    for (int i = 1; i < 100; i++)
    {
        printf("%d, ", i);
        if(fabs(df(i))<1)
        {
            printf("\nPossible at : %d", i);
            break;
        }
    }
    
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