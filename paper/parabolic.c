#include <stdio.h>

int main() {
    int n, i, x[20], y[20];
    double sumx = 0, sumy = 0, sumx2 = 0, sumx3 = 0, sumx4 = 0, sumxy = 0, sumx2y = 0;

    printf("\n   C program for Parabolic Curve Fitting \n ");
    printf("\n Enter the value of number of terms n: ");
    scanf("%d", &n);
    
    printf("\n Enter the values of x:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }

    printf("\n Enter the values of y:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &y[i]);
    }

    for (i = 0; i < n; i++) {
        double x2 = x[i] * x[i];
        double x3 = x2 * x[i];
        double x4 = x2 * x2;

        sumx += x[i];
        sumx2 += x2;
        sumx3 += x3;
        sumx4 += x4;
        sumy += y[i];
        sumxy += x[i] * y[i];
        sumx2y += x2 * y[i];
    }

    double denominator = n * sumx2 * sumx4 - sumx2 * sumx2 * sumx2 - sumx * sumx * sumx4 + 2 * sumx * sumx2 * sumx3 - n * sumx4 * sumx;
    double a = (sumx2y * sumx2 * sumx - sumxy * sumx2 * sumx2 - sumx3 * sumx * sumx4 + sumxy * sumx4 * sumx + sumx3 * sumx2 * sumx) / denominator;
    double b = (n * sumx2y * sumx4 - sumx2 * sumx2y * sumx2 - sumx * sumx3 * sumx4 + sumx2 * sumx3 * sumx2 + sumx * sumx2 * sumxy - n * sumx2 * sumxy) / denominator;
    double c = (n * sumx2 * sumx2y - sumx * sumx2 * sumx2y - sumx2 * sumx3 * sumxy + sumx * sumx3 * sumx2 - sumx * sumx * sumx2y + sumx2 * sumx * sumxy) / denominator;

    printf("\nThe curve is Y = %3.3fX^2 + %3.3fX + %3.3f\n", a, b, c);

    return 0;
}