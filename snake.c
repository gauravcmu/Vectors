#include<stdio.h>

void
printSnake(int A[][3], int rows, int columns)
{
    int i, j;

    for(i=0;i<rows;i++)
        for(j=0;j<columns;j++)
            printf("\n%d", A[i][j+(columns - 1 -(2*j))*(i%2)]);
}
int main()
{
    int A[3][3] = {{1,2,3}, {4,5,6},{7,8,9}};
    printSnake(A, 3, 3);
}
