#include <stdio.h>

int main()
{
    float x = 1.0, y = 1.0, z = 1.0;
    float u = 4*(x*x)*(y*y*y)/(z*z*z*z);
    float dU = ((8*x*x*x/(z*z*z*z))*0.001) + ((12*x*x*y*y/(z*z*z*z))*0.001) + ((16*x*x*y*y*y/(z*z*z*z*z))*0.001);

    float relativeError = dU/u;
    printf("\nTrue Value:%f", u);
    printf("\nError:%f", dU);
    printf("\nRelative error:%f", relativeError);
}