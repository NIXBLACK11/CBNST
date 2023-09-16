#include <stdio.h>
#include <math.h>

#define MAX_ITER 100
#define EPSILON 1e-6

int main() {
    int n;
    printf("Enter the number of equations: ");
    scanf("%d", &n);

    double A[n][n];
    double b[n];

    printf("Enter the coefficients of the equations:\n");
    for (int i = 0; i < n; i++) {
        printf("Equation %d coefficients (space-separated): ", i + 1);
        for (int j = 0; j < n; j++) {
            scanf("%lf", &A[i][j]);
        }
        printf("Enter the constant term (b%d): ", i + 1);
        scanf("%lf", &b[i]);
    }

    double x[n]; // Initialize solution vector
    for (int i = 0; i < n; i++) {
        x[i] = 0.0; // You can initialize with other values as well
    }

    int iter = 0;
    double maxDiff;

    do {
        maxDiff = 0.0;
        for (int i = 0; i < n; i++) {
            double oldX = x[i];
            double sum = 0.0;
            for (int j = 0; j < n; j++) {
                if (j != i) {
                    sum += A[i][j] * x[j];
                }
            }
            x[i] = (b[i] - sum) / A[i][i];
            double diff = fabs(x[i] - oldX);
            if (diff > maxDiff) {
                maxDiff = diff;
            }
        }

        iter++;

        printf("Iteration %d: ", iter);
        for (int i = 0; i < n; i++) {
            printf("x%d = %.6lf ", i + 1, x[i]);
        }
        printf("\n");

    } while (maxDiff > EPSILON && iter < MAX_ITER);

    printf("Solution after %d iterations:\n", iter);
    for (int i = 0; i < n; i++) {
        printf("x%d = %.6lf\n", i + 1, x[i]);
    }

    return 0;
}