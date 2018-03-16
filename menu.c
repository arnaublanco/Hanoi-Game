/*Created by; Gabriel Graells Solé, Asfandyar Abbasi and Arnau Blanco
 * This functions has the menu option of the different functions of the email
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "menu.h"
#include "playgame.h"
#include "main.h"

void play_game(stack *l)
{
    /*COUNTER INSIDE A LOOP*/
    while(end_game(l) != 1)
    {
        playgame_directory(l);
    }
}
/*FUNCTION THAT EXECUTES THE hanoiplus COMMAND*/
void command(char **argv, int argc, stack *list){
    int option = 1;
    int i = 0;
    while(i < argc){
        if(argv[i][0] == '-' && argv [i][1] == 'd' && argv[i+1]){
            list->disk = atoi(argv[i+1]);
        }
        if(argv[i][0] == '-' && argv [i][1] == 'f' && argv[i+1]){
            strcpy(list->fname,argv[i+1]);
            option = 0;
        }
        if(argv[i][0] == '-' && argv [i][1] == 'o' && argv[i+1]){
            strlcpy(list->operation,argv[i+1],MAX_FIELD);
        }
        i++;
    }
    //By default, fname is hanoiplus-<ndisks>d
    if(option==1){
        char *aux;
        sprintf(aux,"%s-%dd",HPLUS,list->disk);
        strlcpy(list->fname,aux,MAX_FIELD);
    }
}

void create_file(stack *list){
    FILE *f; //Declare the file
    char path[MAX_FIELD]; //Declaration of the path of the file
    sprintf(path,"%s%s",list->fname,".txt"); //path = name.txt (THIS IS NOT WORKING)
    //If new_file is true, then create a new file or overwrite it. Otherwise, append the content at the end of it.
    if(strcmp(list->operation,"w")==0){
        f = fopen(path,"w"); //Open file with given name
    }else if(strcmp(list->operation,"ap")==0){
        f = fopen(path,"a"); //Append file with given name
    }
    //Check if the file has been opened correctly
    if(f==NULL){
        printf("Error while creating the file.");
        exit(0);
    }
    fprintf(f,"%s%s",LINE,NEWLINE);
    fprintf(f,"Number of Towers: %d\n",NTOWERS);
    fprintf(f,"Number of Discs: %d\n",list->disk);
    fprintf(f,"Output filename: %s\n",list->fname);
    fprintf(f,"File operation: %s\n\n",list->operation);
    fprintf(f,"Total number of moves: %d\n",list->num);
    time_t rawtime;
  struct tm * timeinfo;

  time ( &rawtime );
  timeinfo = localtime ( &rawtime );
  printf ( "Current local time and date: %s", asctime (timeinfo) );

    //fprintf(f,"Total number of moves: %s\n",t);    
    for(int c=0; c<=list->num; c++){
        int m;
        node_t *cnode;
        cnode= list->top;
        for(m=list->num; m>c; m--){
            cnode = cnode->prev;
        }
        file_print(list,f,cnode);
    }
    fclose(f);
}

void file_print(stack *list, FILE *f, node_t *cnode){
    /*LOOP THAT WILL PRINT ALL THE MOVES IN THE FILE*/
    printf("move from %d to %d",cnode->torg,cnode->tdest);
    int dots, bars=0;
       //hanoiprint(list->top,list->disks);
       for(int i=0; i<list->disk; i++){
        for(int k=0; k<NTOWERS; k++){
           bars = cnode->matrix[i][k]; //Declaration of the value in position k i in the matrix
           dots=list->disk-bars;
           /*PRINT DOT number of disks-mat TIMES*/ 
           for(int j=0; j<dots; j++)
                fprintf(f,"%s",".");
           
           /*PRINT UNDERSCORE mat TIMES*/
           for(int j=0; j<bars; j++)
                fprintf(f,"%s","-");
           
           /*PRINT VERTICAL BAR*/
           fprintf(f,"%s","|");
           
              /*PRINT UNDERSCORE mat TIMES*/
            for(int j=0; j<bars; j++)
                fprintf(f,"%s","-");
           
           /*PRINT DOT umber of disks-mat TIMES*/
            for(int j=0; j<dots; j++)
                fprintf(f,"%s",".");
           
        
           
           //If it's not printing the last tower, then print a tabspace
           if(k<NTOWERS){
               fprintf(f,"%s","\t");
           }else{
               fprintf(f,"%s","\n");
           }
        }
       fprintf(f,"%s","\n"); 
    } 
    fprintf(f,"%s","\n");
}
int display_menu()
{
    int option;
    printf("\nMenu Options.\n"
            "1.Show Hanoi solution. Type 1.\n"
            "2.Play Hanoi. Type 2.\n"
            "0.Exit. Type 0.\n\n"
            "Option: ");
    scanf("%d", &option);
    return option;
}

void menu_directory(stack *l)
{
    int option;
    option = display_menu();
    
    while (option != 0)
    {
        switch(option)
        {
            case OPTION_1:
                show_game(l);
                break;
            case OPTION_2:
                play_game(l);
                break;
            default:
                printf("\nInvalid option.\n");
                break;
        }
        option = display_menu();
    }
}
/*FUNCTION THAT SHOWS A MOVE ON-SCREEN*/
void show_game(stack *l){
    int move; //Declare move which stores the input of the user
    node_t *current_node = l->top; //Create a node that points to the last node
    printf("%sType the number of the move you want to see: ",NEWLINE);
    scanf("%d",&move); //Scan user's input
    //If the user's input is not valid, then print a warning message
    if(move >= 0 && move <= l->num){
        //Loop to jump from one node to another
        for(int m=l->num; m>move; m--){
            current_node = current_node->prev;
        }
        hanoiprint(current_node,l->disk); //Print the move
    }else{
        printf("This move does not exist.%s",NEWLINE);
    }
}