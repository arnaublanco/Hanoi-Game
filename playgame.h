

#ifndef PLAYGAME_H
#define PLAYGAME_H
/*variable*/
#define OPTION 35
#define OPTION_1 1
#define OPTION_2 2
#define OPTION_3 3
#define NTOWER 2


/*Functions*/
void basic_write_file(stack *l, int counter);
void hanoiprintg(stack *l);
int end_game(stack *l);
void write_file(stack *l, int counter);
void makemove(stack *l, int counter);
void playgame_directory(stack *l);
int interactive_disc(stack *l);
#endif /* PLAYGAME_H */

