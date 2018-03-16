/*Created by; Asfandyar Abbasi, Arnau Blanco and Gabriel Graells Solé.
 * 
 * 
 * .h File for "menu.c"
 * 
 * 
 */
#ifndef MENU_H
#define	MENU_H
#include "database.h"
/*CONSTANT VARIABLES FOR THE MENU OPTIONS*/
#define PLAYGAME 1
#define SHOWGAME 2
/*CONSTANT VARIABLES FOR THE COMMANDS*/

#define TRUE 1
#define FALSE 0

//Declaration of the functions
void play_game(gstruct *ll, stack *l);
void show_game(stack *l);
int display_menu();
void menu_directory();
int command(char **argv, int argc, stack *list);
void create_file(stack *list, char **argv, int argc);
void file_print(stack *list, FILE *f, node_t *cnode);


#endif	/* MENU_H */
