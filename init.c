#include "init.h"
#include "main.h"

int** matrix_init(int D)
{
    int **matrix;
    for (int i=0; i<D; i++)
         matrix[i] = (int *)malloc(NTOWERS * sizeof(int));
    
    return matrix;

}