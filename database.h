
#ifndef DATABASE_H
#define DATABASE_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*Declaration of a node of the linked list*/
struct node{
    int **matrix; //Matrix that stores the position of the disks
    int depth; //Depth of the move
    int torg; //Tower origin of the disk moved
    int tdest; //Tower destination of the disk moved
    struct node *prev; //Variable that points to the previous move
};
typedef struct node node_t;
/*Declaration of the list*/
typedef struct{
    node_t *top; //Variable that points to the last move
    int num; //Total number of moves
}stack;
/*Declaration of the database*/
typedef struct{
    stack list;
    int ndisks;
    int ntowers;
}Database;

void push(int D,int org,int dest,int depth,Database *db);
void matrix_init(Database *db);
void change_disks(int n,Database *db);

#endif /* DATABASE_H */