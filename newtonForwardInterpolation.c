#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of values: ");
    scanf("%d", &n);

    int x[n];
    int y[n][n];

    printf("Enter the values of x:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }

    printf("Enter the values of y:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &y[i][0]);
    }

    // Calculate the differences
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            y[i][j] = y[i + 1][j - 1] - y[i][j - 1];
        }
    }

    // Print the table
    printf("\nNewton Forward Interpolation Table:\n");
    printf("x\t");
    for (int i = 0; i < n; i++) {
        printf("y%d\t", i);
    }
    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t", x[i]);
        for (int j = 0; j < n - i; j++) {
            printf("%d\t", y[i][j]);
        }
        printf("\n");
    }

    return 0;
}
