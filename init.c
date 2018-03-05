#include "init.h"
#include "main.h"


void matrix_init(stack *list)
{ 
    list->top->matrix = (int **)malloc(list->num * sizeof(int *)); 
    for (int i=0; i<list->num; i++)
         list->top->matrix[i]= (int *)malloc(NTOWERS * sizeof(int));
}
