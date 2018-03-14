#ifndef MAIN_H
#define MAIN_H

#include "database.h"

#define NTOWERS 3  //Declaration of the number of towers
#define NDISKS 5 //Number of disks by default
#define VERT_BAR "|" //Declaration of a vertical bar
#define DASH "-" //Declaration of a dash
#define DOT "." //Declaration of a dot
#define TABSPACE "\t" //Declaration of tabulation space
#define NEWLINE "\n" //Declaration of new line

/*Declaration of the functions*/
void move(int towerorg, int towerdest,stack *list);
void hanoi(int nd, int torg, int tdest, int taux, stack *list);
void hanoiprint(node_t *current_node, int numdisks);

#endif /* MAIN_H */

