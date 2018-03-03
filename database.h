
#ifndef DATABASE_H
#define DATABASE_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

//Declaration of a node of the linked list
struct node{
    int **matrix;
    int depth;
    int torg;
    int tdest;
    struct node *prev;
};
typedef struct node node_t;
//Declaration of the list
typedef struct{
    node_t *last;
    int num;
}list;

node_t* new_node(int **mat,int D,int org,int dest,node_t last);

//FOR LOOP: node.next

#endif /* DATABASE_H */