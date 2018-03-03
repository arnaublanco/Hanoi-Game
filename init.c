#include "init.h"



void array_init()
{
    int i, j;
    int discs;
    printf("Please enter the number of discs that you want: ");
    scanf("%d\n", &discs);
        
    node_t.matrix = (int **)malloc(discs * sizeof(int *));/*Pointer to a single array of 'discs' elements*/
    for(i=0; i<discs; i++);
    {
        node_t.matrix = (int *)malloc(TOWERS * sizeof(int));/*Pointer to an array with 'TOWERS' elements*/
    }
    /*Filling the array with the initial disposition*/
    for(i = 0; i<discs; i++)
    {
     for (j = discs; j>discs; j--)
         node_t.matrix[0][i] = j;
    }
    /*Fill the rest of the array with NULL value*/
    for(i=0; i<discs; i++)
    {
        for(j=1; i<TOWERS; j++)
        {
            node_t.matrix[j][i]=NULL;
        }
    }
}
