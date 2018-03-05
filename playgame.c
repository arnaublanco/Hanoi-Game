#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "database.h"
#include "main.h"
#include "playgame.h"


/*1.Ask number of discs
 *1.1 print init
 2.ask moves*/

void interactive_disc(stack *l)
{
    printf("Enter the number of disc you would like to play with: ");
    scanf("%d", l->num);
}

