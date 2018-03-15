#ifndef MAIN_H
#define MAIN_H

#include "database.h"

#define NTOWERS 3  //Declaration of the number of towers
#define NDISKS 5 //Number of disks by default
#define VERT_BAR "|" //Declaration of a vertical bar
#define UNDERSC "_" //Declaration of an underscore
#define DOT "." //Declaration of a dot
#define TABSPACE "\t" //Declaration of tabulation space
#define NEWLINE "\n" //Declaration of new line
#define LINE "=============================================" //Declaration of line

#define LOGS 1 //Choose between 0 or non-zero number
#define LOGLIST 0
#if LOGS
#define LOGDISKS "Move count %d Rec Depth %d: it moves disc %d from T%d to T%d"
#else
#define LOGDISKS ""
#endif
#if LOGLIST
#define LOGLISTOPS "LOG: Add back, move number: %d, info saved in node\n"
#else
#define LOGLISTOPS ""
#endif

void move(int towerorg, int towerdest,stack *list, int depth);
void hanoi(int nd, int torg, int tdest, int taux, stack *list);
void hanoiprint(node_t *newnode, int numdisks);

#endif /* MAIN_H */
