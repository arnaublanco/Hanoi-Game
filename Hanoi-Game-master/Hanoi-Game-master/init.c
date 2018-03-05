#include "init.h"
#include "main.h"


void matrix_init(int D, stack *list)
{ 
    
    list->top->matrix = (int **)malloc(D * sizeof(int *)); 
    for (int i=0; i<D; i++)
         list->top->matrix[i]= (int *)malloc(NTOWERS * sizeof(int));
    

}
