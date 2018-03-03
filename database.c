#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "database.h"

node_t* new_node(int **mat,int D,int org,int dest)
{
    //Define the variables that will store the tops in tower origin and tower destination
    int toporg, topdest;
    //Find the top in tower origin
    for(int i=D-1; i>=0; i--)
        //If position i in that matrix is equal to 0, it means in the previous position there is the top
        if(mat[org][i]==0){
            break;
        }else{
            toporg = i;
        }
    //Find the top in tower destination
    for(int i=D-1; i>=0; i--)
        //If position i equals to 0, then there is an empty space
        if(mat[dest][i]==0)
            topdest = i;
            break;           
    //Fill those positions with their corresponding values
    mat[dest][topdest] = mat[org][toporg];
    mat[org][toporg] = 0;
}