#include <stdio.h>
#include <stdlib.h>

int main(){

    printf("Calculate matrix determinant by Gaussian elimination method.\n\n");
    printf("Enter the size of the square matrix:\n");

    int size;
    scanf("%d", &size);

    double matrix[size][size], determinant = 1;
    int signOfDeterminant = 1;

    printf("\nEnter the Matrix elements separate with space or enter:\n");

    for(int row = 0; row < size; row++)
        for(int column = 0; column < size; column++)
            scanf("%lf", &matrix[row][column]);

    // Convert to triangular matrix
    for(int i = 0; i < size; i++)
        for(int j = i + 1; j < size; j++){
            // check if determinant is equal to zero or not
            if(matrix[i][i] == 0){
                for(int m = 1; i + m < size; m++)
                    if(matrix[i + m][i] != 0){
                        double hold[size - i];
                        for(int n = i; n < size; n++){
                            hold[n - i] = matrix[i][n];
                            matrix[i][n] = matrix[i + m][n];
                            matrix[i + m][n] = hold[n - i];
                        }
                        signOfDeterminant *= -1;
                        break;
                    }
                    else{
                        if(i + m == size - 1){
                            // determinant is equal to zero
                            determinant = 0, signOfDeterminant = 1;
                            goto LOOP1;
                        }
                        continue;
                    }
            }
            // changing the amount of some elements to zero
            double Coefficient = matrix[j][i] / matrix[i][i];
            for(int k = i + 1; k < size; k++)
                matrix[j][k] -= Coefficient * matrix[i][k];
        }

    // calculate determinant of triangular matrix
    for(int i = 0; i < size; i++)
        determinant *= matrix[i][i];

    LOOP1:

    printf("\nThe determinant is: %.2f\n", (float) determinant * signOfDeterminant);

    return 1;
}
