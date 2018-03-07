#ifndef MAIN_H
#define MAIN_H

#include "database.h"

#define NTOWERS 3  //Declaration of the number of towers
#define VERT_BAR "|" //Declaration of a vertical bar
#define UNDERSC "_" //Declaration of an underscore
#define DOT "." //Declaration of a dot
#define TABSPACE "\t" //Declaration of tabulation space

void move(int towerorg, int towerdest,stack list);
void hanoi(int nd, int torg, int tdest, int taux, stack list);
void hanoiprint(stack *list);

#endif /* MAIN_H */

