
#ifndef DATABASE_H
#define DATABASE_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

//Declaration of a node of the linked list
typedef struct node{
    int **matrix;
    struct node *next;
}node_t;

node_t* new_node();

#endif /* DATABASE_H */