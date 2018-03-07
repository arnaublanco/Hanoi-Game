/*Created by; Gabriel Graells Solé, Asfandyar Abbasi and Arnau Blanco
 * This functions has the menu option of the differents functions of the email
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "menu.h"
#include "database.h"

void play_game(Database *db)
{
    //push(D,org,dest,depth,l); //NO TENS D, org, dest NI depth DEFINITS
    //interactive_disc(l); //ON HAS CREAT AQUESTA FUNCIÓ?
    matrix_init(db);
}

void show_game(Database *db)
{
  //CALL THE FUNCTIONS THAT CALCULATE THE MOVES AND ASK THE USER WHICH MOVE THEY WANT TO SEE
}

/*FUNCTION THAT EXECUTES THE hanoiplus COMMAND*/
int command(char *cmd,Database *db){
    /*CHECK IF THE hanoiplus COMMAND HAS BEEN ENTERED*/
    if(strcmp(strstr(HPLUS,cmd),cmd)==0){
        /*EXECUTE -d COMMAND IF SPECIFIED*/
        if(strcmp(strstr(DCMD,cmd),cmd)==0){
            //GET THE NUMBER THAT USER HAS ENTERED
            change_disks(0,db); //Call the function that changes the number of disks (CHANGE 0 FOR THE NUMBER OF DISKS!!)
            return DRET;
        }
        /*EXECUTE -f COMMAND IF SPECIFIED*/
        if(strcmp(strstr(FCMD,cmd),cmd)==0){
            //Call the function that creates an external file
            return FRET;
        }
        /*EXECUTE -o COMMAND IF SPECIFIED*/
        if(strcmp(strstr(OCMD,cmd),cmd)==0){
            //Call the function that calls the writing operation
            return ORET;
        }
    }else{
        return 0; //The command is not valid.
    }
}

void menu_directory(Database *db)
{
    int option = menu_display();
    while (option != 0)
    {
        switch(option)
        {
            case PLAYGAME: 
                    play_game(db);
                    break;
                case SHOWGAME: 
                    show_game(db);
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