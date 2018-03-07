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
#define DRET 1
#define FRET 2
#define ORET 3

//Declaration of the functions
void play_game(Database *db);
void show_game(Database *db);
int menu_display();
void menu_directory(Database *db);


#endif	/* MENU_H */

