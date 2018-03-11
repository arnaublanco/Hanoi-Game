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
    /*COUNTER INSIDE A LOOP*/
    int counter = 0;
    
    playgame_directory(l);
    
    init_game(l);
    while(end_game(l) == 1)
    {
        makemove(l);
        /*if () condition that if becomes true makes a fprintf in to the given file*/
    }
}

void show_game(stack *l)
{
  //CALL THE FUNCTIONS THAT CALCULATE THE MOVES AND ASK THE USER WHICH MOVE THEY WANT TO SEE
}

/*FUNCTION THAT EXECUTES THE hanoiplus COMMAND*/
int command(char **cmd, int narg, stack *l){
    /*CHECK IF THE hanoiplus COMMAND HAS BEEN ENTERED*/
    if(strcmp(strstr(HPLUS,cmd[1]),cmd[1])==0){
      for(int i=1; i <= narg; i++){
        if(strcmp(strstr(DCMD,cmd[i]),cmd[i])==0 && i<narg){ /*EXECUTE -d COMMAND IF SPECIFIED*/           
            i++; //Increase i by 1 to go to the next command           
            l->disks = *cmd[i]; //Change the number of disks to cmd[i]
        }else if(strcmp(strstr(FCMD,cmd[i]),cmd[i])==0 && i<narg){ /*EXECUTE -f COMMAND IF SPECIFIED*/         
            //Call the function that creates an external file
        }else if(strcmp(strstr(OCMD,cmd[i]),cmd[i])==0 && i<narg){ /*EXECUTE -o COMMAND IF SPECIFIED*/           
            //Call the function that calls the writing operation
        }
      }
      return 1; //The command/s is/are valid.
    }else{
        return 0; //The command is not valid.
    }
}

void menu_directory(stack *l)
{
    int option = menu_display();
    while (option != 0)
    {
        switch(option)
        {
            case PLAYGAME: 
                    play_game(l);
                    break;
                case SHOWGAME: 
                    show_game(l);
                    break;
                    printf("Please enter a letter to continue\n");
            default:
                printf("Invalid option\n");
                break;
        } 
     option = menu_display();   
    }
    printf("Please enter a letter to continue\n");
}

int menu_display()
{
    int option;
    printf("___________________________________________________________________________\n");
    printf("___________________________________________________________________________\n");
    printf("1-Play Hanoi Tower\n");
    printf("2-See Hanoi Tower Solution\n");
    printf("0-Quit\n");
          
   
    printf("\nSelect option: ");
    scanf("%d", &option);
    printf("___________________________________________________________________________\n");
    printf("___________________________________________________________________________\n");
    return option;
}