#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "database.h"


node_t* new_node(int **mat,int D,int org,int dest)
{
    //1. Load the previous matrix => DONE
    //2. Check who's the top in towerorg
    int toporg;
    for(int i=D-1; i>=0; i--)
        if(mat[org][i]==0){
            toporg = i-1;
            break;
        }else{
            toporg = i;
        }
    //3. Find empty position in towerdest
    int topdest;
    for(int i=D-1; i>=0; i--)
        if(mat[dest][i]==0)
            topdest = i;
            break;
    //4. Fill the matrix
    mat[dest][topdest] = mat[org][toporg];
    mat[org][toporg] = 0;
}