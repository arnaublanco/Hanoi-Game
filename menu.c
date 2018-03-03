/*Created by; Gabriel Graells Solé
 * This functions has the menu option of the differents functions of the email
 */
#include "menu.h"


void play_game()
{
   
}

void show_game()
{
  
}
void menu_directory()
{
    int option = menu_display();
    while (option != 0)
    {
        switch(option)
        {
            case PLAYGAME: 
                    play_game();
                    break;
                case SHOWGAME: 
                    show_game();
                    break;
                    printf("Please enter a letter to continue\n");
            default:
                printf("Invalid option\n");
                break;
        } 
     option = menu_display();   
    }
    printf("Please enter a letter to continue\n");
}



int menu_display()
{
    int option;
    printf("___________________________________________________________________________\n");
    printf("___________________________________________________________________________\n");
    printf("1-Play Hanoi Tower\n");
    printf("2-See Hanoi Tower Solution\n");
    printf("0-Quit\n");
          
   
    printf("\nSelect option: ");
    scanf("%d", &option);
    printf("___________________________________________________________________________\n");
    printf("___________________________________________________________________________\n");
    return option;
}

int main()
{
    menu_directory();
    return 0;
}