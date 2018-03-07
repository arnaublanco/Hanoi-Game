#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "database.h"
#include "main.h"

void push(int D,int org,int dest,int depth, Database *db)/*SHOULDN'T THIS PARAMETERS BE INSIDE THE FUNCTION AS PROPER DECLARATION??*/
{
    //Define the variables that will store the tops in tower origin and tower destination
    int toporg, topdest;
    //Find the top in tower origin
    for(int i=D-1; i>=0; i--)
        //If position i in that matrix is equal to 0, it means in the previous position there is the top
        if(db->list.top->matrix[org][i]==0){
            break;
        }else{
            toporg = i;
        }
    //Find the top in tower destination
    for(int i=D-1; i>=0; i--){
        //If position i equals to 0, then there is an empty space
        if(db->list.top->matrix[dest][i]==0)
            topdest = i;
            break;
            
    }
    //Fill those positions with their corresponding values
    db->list.top->matrix[dest][topdest] = db->list.top->matrix[org][toporg];
    db->list.top->matrix[org][toporg] = 0;
    
    node_t returned_node; //Declare a new node
    returned_node.matrix =  db->list.top->matrix; //Setting matrix
    returned_node.prev = db->list.top; //Node points to the previous node
    db->list.top = &returned_node; //List points to this new node, which is the last one
    db->list.num++; //Increase number of nodes by 1
    //TO-DO: Add depth, tower origin and tower destination
    
}
/*FUNCTION THAT INITIALISES THE MATRIX THAT WILL BE USED IN EVERY NODE*/
void matrix_init(Database *db)
{ 
    db->list.top->matrix = (int **)malloc(db->list.num * sizeof(int *)); 
    for (int i=0; i<db->list.num; i++)
         db->list.top->matrix[i]= (int *)malloc(NTOWERS * sizeof(int));
}
/*FUNCTION THAT CHANGES THE NUMBER OF DISKS IN THE DB*/
void change_disks(int n,Database *db){
    db->ndisks = n;
}