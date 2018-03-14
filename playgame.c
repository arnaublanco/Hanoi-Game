/*Created by; Asfandyar Abbasi, Arnau Blanco and Gabriel Graells Solé.
 * This functions has the menu option of the differents functions of the email
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "database.h"
#include "main.h"
#include "playgame.h"

/*The code uses an static matrix that is rewritten every time hat the user makes a move
 since it is specified in the PDF that there is no need on keeping track of the movements
 -Make a counter to print the move number*/

/*Print for command guides*/
int interactive_disc(stack *l){
    printf("%sPlay Hanoi Tower Menu:%s"
            "1.Make a move: Typer 1.%s"
            "2.Show current game state: Type 2.%s"
            "3.Write in file current game state: Type 3.%s"
            "0.Quit: Type 0 to end the game.%s",NEWLINE,NEWLINE,NEWLINE,NEWLINE,NEWLINE,NEWLINE);
    int option;
    scanf("%d", &option);
    return option;
}
/*Switch for the command*/
void playgame_directory(stack *l){
    int option = interactive_disc(l); //Get user's input
    int counter = 0;
    while(option != 0)
    {
        switch(option)
        {
            case OPTION_1: //OPTION 1: Make a move
                makemove(l, counter);
                counter++;
                break;
            case OPTION_2: //OPTION 2: Show current status of the game
                hanoiprintg(l);
                break;
            case OPTION_3:
                write_file(l, counter); //OPTION 3: Write moves in file
                break;
            default:
                printf("Invalid option.%s",NEWLINE);
                break;
                
        }
        option = interactive_disc(l);
    }
      
   
}

/*Ask for the new move to the user, then calls to basic_write_file() function*/
void makemove(stack *l, int counter)
{
    int i, j;
    int getd;/*buf for disc*/
    printf("Move disc%sFrom: T",NEWLINE);
    scanf("%d", &l->top->torg);
    printf("To: T");
    scanf("%d", &l->top->tdest);
    
    /*This looper starts with the top position the firts disc found is taken
     placed un the buff disc and that possition is changed to empty  '0'*/
    for(i=0; i<l->moves; i++)
    {
        if(l->top->matrix[i][l->top->torg] != 0)
        {
            getd = l->top->matrix[i][l->top->torg];/*getd collects the first disc*/
            l->top->matrix[i][l->top->torg] = 0; /*that position is switched to 0*/
        }
    }
    
    /*This loop starts with the lowest position of the dest tower, when it finds the first
     *empty space drops the disc number contained in getd.
     */
    for(i=l->moves; i>0; i--)
    {
     
        if(l->top->matrix[i][l->top->tdest] == 0)
        {
            l->top->matrix[i][l->top->tdest] = getd;
        }   
    }
    basic_write_file(l, counter);  
}
/*Creates/appends the file 'game.txt' this function prints the full graphic display of the game*/
void write_file(stack *l, int counter)
{
    FILE *f;
    f = fopen("game.txt", "a");
    if (f == NULL)
    {
        printf("\nERROR, file 'game.txt' not found a new game file is going to be created.\n");
        f = fopen("game.txt", "w");
    }
    
    fprintf(f, "\n_______________________________");
    fprintf(f, "\nNumber of moves: %d\n", counter);
    fprintf(f, "_______________________________");
    
    for(int i=0; i<l->disks; i++){
        for(int k=0; k<NTOWERS; k++){
           int mat = l->top->matrix[k][i]; //Declaration of the value in position k i in the matrix
           /*PRINT DOT D-max TIMES*/ 
           for(int j=0; j<l->disks-mat; j++)
                fprintf(f,"%s",DOT);
           
           /*PRINT UNDERSCORE max TIMES*/
           for(int j=0; j<mat; j++)
                fprintf(f,"%s",DASH);
           
           /*PRINT VERTICAL BAR*/
           fprintf(f,"%s",VERT_BAR);
           
           /*PRINT DOT D-max TIMES*/
            for(int j=0; j<l->disks-mat; j++)
                fprintf(f,"%s",DOT);
           
           /*PRINT UNDERSCORE max TIMES*/
            for(int j=0; j<mat; j++)
                fprintf(f,"%s",DASH);
           
           //If it's not printing the last tower, then print a tabspace
           if(k<NTOWERS){
               fprintf(f,"%s",TABSPACE);
           }else{
               fprintf(f,"%s",NEWLINE);
           }
        }
    }
    
}
/*Creates the las possition of the game and compares it to the current one if match the game ends*/
int end_game(stack *l)
{
    int mid_tower = 1;
    int **endmatrix;
    int equal = 1;
    /*space reservation for the end result matrix*/
    endmatrix = (int **)malloc(l->disks * sizeof(int *)); 
    for (int i=0; i<l->disks; i++)
         endmatrix[i]= (int *)malloc(NTOWERS * sizeof(int));
    
    
    /*Fill the endmatrix with the end disc positioning*/
    int i, j;
    for(i=0; i<l->disks; i++)
    {
        for(j=0; j<NTOWERS; j++)
        {
           endmatrix[i][j]=0;
        }
    }
    
    for(i=0; i<l->disks; i++)
    {
        int counter=1;
        endmatrix[i][mid_tower]= counter;
        counter++;
    }
    
    for(i=0; i<l->disks; i++)
    {
        for(j=0; j<NTOWERS; j++)
        {
            if(l->top->matrix[i][j] != endmatrix[i][j])
                equal = 0;
                
        }
    }
    return equal;
}
/*Prints on the screen the full display game*/
void hanoiprintg(stack *l){
    /*LOOP TO PRINT EACH LINE OF THE DRAWING OF THE GAME*/
    for(int i=0; i<l->disks; i++){
        for(int k=0; k<NTOWERS; k++){
           int mat = l->top->matrix[k][i]; //Declaration of the value in position k i in the matrix
           /*PRINT DOT D-max TIMES*/ 
           for(int j=0; j<l->disks-mat; j++)
                printf("%s",DOT);
           
           /*PRINT UNDERSCORE max TIMES*/
           for(int j=0; j<mat; j++)
                printf("%s",DASH);
           
           /*PRINT VERTICAL BAR*/
           printf("%s",VERT_BAR);
           
           /*PRINT DOT D-max TIMES*/
            for(int j=0; j<l->disks-mat; j++)
                printf("%s",DOT);
           
           /*PRINT UNDERSCORE max TIMES*/
            for(int j=0; j<mat; j++)
                printf("%s",DASH);
           
           //If it's not printing the last tower, then print a tabspace
           if(k<NTOWERS){
               printf("%s",TABSPACE);
           }else{
               printf("%s",NEWLINE);
           }
        }
    }
}
/*Prints in file the basic information of each move*/
void basic_write_file(stack *l, int counter)
{
    FILE *f;
    f = fopen("game.txt", "a");
    if ( f == NULL)
    {
        printf("\nERROR, file 'game.txt' not found, a new game file is going to be created.");
        f = fopen("game.txt", "w");
    }
    fprintf(f, "\n_______________________________");
    fprintf(f, "\nNumber of moves: %d\n", counter);
    fprintf(f, "_______________________________");
    fprintf(f, "\nMove disc from %d tower to tower %d.", l->top->torg, l->top->tdest);
    
}