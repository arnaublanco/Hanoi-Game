#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "database.h"

void new_node(int D,int org,int dest,int depth, stack *l)
{
    //Define the variables that will store the tops in tower origin and tower destination
    int toporg, topdest;
    //Find the top in tower origin
    for(int i=D-1; i>=0; i--)
        //If position i in that matrix is equal to 0, it means in the previous position there is the top
        if(l->top->matrix[org][i]==0){
            break;
        }else{
            toporg = i;
        }
    //Find the top in tower destination
    for(int i=D-1; i>=0; i--){
        //If position i equals to 0, then there is an empty space
        if(l->top->matrix[dest][i]==0)
            topdest = i;
            break;
            
    }
    //Fill those positions with their corresponding values
    l->top->matrix[dest][topdest] = l->top->matrix[org][toporg];
    l->top->matrix[org][toporg] = 0;
    
    node_t returned_node; //Declare a new node
    returned_node.matrix =  l->top->matrix; //Setting matrix
    returned_node.prev = l->top; //Node points to the previous node
    l->top = &returned_node; //List points to this new node, which is the last one
    l->num++; //Increase number of nodes by 1
    //TO-DO: Add depth, tower origin and tower destination
    
}