#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

// This function indicates a move of one disk
void move(int towerorg, int towerdest,int **mat,int D,int nd){
    
    printf("Move one disc from %d to %d\n", 
            towerorg, towerdest);
    
    node_t n = new_node(mat,D,towerorg,towerdest,nd); //Create a new node
    
}// move

// Recursive function to move nd disks from the origin tower towerorg, to 
// destination tower towerdest, using toweraux as auxiliary tower.
// it doesn't return anything and instead it prints information of the move of 
// the disks to display
void hanoi(int nd,int towerorg,int towerdest,int toweraux,int **mat, int D){
    
    if (nd == 1){
        move(towerorg, towerdest, mat, D, nd);
    }
    else{
        hanoi(nd - 1, towerorg, toweraux, towerdest);
        move(towerorg, towerdest, mat, D, nd);
        hanoi(nd - 1, toweraux, towerdest, towerorg);
    }                                                     
}// hanoi

int main(){    
    
    int n; //Number of disks the user wants
    printf("How many disks do you want?");
    scanf("%d",&n); //Ask the number of disks
    int **matrix = matrix_init(n); //Initialise the matrix
    
    hanoi(n,0,1,2 //Call hanoi function
    
    return(0);
}

void dotprint(int k){
     for(int c = 0; c<k; c++){
            printf(".");
}
}
void dashprint(int c){
    for (int k = 0;k <c; k++){
            printf("-");
}
}
void hanoiprint(int *mat[]){
    int dots1, dots2, dots3;
    for(int i = (NDISCS-1); i>=0; i--){
        dots1=(NDISCS-mat[0][i]);
        dotprint(dots1);
        dashprint(mat[0][i]);
        printf("|");
        dashprint(mat[0][i]);
        dotprint(dots1);
        printf("  ");
        
        dots2=NDISCS-mat[1][i];
        dotprint(dots2);
        dashprint(mat[1][i]);
        printf("|");
        dashprint(mat[1][i]);
        dotprint(dots2);
        printf("  ");
        
        dots3=NDISCS-mat[2][i];
        dotprint(dots3);
        dashprint(mat[2][i]);
        printf("|");
        dashprint(mat[2][i]);
        dotprint(dots3);
        printf("\n");
    }
}
