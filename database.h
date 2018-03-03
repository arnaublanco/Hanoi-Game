

#ifndef DATABASE_H
#define DATABASE_H
#define <stdio.h>
/*Constant Variables*/
#define TOWERS 3

/*Struct*/
typedef struct node{
    int **matrix;
    struct node *next;
    struct node *prev;   
}node_t;


/*Functions*/
node_t* new_node();



#ifdef 