/*Created by; Gabriel Graells Solé, Asfandyar Abbasi and Arnau Blanco
 * This functions has the menu option of the different functions of the email
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "menu.h"
#include "playgame.h"
#include "main.h"

/*FUNCTION THAT ALLOWS THE USER TO PLAY THE GAME*/
int play_game(stack *l)
{
    int exit = 1;
    while(end_game(l) != 1 && exit != 0)
    {  
        playgame_directory(l); //Call the function that shows the menu to the user and scans the option they choose
        printf("Type 0 again to exit.");
        scanf("%d", &exit);
    }
    return exit;
}
/*FUNCTION THAT CREATES A FILE*/
void create_file(stack *list){
    FILE *f; //Declare the file
    char path[MAX_FIELD]; //Declaration of the path of the file
    sprintf(path,"%s%s",list->fname,".txt"); //path = name.txt (THIS IS NOT WORKING)
    //If new_file is true, then create a new file or overwrite it. Otherwise, append the content at the end of it.
    if(strcmp(list->operation,"w")==0){
        f = fopen(path,"w"); //Open file with given name
    }else if(strcmp(list->operation,"ap")==0){
        f = fopen(path,"a"); //Append file with given name
    }
    //Check if the file has been opened correctly
    if(f==NULL){
        printf("Error while creating the file.");
        exit(0);
    }
    for(int c=0; c<list->moves; c++){
        node_t *cnode = list->top;
        for(int m=list->moves; m>0; m--){
            cnode = cnode->prev;
        }
        file_print(list,f,cnode);
    }
    fclose(f);
}
/*FUNCTION THAT DISPLAY THE MENU ON-SCREEN*/
int display_menu()
{
    int option;
    printf("%sMenu Options.%s"
            "1.Show Hanoi solution. Type 1.%s"
            "2.Play Hanoi. Type 2.%s"
            "0.Exit. Type 0.%s%s"
            "Option: ",NEWLINE,NEWLINE,NEWLINE,NEWLINE,NEWLINE,NEWLINE);
    scanf("%d", &option);
    return option;
}
/*FUNCTION THAT EXECUTES THE OPTION THAT USER CHOOSES*/
void menu_directory(stack *l)
{
    int option;
    option = display_menu(); //Call function that shows menu to user and scans option
    
    //While 'option' is not 0, show the menu
    while (option != 0)
    {
        switch(option)
        {
            case OPTION_1: //OPTION 1: Show moves of the game
                show_game(l);
                break;
            case OPTION_2: //OPTION 2: Play the game yourself
                option = play_game(l); //
                break;
            default:
                printf("\nInvalid option.\n");
                break;
        }
        if(option!=0){
            option = display_menu();
        }
    }
}
/*FUNCTION THAT SHOWS A MOVE ON-SCREEN*/
void show_game(stack *l){
    int move; //Declare move which stores the input of the user
    node_t *current_node = l->top; //Create a node that points to the last node
    printf("%sType the number of the move you want to see: ",NEWLINE);
    scanf("%d",&move); //Scan user's input
    //If the user's input is not valid, then print a warning message
    if(move >= 0 && move <= l->moves){
        //Loop to jump from one node to another
        for(int m=l->moves; m>move; m--){
            current_node = current_node->prev;
        }
        hanoiprint(current_node,l->disks); //Print the move
    }else{
        printf("This move does not exist.%s",NEWLINE);
    }
}
void file_print(stack *list, FILE *f, node_t *cnode){
    /*LOOP THAT WILL PRINT ALL THE MOVES IN THE FILE*/
    printf("move from %d to %d",cnode->torg,cnode->tdest);
    int dots, bars=0;
       //hanoiprint(list->top,list->disks);
       for(int i=0; i<list->disks; i++){
        for(int k=0; k<NTOWERS; k++){
           bars = cnode->matrix[i][k]; //Declaration of the value in position k i in the matrix
           dots=list->disks-bars;
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
    }
