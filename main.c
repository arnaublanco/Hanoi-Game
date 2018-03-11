#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"
#include "menu.h"
#include "database.h"
#include "playgame.h"

//Function that prints and creates a new move
void move(int towerorg, int towerdest,stack list){
    
    printf("Move one disc from %d to %d\n", 
            towerorg, towerdest);
    
    //new_node(D,towerorg,towerdest,nd,l); //Create a new node
    hanoiprint(&list);
}

void hanoi(int nd, int torg, int tdest, int taux, stack list){
    
    if (nd == 1){
        move(torg, tdest, list);
    }
    else{
        hanoi(nd - 1, torg, taux, tdest, list);
        move(torg, tdest, list);
        hanoi(nd - 1, taux, tdest, torg, list);
    }                                                     
}

int main(int argc, char**argv){
    
    /*DESIGN GAME PRITING*/
    printf("HANOI GAME\n===========\n\n");
    
    /*STACK INITIALISATION*/
    stack list;
    list.top = NULL;
    command(argv,argc,&list); //Check if there is any command
    matrix_init(&list); //Initialise the matrix according to the number of disks
    
   /*REQUEST FOR GAME*/
    //Call function that shows the options
    
    hanoi(list.num,0,1,2,list); //This will be deleted after we have implemented the function that calls the options
    return(0);
}

void hanoiprint(stack *list){
    /*LOOP TO PRINT EACH LINE OF THE DRAWING OF THE GAME*/
    for(int i=0; i<list->disks; i++){
        for(int k=0; k<NTOWERS; k++){
           int mat = list->top->matrix[k][i]; //Declaration of the value in position k i in the matrix
           /*PRINT DOT D-max TIMES*/ 
           for(int j=0; j<list->disks-mat; j++)
                printf("%s",DOT);
           
           /*PRINT UNDERSCORE max TIMES*/
           for(int j=0; j<mat; j++)
                printf("%s",UNDERSC);
           
           /*PRINT VERTICAL BAR*/
           printf("%s",VERT_BAR);
           
           /*PRINT DOT D-max TIMES*/
            for(int j=0; j<list->disks-mat; j++)
                printf("%s",DOT);
           
           /*PRINT UNDERSCORE max TIMES*/
            for(int j=0; j<mat; j++)
                printf("%s",UNDERSC);
           
           //If it's not printing the last tower, then print a tabspace
           if(k<NTOWERS){
               printf("%s",TABSPACE);
           }else{
               printf("%s",NEWLINE);
           }
        }
    }
}