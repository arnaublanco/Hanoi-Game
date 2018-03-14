#ifndef MENU_H
#define	MENU_H
#include "database.h"
/*CONSTANT VARIABLES FOR THE MENU OPTIONS*/
#define PLAYGAME 1
#define SHOWGAME 2
/*CONSTANT VARIABLES FOR THE COMMANDS*/
#define HPLUS "hanoiplus"
#define DCMD "-d"
#define FCMD "-f"
#define OCMD "-o"
#define APCMD "ap"
#define WCMD "w"
#define APPEND 2 //Variable used in the function that appends the moves in a file
/*GENERAL CONSTANT VARIABLES USED IN ALL THE PROGRAM*/
#define TRUE 1
#define FALSE 0
/*CONSTANT VARIABLES FOR TOWERS*/
#define TSTART 0
#define TAUX 1
#define TEND 3

//Declaration of the functions
int play_game(stack *l);
void show_game(stack *l);
int menu_display();
void menu_directory();
void command(char **cmd, int narg, stack *l);
void create_file(stack *l, char *name, int new_file);

#endif	/* MENU_H */

