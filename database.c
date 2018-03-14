#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "database.h"
#include "main.h"

/*FUNCTION THAT ADDS THE NODE TO THE LISTZ*/
void push(stack *l,node_t *newnode){  
    newnode->prev = l->top; //Newnode points now to old node
    l->top = newnode; //Top points now to new node
}

/*FUNCTION THAT CREATES FIRST NODE*/
void createFirstNode(node_t *newnode, stack *list){
    /*Loop that fills the first tower with the disks and the rest with 0s*/
    for(int i=0; i< list->disks; i++){
        for(int j=0; j<NTOWERS; j++){
            if(j==0){
                newnode->matrix[i][j] = i+1;
            }else{
                newnode->matrix[i][j] = 0;
            }
        }
    }
    list->top = newnode; //Now list->top points to the first node
}
/*FUNCTION THAT ENCAPSULATES INFO FOR A NODE AND INITIALISES ITS MATRIX*/
node_t* encapsulateinfo(int disks, int torg, int tdest, int depth){
    node_t *newnode=(node_t *)malloc(sizeof(node_t)); //Allocate space for new node
    newnode->depth = depth;
    newnode->prev = NULL;
    newnode->tdest = tdest;
    newnode->torg = torg;
    newnode->matrix=(int **)malloc(disks * sizeof(int *));
    for (int i=0; i<disks; i++)
        newnode->matrix[i]= (int *)malloc(NTOWERS * sizeof(int));
    return newnode;
    
}