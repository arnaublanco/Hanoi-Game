
#ifndef DATABASE_H
#define DATABASE_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
    node_t *top;
    int num;
}stack;

void new_node(int D,int org,int dest,int depth,stack *l);
void matrix_init(stack *list);

#endif /* DATABASE_H */