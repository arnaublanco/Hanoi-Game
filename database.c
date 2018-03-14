#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "database.h"
#include "main.h"

void movedisk(stack *list, int towerorg, int towerdest){
    int n=list->disk;
    node_t* newnode=encapsulateinfo(n);
    int aux;
    for(int c = 0; c < list->disk; c++){
        for(int i = 0; i < NTOWERS; i++){
            newnode->matrix[c][i]=list->top->matrix[c][i];
        }
    }
    
    //memcpy(&newnode,list->top,sizeof(node_t));
    for(int c = 0; c < list->disk; c++){
        if(list->top->matrix[c][towerorg]!=0){
            newnode->matrix[c][towerorg]=0;
            aux=list->top->matrix[c][towerorg];
            break;
        }  
    }
    for(int i = list->disk-1; i >= 0; i--){
        if(list->top->matrix[i][towerdest]==0){
            newnode->matrix[i][towerdest] = aux;
            break;
        }
    }
    push(list,newnode);
}

void push(stack *l,node_t *newnode){  
    newnode->prev=l->top; //Newnode points to old node 
    l->top=newnode; 
    l->top->depth+=1;    
}


void createFirstNode(node_t *newnode, stack *list){
    for(int i=0; i< list->disk; i++){
        for(int j=0; j<NTOWERS; j++){
            if(j==0){
                newnode->matrix[i][j] = i+1;
            }else{
                newnode->matrix[i][j] = 0;
            }
        }
    }
    list->top=newnode;
    //  memcpy(&list->top,&newnode,sizeof(node_t));
}
node_t* encapsulateinfo(int n){
    node_t *newnode=(node_t *)malloc(sizeof(node_t));
    newnode->depth=0;
    newnode->prev=NULL;
    newnode->tdest=0;
    newnode->torg=0;
    newnode->matrix=(int **)malloc(n * sizeof(int *));
    for (int i=0; i<n; i++)
        newnode->matrix[i]= (int *)malloc(NTOWERS * sizeof(int));
    return newnode;
    
}