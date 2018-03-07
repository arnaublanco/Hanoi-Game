#ifndef MAIN_H
#define MAIN_H

#include "database.h"

#define NTOWERS 3  //Declaration of the number of towers
#define NDISKS 5 //Declaration of default number of disks
#define VERT_BAR "|" //Declaration of a vertical bar
#define UNDERSC "_" //Declaration of an underscore
#define DOT "." //Declaration of a dot
#define TABSPACE "\t" //Declaration of tabulation space

void move(int depth,int towerorg, int towerdest,Database *db);
void hanoi(int nd, int torg, int tdest, int taux, Database *db);
void hanoiprint(Database *db,int torg,int tdest,int depth);

#endif /* MAIN_H */

