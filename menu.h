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
#define TRUE 1
#define FALSE 0
#define APPEND 2

//Declaration of the functions
void play_game(stack *l);
void show_game(stack *l);
int menu_display();
void menu_directory();
void command(char **argv, int argc, stack *list);
void create_file(stack *list);
void file_print(stack *list, FILE *f, node_t *cnode);


#endif	/* MENU_H */
