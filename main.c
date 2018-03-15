#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"
#include "menu.h"
#include "database.h"
#include "playgame.h"

/*FUNCTION THAT PRINTS AND CREATES A NEW MOVE*/
void move(int depth, int towerorg, int towerdest,stack *list){
    node_t* newnode = encapsulateinfo(list->disks,towerorg,towerdest,depth); //Create new node
    int aux; //Auxiliary variable to store the number of the disk that has to be moved
    //Copy the whole old matrix to the new node's matrix
    for(int c = 0; c < list->disks; c++){
        for(int i = 0; i < NTOWERS; i++){
            newnode->matrix[c][i] = list->top->matrix[c][i];
        }
    }
    //Set the value of the disk at the top of tower origin to 0 (in new matrix)
    for(int c = 0; c < list->disks; c++){
        if(list->top->matrix[c][towerorg]!=0){
            newnode->matrix[c][towerorg] = 0; //Set to 0
            aux = list->top->matrix[c][towerorg]; //Store that value in aux
            break;
        }  
    }
    //Look for the lowest position in tower destination and set it to 'aux' (in new matrix) 
    for(int i = list->disks-1; i >= 0; i--){
        if(list->top->matrix[i][towerdest]==0){
            newnode->matrix[i][towerdest] = aux;
            break;
        }
    }
    push(list,newnode);
    list->moves++;
}
/*HANOI FUNCTION*/
void hanoi(int nd, int torg, int tdest, int taux, stack *list){
    if (nd == 1){
        move(nd, torg, tdest, list);
    }
    else{
        hanoi(nd - 1, torg, taux, tdest, list);
        move(nd, torg, tdest, list);
        hanoi(nd - 1, taux, tdest, torg, list);
    }                                                     
}

int main(int argc, char **argv){
    
    /*GAME DESIGN*/
    printf("HANOI GAME%s==========%s",NEWLINE,NEWLINE);
    
    /*STACK INITIALISATION*/
    stack list;
    list.moves = EMPTY; //Initialise number of moves as 0
    list.disks = NDISKS; //By default, the number of disks is NDISKS
    strlcpy(list.operation,APCMD,MAX_FIELD); //By default, operation is "ap"
    int option = 1;
    int i = 0;
    while(i < argc){
        if(argv[i][0] == '-' && argv [i][1] == 'd' && argv[i+1]){
            list.disks = atoi(argv[i+1]);
        }
        if(argv[i][0] == '-' && argv [i][1] == 'f' && argv[i+1]){
            strcpy(list.fname,argv[i+1]);
            option = 0;
        }
        if(argv[i][0] == '-' && argv [i][1] == 'o' && argv[i+1]){
            strlcpy(list.operation,argv[i+1],MAX_FIELD);
        }
        i++;
    }
    //By default, fname is hanoiplus-<ndisks>d
    if(option==1){
        char *aux;
        sprintf(aux,"%s-%dd",HPLUS,list.disks);
        strlcpy(list.fname,aux,MAX_FIELD);
    }
    
    /*REQUEST FOR THE NUMBER OF DISKS*/
    node_t* newnode = encapsulateinfo(list.disks,TSTART,TSTART,EMPTY); //Initialise the matrix according to the number of disks in a node
    createFirstNode(newnode,&list); //Create the first node
    hanoi(list.disks,TSTART,TAUX,TEND,&list); //Call function that calculates the number of moves of the game
    create_file(&list);
    menu_directory(&list); //Call function that shows the menu to the user
    
    return 0;
}
/*FUNCTION THAT PRINTS A MOVE*/
void hanoiprint(node_t *current_node,int numdisks){
    /*LOOP TO PRINT EACH LINE OF THE DRAWING OF THE GAME*/
    for(int i=0; i<numdisks; i++){
        for(int k=0; k<NTOWERS; k++){
           int dashes = current_node->matrix[i][k]; //Declaration of the value in position k i in the matrix
           int dots = numdisks-dashes; //Declaration of the number of dots
           /*PRINT DOT numdisks-dashes TIMES*/ 
           for(int j=0; j<dots; j++)
                printf("%s",DOT);
           
           /*PRINT UNDERSCORE dashes TIMES*/
           for(int j=0; j<dashes; j++)
                printf("%s",DASH);
           
           /*PRINT VERTICAL BAR*/
           printf("%s",VERT_BAR);
           
           /*PRINT UNDERSCORE dashes TIMES*/
            for(int j=0; j<dashes; j++)
                printf("%s",DASH);
           
           /*PRINT DOT numdisks-dashes TIMES*/
            for(int j=0; j<dots; j++)
                printf("%s",DOT);

           //If it's not printing the last tower, then print a tabspace
           if(k<NTOWERS-1){
               printf("%s",TABSPACE);
           }
           else{
               printf("%s",NEWLINE);
           }
        }
    }
    printf("%s",NEWLINE);
}