#include <stdio.h>

#define MAX_SIZE 3

void printMatrix(float matrix[MAX_SIZE][MAX_SIZE+1], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            printf("%.2f\t", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void gaussJordan(float matrix[MAX_SIZE][MAX_SIZE+1], int n) {
    for (int i = 0; i < n; i++) {
        // Pivot element is the current element matrix[i][i]
        float pivot = matrix[i][i];

        // Divide the current row by the pivot element
        for (int j = 0; j <= n; j++) {
            matrix[i][j] /= pivot;
        }

        // Eliminate all other rows
        for (int k = 0; k < n; k++) {
            if (k != i) {
                float factor = matrix[k][i];
                for (int j = 0; j <= n; j++) {
                    matrix[k][j] -= factor * matrix[i][j];
                }
            }
        }
    }
}

int main() {
    int n; // Number of equations and variables
    printf("Enter the number of equations/variables (<= %d): ", MAX_SIZE);
    scanf("%d", &n);

    // Create an augmented matrix with n rows and (n+1) columns
    float matrix[MAX_SIZE][MAX_SIZE + 1];

    // Input coefficients and constants
    printf("Enter the coefficients of the equations:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            scanf("%f", &matrix[i][j]);
        }
    }

    // printf("Original Matrix:\n");
    // printMatrix(matrix, n);

    // Perform Gauss-Jordan elimination
    gaussJordan(matrix, n);

    // printf("Reduced Row Echelon Form:\n");
    // printMatrix(matrix, n);

    printf("Solutions:\n");
    for (int i = 0; i < n; i++) {
        printf("x%d = %.2f\n", i + 1, matrix[i][n]);
    }

    return 0;
}