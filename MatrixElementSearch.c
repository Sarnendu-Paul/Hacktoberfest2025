#include <stdio.h>

int main() {
    int rows, cols, target, found = 0;

    // Get matrix dimensions
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int matrix[rows][cols];

    // Input matrix elements
    printf("Enter the matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Get search element
    printf("Enter the element to search: ");
    scanf("%d", &target);

    // Search for the element
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == target) {
                printf("Element %d found at position (%d, %d)\n", target, i + 1, j + 1);
                found = 1;
            }
        }
    }

    // Display message if not found
    if (!found) {
        printf("Element %d not found in the matrix.\n", target);
    }

    return 0;
}
