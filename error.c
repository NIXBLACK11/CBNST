#include<stdio.h>

int main()
{
    float trueValue = 0;
    float approximateValue = 0;
    printf("\nEnter the approximate value:");
    scanf("%f", &approximateValue);
    trueValue = 1.0/3.0;
    printf("\nTrue Value: %f", trueValue);
    float absoluteError = trueValue-approximateValue;
    if(absoluteError<0)
        absoluteError = -absoluteError;
    printf("\nAbsolute error:%f", absoluteError);
    float relativeError = absoluteError/trueValue;
    printf("\nRelative error:%f", relativeError);
    float percentageError = relativeError*100;
    printf("\nPercentage error:%f", percentageError);
    return 0;
}