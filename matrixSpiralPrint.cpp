#include <cstdio>
#include <cstdlib>

using namespace std;

void printSpiral(int** matrix, int rows, int cols) {
    int i, r = 0, c = 0;

    // r = Starting row index
    // c = Starting column index

    printf("Spiral Print: \n");
    while (r < rows && c < cols) {

        // Print first row from remaining rows
        for (i = c; i < cols; i++) {
            printf("%d ", matrix[r][i]);
        }
        r++;

        // Print last column from remaining columns
        for (i = r; i < rows; i++) {
            printf("%d ", matrix[i][cols-1]);
        }
        cols--;

        // Print last row from remaining rows
        if (r < rows) {
            for (i = cols - 1; i >= c; i--) {
                printf("%d ", matrix[rows - 1][i]);
            }
            rows--;
        }

        // Print first column from remaining columns
        if (c < cols) {
            for (i = rows - 1; i >= r; i--) {
                printf("%d ", matrix[i][c]);
            }
            c++;       
        }
    }

    printf("\n");
}

void printMatrix(int** matrix, int rows, int cols) {
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            printf("%d ", matrix[r][c]);
        }
        printf("\n");
    }
}

int** createMatrix(int rows, int cols) {
    int** matrix = (int**) malloc(rows * sizeof(int*));

    for (int i = 0; i < rows; i++)
        matrix[i] = (int*) malloc(cols * sizeof(int));
    
    printf("Insert matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    return matrix;
}

int main() {

    int rows = 3;
    int cols = 3;
        
    int** matrix = createMatrix(rows, cols);

    printMatrix(matrix, rows, cols);

    printSpiral(matrix, rows, cols);

    return 0;
}