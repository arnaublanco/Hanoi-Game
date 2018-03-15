#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"
#include "menu.h"
#include "database.h"
#include "playgame.h"
//Function that prints and creates a new move
void move(int towerorg, int towerdest,stack *list, int depth){
    movedisk(list, towerorg, towerdest, depth);
    
    hanoiprint(list->top,list->disk);
}

void hanoi(int nd, int torg, int tdest, int taux, stack *list){
    if (nd == 1){
        move(torg, tdest, list, list->disk-nd);
        }
    else{
        hanoi(nd - 1, torg, taux, tdest, list);
        move(torg, tdest, list, list->disk-nd);
        hanoi(nd - 1, taux, tdest, torg, list);
    }                                                     
}

int main(int argc, char **argv){
    /*DESIGN GAME PRITING*/
    printf("HANOI GAME\n===========\n\n");
    
    /*STACK INITIALISATION*/
    stack list;
    list.num = 0;
    strcpy(list.operation,"ap");
    command(argv,argc,&list);
    /*REQUEST FOR THE NUMBER OF DISKS*/
    node_t* newnode=encapsulateinfo(list.disk); //Initialise the matrix according to the number of disks
    createFirstNode(newnode,&list); //create new node function
    hanoi(list.disk,0,1,2,&list);
    create_file(&list);
    menu_directory(&list);
    
    
    return(0);
}

void hanoiprint(node_t *newnode,int numdisks){
    printf(LOGDISKS,newnode->move_num,newnode->disk_moved,newnode->torg,newnode->tdest);
    printf("%s",NEWLINE);
    /*LOOP TO PRINT EACH LINE OF THE DRAWING OF THE GAME*/
    for(int i=0; i<numdisks; i++){
        for(int k=0; k<NTOWERS; k++){
           int dashes = newnode->matrix[i][k]; //Declaration of the value in position k i in the matrix
           int dots=numdisks-dashes;
           /*PRINT DOT D-max TIMES*/ 
           for(int j=0; j<dots; j++)
                printf(".");
           
           /*PRINT UNDERSCORE max TIMES*/
           for(int j=0; j<dashes; j++)
                printf("-");
           
           /*PRINT VERTICAL BAR*/
           printf("|");
           
           /*PRINT UNDERSCORE max TIMES*/
            for(int j=0; j<dashes; j++)
                printf("-");
           
           /*PRINT DOT D-max TIMES*/
            for(int j=0; j<dots; j++)
                printf(".");
           
           
           
           //If it's not printing the last tower, then print a tabspace
           if(k<NTOWERS-1){
               printf("%s",TABSPACE);
           }
           else{
               printf("\n");
           }
        }
    }
    printf("\n");
}