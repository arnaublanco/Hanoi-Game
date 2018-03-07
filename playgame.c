/*Created by; Asfandyar Abbasi, Arnau Blanco and Gabriel Graells Solé.
 * This functions has the menu option of the differents functions of the email
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "database.h"
#include "main.h"
#include "playgame.h"

/*The code uses an static matrix that is rewrited every time hat the user makes a move
 since it is specified in the PDF that there is no need on keeping track of the movements
 -Makea counter to print the move number*/

/*Print for command guides*/
int interactive_disc(stack *l){
    printf("Comandos:\n 1. '1': Type 'd' +Enter and when asked type the number of dics.\n"
            "2. '2': move, make a new move.\n"
            "   2.1 -How to do a move-: Select the disc by typing the tower number ('1,2,3') then "
            "type the tower number where you want to drop the disc.\n"
            "3.- '0': to exit.");
    char option;
    return option;
}
/*Switch for the commant*/
void playgame_directory(stack *l){
    int option = interactive_disc(l);
    while(option != 0)
    {
        switch(option)
        {
            case OPTION_1:
                init_game(l);
                break;
            default:
                printf("Invalid option\n");
                break;
                
        }
        option = interactive_disc(l);
    }
      
   
}/*Ask for number of disck, creates and prints the init display*/
void init_game(stack *l){
    int i, j;
    printf("\nEnter the number of discs: ");
    scanf("%d", &l->num);
    /*Init matrix*/
    matrix_init(l);
    
    for(i=0; i<l->num; i++)
    {
        for(j=0; j<NTOWERS; j++)
        {
            l->top->matrix[i][j]=-1;
        }
    }
    
    for(i=0; i<l->num; i++)
    {
        int counter;
        l->top->matrix[i][0]= counter;
        counter ++;
    }
 
            
    /*Fill unused parameters*/
    l->top->depth = NUL;
    l->top->prev = NULL;
    l->top->tdest = NUL;
    l->top->torg = NUL;
}
void makemove(stack *l)
{
    int i, j;
    int getd;/*buf for disc*/
    printf("Move disc from ");
    scanf("%d", &l->top->torg);
    printf(" to tower ");
    scanf("%d", &l->top->tdest);
    
    for(i=l->num; i>l->num; i--)
    {
        if(l->top->matrix[i][l->top->torg] != -1)
        {
            getd = l->top->matrix[i][l->top->torg];
        }
    }
    
    for(i=0; i<l->num; i++)
    {
     
        if(l->top->matrix[i][l->top->torg] == -1)
        {
            l->top->matrix[i][l->top->torg] = getd;
        }   
    }
    
}
/*Each time that a game is initialized the file game.txt is rewrited!!!*/
void write_file(stack *l, int counter)
{
    FILE *f;
    f = fopen("game.txt", "w");
    if (f == NULL)
    {
        printf("\nERROR, file 'game.txt' not found.");
    }
    
    f("_______________________________");
    fprintf(f, "\nNumber of moves: %d\n", counter);
    fputs("_______________________________");
    
    for(int i=0; i<l->num; i++){
        for(int k=0; k<NTOWERS; k++){
           int max = l->top->matrix[k][i]; //Declaration of the value in position k i in the matrix
           /*PRINT DOT D-max TIMES*/ 
           for(int j=0; j<l->num-max; j++)
                fprintf(f,"%s",DOT);
           
           /*PRINT UNDERSCORE max TIMES*/
           for(int j=0; j<max; j++)
                fprintf(f,"%s",UNDERSC);
           
           /*PRINT VERTICAL BAR*/
           fprintf(f, "%s",VERT_BAR);
           
           /*PRINT DOT D-max TIMES*/
            for(int j=0; j<l->num-max; j++)
               fprintf(f, "%s",DOT);
           
           /*PRINT UNDERSCORE max TIMES*/
            for(int j=0; j<max; j++)
                fprintf(f, "%s",UNDERSC);
           
           //If it's not printing the last tower, then print a tabspace
           if(i<l->num){
               fprintf(f, "%s",TABSPACE);
           }
        }
    }
    
}