
#ifndef DATABASE_H
#define DATABASE_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUL -1

//Declaration of a node of the linked list
struct node{
    int **matrix; //Matrix that stores the position of the disks
    int depth; //Depth of the move
    int torg; //Tower origin of the disk moved
    int tdest; //Tower destination of the disk moved
    struct node *prev; //Variable that points to the previous move
};
typedef struct node node_t;
//Declaration of the list
typedef struct{
    node_t *top; //Variable that points to the last move
    int num; //Total number of moves
    int disk; //Total number of disks
}stack;

void movedisk(stack *list, int towerorg, int towerdest);
void push(stack *list,node_t *newnode);
void createFirstNode(node_t *newnode,stack *list);
node_t* encapsulateinfo(int n);

#endif /* DATABASE_H */