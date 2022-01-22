#include <stdio.h>

double determinant(int size, double matrix[size][size])
{
    double determinant = 1;
    int sign = 1;

    // Convert input matrix to triangular matrix by Gaussian elimination method
    // (The Gaussian elimination method is a little different, so I assume that
    // there is no solution section)
    for (int i = 0; i < size - 1; i++)
        for (int j = i + 1; j < size; j++)
        {
            // Check if determinant is equal to zero or not
            // (If any elements of the main diameter is equal to zero,
            // and we can't fix it by swapping two rows together the
            // determinant will be equal to zero)
            if (matrix[i][i] == 0)
            {
                for (int m = 1; i + m < size; m++)
                {
                    if (matrix[i + m][i] != 0)
                    {
                        // Swap two rows together
                        double tmp[size - i];
                        for (int n = i; n < size; n++)
                        {
                            tmp[n - i] = matrix[i][n];
                            matrix[i][n] = matrix[i + m][n];
                            matrix[i + m][n] = tmp[n - i];
                        }

                        // (If two rows are swapped, the determinant sign changes)
                        sign *= -1;

                        break;
                    }
                    else if (i + m == size - 1)
                    {
                        // Determinant is equal to zero
                        return 0;
                    }
                }
            }

            // Changing the amount of elements below the main diameter to zero
            // (To do this the other elements in current row will be affected)
            if (matrix[j][i] != 0)
            {
                double Coefficient = matrix[j][i] / matrix[i][i];

                for (int k = j; k < size; k++)
                    matrix[j][k] -= Coefficient * matrix[i][k];

                matrix[j][i] = 0;
            }
        }

    // Calculate determinant of triangular matrix
    // (Determinant for triangular matrix is equal to Multiply the
    // elements on the original diameter)
    for (int i = 0; i < size; i++)
        determinant *= matrix[i][i];

    if (determinant == 0)
        return 0;

    return determinant * sign;
}

int main()
{
    printf("Enter the size of the square matrix: ");
    int size;
    scanf("%d", &size);

    double matrix[size][size];

    printf("\nEnter the Matrix elements:\n");

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            scanf("%lf", &matrix[i][j]);

    printf("\nThe determinant is: %.2f\n", determinant(size, matrix));

    return 1;
}
