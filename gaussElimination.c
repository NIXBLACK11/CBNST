#include <stdio.h>

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    double mat[n][n + 1];

    printf("Enter the value of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            scanf("%lf", &mat[i][j]); // Use %lf for double
        }
    }

    // Gauss elimination
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double ratio = mat[j][i] / mat[i][i];
            for (int k = 0; k < n + 1; k++) {
                mat[j][k] = mat[j][k] - ratio * mat[i][k];
            }
        }
    }

    // Back substitution
    double value[n];
    for (int i = 0; i < n; i++) {
        value[i] = 0.0; // Initialize with zeros
    }

    for (int i = n - 1; i >= 0; i--) {
        double sum = 0;
        for (int j = i + 1; j < n; j++) {
            sum += mat[i][j] * value[j];
        }
        value[i] = (mat[i][n] - sum) / mat[i][i];
    }

    printf("Solution for the system of equations:\n");
    for (int i = 0; i < n; i++) {
        printf("x%d = %.2lf\n", i + 1, value[i]);
    }

    return 0;
}
