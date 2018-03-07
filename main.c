#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

//Function that prints and creates a new move
void move(int depth, int towerorg, int towerdest,Database *db){
    
    printf("Move one disc from %d to %d\n", 
            towerorg, towerdest);
    
    //new_node(D,towerorg,towerdest,nd,l); //Create a new node
    hanoiprint(db,towerorg,towerdest,depth);
}

void hanoi(int nd, int torg, int tdest, int taux, Database *db){
    
    if (nd == 1){
        move(nd, torg, tdest, db);
    }
    else{
        hanoi(nd - 1, torg, taux, tdest, db);
        move(nd, torg, tdest, db);
        hanoi(nd - 1, taux, tdest, torg, db);
    }                                                     
}

int main(){
    
    /*DESIGN GAME PRITING*/
    printf("HANOI GAME\n===========\n\n");
    
    /*DATABASE INITIALISATION*/
    Database db;
    db.list.top = NULL;
    db.ndisks = NDISKS;
    db.ntowers = NTOWERS;
    //matrix_init(&db); //Initialise the matrix according to the number of disks (WE HAVE PROBLEMS WITH THIS FUNCTION, SO MEANWHILE I'LL COMMENT IT)
    
    hanoi(db.ndisks,0,1,2,&db); //Call hanoi function
    
    return(0);
}

void hanoiprint(Database *db,int torg,int tdest,int depth){
    printf("Move count %d Rec Depth %d : it moves disc %d from T%d to T%d",db->list.num,depth,1,torg,tdest); //Print text line first (CHANGE 1 FOR THE DISC NUMBER)
    /*LOOP TO PRINT EACH LINE OF THE DRAWING OF THE GAME*/
    for(int i=0; i<db->list.num; i++){
        for(int k=0; k<NTOWERS; k++){
           int max = db->list.top->matrix[k][i]; //Declaration of the value in position k i in the matrix
           /*PRINT DOT D-max TIMES*/ 
           for(int j=0; j<db->list.num-max; j++)
                printf("%s",DOT);
           
           /*PRINT UNDERSCORE max TIMES*/
           for(int j=0; j<max; j++)
                printf("%s",UNDERSC);
           
           /*PRINT VERTICAL BAR*/
           printf("%s",VERT_BAR);
           
           /*PRINT DOT D-max TIMES*/
            for(int j=0; j<db->list.num-max; j++)
                printf("%s",DOT);
           
           /*PRINT UNDERSCORE max TIMES*/
            for(int j=0; j<max; j++)
                printf("%s",UNDERSC);
           
           //If it's not printing the last tower, then print a tabspace
           if(i<db->list.num){
               printf("%s",TABSPACE);
           }
        }
    }
}