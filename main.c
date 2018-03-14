#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"
#include "menu.h"
#include "database.h"
#include "playgame.h"
//Function that prints and creates a new move
void move(int towerorg, int towerdest,stack *list){
    movedisk(list, towerorg, towerdest);
    list->moves++;
}

void hanoi(int nd, int torg, int tdest, int taux, stack *list){
    if (nd == 1){
        move(torg, tdest, list);
        }
    else{
        hanoi(nd - 1, torg, taux, tdest, list);
        move(torg, tdest, list);
        hanoi(nd - 1, taux, tdest, torg, list);
    }                                                     
}

int main(int argc, char **argv){
    
    /*STACK INITIALISATION*/
    stack list;
    command(argv,argc,&list);
    
    /*REQUEST FOR THE NUMBER OF DISKS*/
    node_t* newnode = encapsulateinfo(list.disks); //Initialise the matrix according to the number of disks in a node
    createFirstNode(newnode,&list); //Create the first node
    hanoi(list.disks,TSTART,TAUX,TEND,&list); //Call function that calculates the number of moves of the game
    menu_directory(&list); //Call function that shows the menu to the user
    
    return 0;
}

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