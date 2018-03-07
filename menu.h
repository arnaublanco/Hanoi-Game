#ifndef MENU_H
#define	MENU_H

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
void play_game();
void show_game();
int menu_display();
void menu_directory();


#endif	/* MENU_H */

