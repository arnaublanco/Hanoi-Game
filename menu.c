/*Created by; Gabriel Graells Solé, Asfandyar Abbasi and Arnau Blanco
 * This functions has the menu option of the different functions of the email
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "menu.h"
#include "playgame.h"
#include "main.h"

void play_game(stack *l)
{
    printf("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
    /*COUNTER INSIDE A LOOP*/
    init_game(l);
    while(end_game(l) != 1)
    {
        playgame_directory(l);
    }
}
/*FUNCTION THAT EXECUTES THE hanoiplus COMMAND*/
void command(char **cmd, int narg, stack *l){
    int disks_changed = FALSE; //Variable to know if the disks have been changed or not
    int create_new = FALSE; //Variable to know if the user wants to create a new file or not
    char *name; //Variable that stores the name of the file that the user may want to create
    /*CHECK IF THE hanoiplus COMMAND HAS BEEN ENTERED*/
    if(narg > 1){
    if(strcmp(HPLUS,cmd[1])==0){/*SEGMENTATION FAULT as there is no argument*/
      for(int i=0; i < narg; i++){
        if(strcmp(DCMD,cmd[i])==0 && i+1<narg){ /*EXECUTE -d COMMAND IF SPECIFIED*/
            i++; //Increase i by 1 to go to the next command           
            l->disk = atoi(cmd[i]); //Change the number of disks to cmd[i]
            disks_changed = TRUE; //The number of disks has changed
        }else if(strcmp(FCMD,cmd[i])==0){ /*EXECUTE -f COMMAND IF SPECIFIED*/
            //If there isn't another command afterwards, it means the program has to create a file. Otherwise, it has to show the moves on screen.
            if(cmd[i+1]){
                if(strcmp(DCMD,cmd[i+1])==0 || strcmp(OCMD,cmd[i+1])==0){
                    //Call hanoiprint as many times as moves there are
                    for(int w=0; w<l->num; w++){
                        hanoiprint(l->top,l->num);
                    }
                }else{
                    i++; //Increase i by 1 to go to the next command
                    create_new = TRUE; //The program will create a new file
                    name = cmd[i]; //Store the name of the file in 'name'
                }
            }else{
                //Call hanoiprint as many times as moves there are
                for(int w=0; w<l->num; w++){
                    hanoiprint(l->top,l->num);
                }
            }
        }else if(strcmp(OCMD,cmd[i])==0 && i+1<narg){ /*EXECUTE -o COMMAND IF SPECIFIED*/           
            if(strcmp(APCMD,cmd[i])==0){
                create_new = APPEND; //Get the given file and append the content at the end of it
            }else if(strcmp(WCMD,cmd[i])==0){
                create_new = TRUE; //Create the same file, that is, overwrite it
            }
        }
      }
      if(create_new==TRUE){
          create_file(l, name, TRUE); //Call the function that creates an external file or overwrites it
      }else if(create_new==APPEND){
          create_file(l, name, FALSE); //Call the function that appends content at the end of a given file
      }
    }
}else printf("\nERROR, no commands found.\n");
    //If the number disks has not been changed, then set it to its default value
    if(!disks_changed){
        l->disk = NDISKS;
    }
}

void create_file(stack *list, char *name, int new_file){
    FILE *f; //Declare the file
    //If new_file is true, then create a new file or overwrite it. Otherwise, append the content at the end of it.
    if(new_file){
        f = fopen(strcat(name,".txt"),"w"); //Open file with given name
    }else{
        f = fopen(strcat(name,".txt"),"a");
    }
    //Check if the file has been opened correctly
    if(f==NULL){
        printf("Error while creating the file.");
        exit(0);
    }
    /*LOOP THAT WILL PRINT ALL THE MOVES IN THE FILE*/
    for(int j=0; j < list->num; j++){
       node_t *current_node = list->top; //Create a node that points to the last node
       /*LOOP TO GO THE CORRESPONDING NODE. Ex: (5 MOVES) If j = 0 (that is, node 1), the loop runs moves-(j+1) = 5-(0+1)=4 times */
       for(int m=list->num; m>j+1; m--){
           current_node = current_node->prev;
       }
       for(int i=0; i<list->disk; i++){
        for(int k=0; k<NTOWERS; k++){
           int mat = list->top->matrix[k][i]; //Declaration of the value in position k i in the matrix
           /*PRINT DOT D-max TIMES*/ 
           for(int j=0; j<list->disk-mat; j++)
                printf("%s",DOT);
           
           /*PRINT UNDERSCORE max TIMES*/
           for(int j=0; j<mat; j++)
                printf("%s",UNDERSC);
           
           /*PRINT VERTICAL BAR*/
           printf("%s",VERT_BAR);
           
           /*PRINT DOT D-max TIMES*/
            for(int j=0; j<list->disk-mat; j++)
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
}


int display_menu()
{
    int option;
    printf("\nMenu Options.\n"
            "1.Show Hanoi solution. Type 1.\n"
            "2.Play Hanoi. Type 2.\n"
            "0.Exit. Type 0.\n\n"
            "Option: ");
    scanf("%d", &option);
    return option;
}

void menu_directory(stack *l)
{
    int option;
    option = display_menu();
    
    while (option != 0)
    {
        switch(option)
        {
            case OPTION_1:
                break;
            case OPTION_2:
                play_game(l);
                break;
            default:
                printf("\nInvalid option.\n");
                break;
        }
        option = display_menu();
    }
}