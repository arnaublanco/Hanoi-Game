/*Created by; Asfandyar Abbasi, Arnau Blanco and Gabriel Graells Solé.
 * 
 * 
 * This file has all the the funtions for a user to play the game.
 * 
 * 
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
int interactive_disc(gstruct *l){
    printf("\nPlay Hanoi Tower Menu:\n%s\n"
            "1.Make a move: Type 1.\n"
            "2.Show hint: Type 2.\n"
            "3.Write in file current game state: Type 3.\n"
            "0.Quit: Type 0.\n%s", LINE, LINE);
    int option;
    printf("\nOption:");
    scanf("%d", &option);
    return option;
}
/*Switch for the command*/
int playgame_directory(gstruct *l, stack *ll){
    int option = interactive_disc(l);
    int counter = 0;
    while(option != 0)
    {
        switch(option)
        {
            case OPTION_1:
                makemove(l, counter);
                counter++;
                hanoiprintg(l, l->disk);
                break;
            case OPTION_2:
                show_hint(counter, ll);
                break;
            case OPTION_3:
                write_file(l, counter);
                break;
            default:
                printf("Invalid option\n");
                break;
                
        }
        option = interactive_disc(l);
    }
    return option;
   
}

/*Ask for the new move to the user, then calls to basic_write_file() function*/
void makemove(gstruct *l, int counter)
{
    int i, j;
    int getd =0;/*buf for disc*/
    printf("\nFrom: Tower");
    scanf("%d", &l->torg);
    /*This looper starts with the top position the firts disc found is taken
     placed un the buff disc and that possition is changed to empty  '0'*/
 
    for(i=0; i<l->disk; i++)
    {
        if(l->matrix[i][l->torg] != 0)
        {
            getd = l->matrix[i][l->torg];/*getd collects the first disc*/
            l->matrix[i][l->torg] = 0; /*that position is switched to 0*/
            i = l->disk;
        }   
    }
        
    /*This loop starts with the lowest position of the dest tower, when it finds the first
     *empty space drops the disc number contained in getd.
     * 
     * 
     */
    int check = 1;
    while(check)
    {
        printf("To: Tower");
        scanf("%d", &l->tdest);
    for(i=l->disk-1; i>=0; i--)
    {
        if(l->matrix[i][l->tdest] == 0)
            {
            if(i+1<5){
            if(l->matrix[i+1][l->tdest]!=0){
            if(l->matrix[i+1][l->tdest]<getd)
            {
                printf("\nIncorrect move, the disc can not be placed in this tower!!!\n");
                i = 0;
            }else
            {
                l->matrix[i][l->tdest] = getd;
                i =0;
                check = 0;
            }
            }else{
            l->matrix[i][l->tdest] = getd;
                i =0;
                check = 0;
            }
            }else{
            l->matrix[i][l->tdest] = getd;
                i =0;
                check = 0;
        }
            }
    }
    }
  
   basic_write_file(l, counter,getd);  
}

/*Creates/appends the file 'game.txt' this function prints the full graphic display of the game*/
void write_file(gstruct *l, int counter)
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
    
    for(int i=0; i<l->disk; i++){
        for(int k=0; k<NTOWERS; k++){
           int dashes = l->matrix[i][k]; //Declaration of the value in position k i in the matrix
           int dots=l->disk-dashes;
           /*PRINT DOT D-max TIMES*/ 
           for(int j=0; j<dots; j++)
                fprintf(f, ".");
           
           /*PRINT UNDERSCORE max TIMES*/
           for(int j=0; j<dashes; j++)
                fprintf(f, "-");
           
           /*PRINT VERTICAL BAR*/
           fprintf(f, "|");
           
           /*PRINT UNDERSCORE max TIMES*/
            for(int j=0; j<dashes; j++)
                fprintf(f, "-");
           
           /*PRINT DOT D-max TIMES*/
            for(int j=0; j<dots; j++)
                fprintf(f, ".");
           
           
           
           //If it's not printing the last tower, then print a tabspace
           if(k<NTOWERS-1){
               fprintf(f, "%s",TABSPACE);
           }
           else{
               fprintf(f, "\n");
           }
        }
    }
    fprintf(f, "\n");
    
}
/*Creates the last possition of the game and compares it to the current one if match the game ends*/
int end_game(gstruct *l)
{
    int mid_tower = 1;
    int **endmatrix;
    int equal = 1;
    /*space reservation for the end result matrix*/
    endmatrix = (int **)malloc(l->disk * sizeof(int *)); 
    for (int i=0; i<l->disk; i++)
         endmatrix[i]= (int *)malloc(NTOWERS * sizeof(int));
    
    
    /*Fill the endmatrix with the end disc positioning*/
    int i, j;
    for(i=0; i<l->disk; i++)
    {
        for(j=0; j<NTOWERS; j++)
        {
           endmatrix[i][j]=0;
        }
    }
    
    for(i=0; i<l->disk; i++)
    {
        int counter=1;
        endmatrix[i][mid_tower]= counter;
        counter++;
    }
    
    for(i=0; i<l->disk; i++)
    {
        for(j=0; j<NTOWERS; j++)
        {
            if(l->matrix[i][j] != endmatrix[i][j])
                equal = 0;
                
        }
    }
    return equal;
}

/*Prints in file the basic information of each move*/
void basic_write_file(gstruct *l, int counter, int getd)
{
    FILE *f;
    char buf[38];
    f = fopen("game.txt", "a");
    if ( f == NULL)
    {
        printf("\nERROR, file 'game.txt' not found, a new game file is going to be created.");
        f = fopen("game.txt", "w");
    }
    sprintf(buf,"\n\nMove disk %d from tower %d to tower %d.\n",getd,l->torg, l->tdest); 
    fputs(buf, f);
    /*LOOP THAT WILL PRINT ALL THE MOVES IN THE FILE*/

    int dots, bars=0;
       //hanoiprint(list->top,list->disks);
       for(int i=0; i<l->disk; i++){
        for(int k=0; k<NTOWERS; k++){
           bars = l->matrix[i][k]; //Number to bars to print same as the size of disk.
           dots=l->disk-bars; //Calculating number of dots to print
           /*PRINT DOT number of disks-mat TIMES*/ 
           for(int j=0; j<dots; j++)
                fprintf(f,"%s",".");
           
           /*PRINT UNDERSCORE mat TIMES*/
           for(int j=0; j<bars; j++)
                fprintf(f,"%s","-");
           
           /*PRINT VERTICAL BAR*/
           fprintf(f,"%s","|");
           
              /*PRINT UNDERSCORE mat TIMES*/
            for(int j=0; j<bars; j++)
                fprintf(f,"%s","-");
           
           /*PRINT DOT umber of disks-mat TIMES*/
            for(int j=0; j<dots; j++)
                fprintf(f,"%s",".");
           
        
           
           //If it's not printing the last tower, then print a tabspace
           if(k<NTOWERS){
               fprintf(f,"%s","\t");
           }else{
               fprintf(f,"%s","\n");
           }
        }
       fprintf(f,"%s","\n"); 
    } 
    fprintf(f,"%s","\n");

    fclose(f);
    
}

void init_matrix(gstruct *l)
{
    l->matrix=(int **)malloc(l->disk * sizeof(int *));
    for (int i=0; i<l->disk; i++)
        l->matrix[i]= (int *)malloc(NTOWERS * sizeof(int));
    
    for(int i=0; i< l->disk; i++){
        for(int j=0; j<NTOWERS; j++){
            if(j==0){
                l->matrix[i][j] = i+1;
            }else{
                l->matrix[i][j] = 0;
            }
        }
    }
       
}

void hanoiprintg(gstruct *newnode,int numdisks){
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
void show_hint(int counter, stack *l)
{
    
    node_t *current_node = l->top; //Create a node that points to the last node
    
    if(counter >= 0 && counter <= l->num){
        //Loop to jump from one node to another
        for(int m=l->num; m>counter; m--){
            current_node = current_node->prev;
        }
        hanoiprint(current_node,l->disk); //Print the move
    }else{
        printf("You did more moves than the minimum necesaries to solve the game.%s",NEWLINE);
    }
}