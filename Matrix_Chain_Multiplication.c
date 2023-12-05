#include <stdio.h>

void calculation(int nom, int d[nom + 1]) {
    int m[nom][nom], s[nom][nom];
    int i, j, k, l;

    // Initialize the matrices with zeros
    for (i = 0; i < nom; i++) {
        for (j = 0; j < nom; j++) {
            m[i][j] = 0;
            s[i][j] = 0;
        }
    }

    // Compute the matrices m and s
    for (l = 2; l <= nom; l++) {
        for (i = 0; i < nom - l + 1; i++) {
            j = i + l - 1;
            m[i][j] = 2147483647; // Set to maximum possible value
            for (k = i; k < j; k++) {
                int q = m[i][k] + m[k + 1][j] + d[i] * d[k + 1] * d[j + 1];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k + 1; // Adjusted index by adding 1
                }
            }
        }
    }

    // Print the matrices
    printf("The m matrix is:\n");
    for (i = 0; i < nom; i++) {
        for (j = 0; j < nom; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    printf("The s matrix is:\n");
    for (i = 0; i < nom; i++) {
        for (j = 0; j < nom; j++) {
            printf("%d ", s[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int no_of_matrix;
    printf("Enter the number of matrices for chain multiplication:\n");
    scanf("%d", &no_of_matrix);

    int d[no_of_matrix + 1];
    printf("Enter the order of the matrices:\n");
    for (int i = 0; i <= no_of_matrix; i++) {
        scanf("%d", &d[i]);
    }

    calculation(no_of_matrix, d);
    return 0;
}
