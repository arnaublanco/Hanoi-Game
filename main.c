#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

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

int main(){
    
    /*DESIGN GAME PRITING*/
    printf("HANOI GAME\n===========\n\n");
    
    /*STACK INITIALISATION*/
    stack list;
    list.top = NULL;
    
    /*REQUEST FOR THE NUMBER OF DISKS*/
    int n;
    printf("How many disks do you want to play with? ");
    scanf("%d",&n);
    list.num = n;
    matrix_init(list); //Initialise the matrix according to the number of disks
    
    hanoi(n,0,1,2,list); //Call hanoi function
    
    return(0);
}

void hanoiprint(stack *list){
    /*LOOP TO PRINT EACH LINE OF THE DRAWING OF THE GAME*/
    for(int i=0; i<list->num; i++){
        for(int k=0; k<NTOWERS; k++){
           int max = list->top->matrix[k][i]; //Declaration of the value in position k i in the matrix
           /*PRINT DOT D-max TIMES*/ 
           for(int j=0; j<list->num-max; j++)
                printf("%s",DOT);
           
           /*PRINT UNDERSCORE max TIMES*/
           for(int j=0; j<max; j++)
                printf("%s",UNDERSC);
           
           /*PRINT VERTICAL BAR*/
           printf("%s",VERT_BAR);
           
           /*PRINT DOT D-max TIMES*/
            for(int j=0; j<list->num-max; j++)
                printf("%s",DOT);
           
           /*PRINT UNDERSCORE max TIMES*/
            for(int j=0; j<max; j++)
                printf("%s",UNDERSC);
           
           //If it's not printing the last tower, then print a tabspace
           if(i<list->num){
               printf("%s",TABSPACE);
           }
        }
    }
}