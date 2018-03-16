
#ifndef PLAYGAME_H
#define PLAYGAME_H
/*variable*/
#define OPTION 35
#define OPTION_1 1
#define OPTION_2 2
#define OPTION_3 3
#define NTOWER 2


/*Functions*/
void show_hint(int counter, stack *l);
void hanoiprintg(gstruct *newnode,int numdisks);
void init_matrix(gstruct *l);
void basic_write_file(gstruct *l, int counter, int getd);
int end_game(gstruct *l);
void write_file(gstruct *l, int counter);
void makemove(gstruct *l, int counter);
int playgame_directory(gstruct *l, stack *ll);
int interactive_disc(gstruct *l);
#endif /* PLAYGAME_H */