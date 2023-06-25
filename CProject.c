#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

char box[10] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
int x;

void headmsg();
int mainmenu();
int tictactoe(int z);
void board();
int checkwin();
void tictactoemenu();
void tictactoerules();
int guessthenumber();
void guess(int n);
void guessthenumberrules();
void guessthenumbermenu();

int main()
{
    int a;
    printf("\033[1;31m");
    headmsg();
    printf("\033[0m");
    mainmenu();
    
    
}

void headmsg()
{
    printf("\t\t#########################################################################");
    printf("\n\t\t############                    WELCOME                      ############");
    printf("\n\t\t############                      TO                         ############");
    printf("\n\t\t############                  GAMERS ZONE !!                 ############");
    printf("\n\t\t#########################################################################");
    printf("\n\t\t-------------------------------------------------------------------------\n");

}

int mainmenu()
{
    int a,z;
    printf("\n###########################\n");
    printf("List of games:\n");
    printf("\033[1;32m");
    printf("1.Tic Tac Toe\n");
    printf("\033[0m");
    printf("\033[1;32m");
    printf("2.Guess The Number\n\n");
    printf("\033[0m");
    printf("###########################\n");
    printf("Enter '1' to play Tic Tac Toe. \nEnter '2' to play Guess The Number.\nEnter '3' to Exit.\n");
    printf("Please Enter your choice: ");
    scanf("%d",&a);
    if(a==1)
    {
        tictactoe(z);
    }
    else if(a==2)
    {
        guessthenumber();
    }
    else if(a==3)
    {
        printf("\033[1;33m");
        printf("\nThank You!!");
        printf("\033[0m");
    }
    else 
    {
        printf("\033[1;31m");
        printf("### Invalid choice ###\n");
        printf("\033[0m");
        mainmenu();
    }
    return 0;
}

void resetboard()
{
    for(int k=0;k<10;k++)
    {
        box[k]=' ';
    }
}

void board()
{
    printf("\n");
    printf("\t|-----------------|\n");   
    printf("\t|     |     |     |\n");
    printf("\t|  %c  |  %c  |  %c  |\n", box[1], box[2], box[3]);
    printf("\t|_____|_____|_____|\n");
    printf("\t|     |     |     |\n");
    printf("\t|  %c  |  %c  |  %c  |\n", box[4], box[5], box[6]);
    printf("\t|_____|_____|_____|\n");
    printf("\t|     |     |     |\n");
    printf("\t|  %c  |  %c  |  %c  |\n", box[7], box[8], box[9]);
    printf("\t|     |     |     |\n");
    printf("\t|-----------------|\n");
}

int checkwin()
{
    if ((box[1]=='X' && box[2]=='X' && box[3]=='X')||(box[1]=='O' && box[2]=='O' && box[3]=='O'))
        return 1;

    else if ((box[4]=='X' && box[5]=='X' && box[6]=='X')||(box[4]=='O' && box[5]=='O' && box[6]=='O'))
        return 1;

    else if ((box[7]=='X' && box[8]=='X' && box[9]=='X')||(box[7]=='O' && box[8]=='O' && box[9]=='O'))
        return 1;

    else if ((box[1]=='X' && box[4]=='X' && box[7]=='X')||(box[1]=='O' && box[4]=='O' && box[7]=='O'))
        return 1;

    else if ((box[2]=='X' && box[5]=='X' && box[8]=='X')||(box[2]=='O' && box[5]=='O' && box[8]=='O'))
        return 1;

    else if ((box[3]=='X' && box[6]=='X' && box[9]=='X')||(box[3]=='O' && box[6]=='O' && box[9]=='O'))
        return 1;

    else if ((box[1]=='X' && box[5]=='X' && box[9]=='X')||(box[1]=='O' && box[5]=='O' && box[9]=='O'))
        return 1;

    else if ((box[3]=='X' && box[5]=='X' && box[7]=='X')||(box[3]=='O' && box[5]=='O' && box[7]=='O'))
        return 1;

    else if (box[1] != ' ' && box[2] != ' ' && box[3] != ' ' && box[4] != ' ' && box[5] != ' ' && box[6] != ' ' && box[7]!= ' ' && box[8] != ' ' && box[9] != ' ')

        return 0;
    else
        return  - 1;
}
void tictactoerules()
{
    printf("\033[1;33m");
    printf("\nGAME RULES:\n");
    printf("1.The Game is played on a 3X3 grid.\n");
    printf("2.Player 1 is 'X' and Player 2 is 'O'.\n");
    printf("3.Enter the numbers given below to fill that particular box with your mark.\n");
    printf("\t|-----------------|\n");   
    printf("\t|     |     |     |\n");
    printf("\t|  1  |  2  |  3  |\n");
    printf("\t|_____|_____|_____|\n");
    printf("\t|     |     |     |\n");
    printf("\t|  4  |  5  |  6  |\n");
    printf("\t|_____|_____|_____|\n");
    printf("\t|     |     |     |\n");
    printf("\t|  7  |  8  |  9  |\n");
    printf("\t|     |     |     |\n");
    printf("\t|-----------------|\n");
    printf("4.The first Player to get 3 of his/her marks in a row \n  (up,down,across,or diagonally) is the winner.\n");
    printf("5.When all 9 boxes are full, the game is over.\n");
    printf("\033[0m");
}

int tictactoe(int z)
{
    int player = 1, i, choice;
    printf("\n********************************************************************\n");
    printf("\033[1;32m");
    printf("\t\t\tTIC TAC TOE\n");
    printf("\033[0m");
    printf("\n********************************************************************\n");
    tictactoerules();
    printf("\n********************************************************************\n");
    resetboard();
    char mark;
    do
    {
        board();
        if(player%2)
        {
            player=1;
        }
        else
        {
            player=2;
        }

        printf("\nPlayer %d:\nPlease enter your choice: ", player);
        scanf("%d", &choice);
        
        if(player==1)
        {
            mark='X';
        }
        else
        {
            mark='O';
        }

        if (choice == 1 && box[1] == ' ')
            box[1] = mark;

        else if (choice == 2 && box[2] == ' ')
            box[2] = mark;

        else if (choice == 3 && box[3] == ' ')
            box[3] = mark;

        else if (choice == 4 && box[4] == ' ')
            box[4] = mark;

        else if (choice == 5 && box[5] == ' ')
            box[5] = mark;

        else if (choice == 6 && box[6] == ' ')
            box[6] = mark;

        else if (choice == 7 && box[7] == ' ')
            box[7] = mark;

        else if (choice == 8 && box[8] == ' ')
            box[8] = mark;

        else if (choice == 9 && box[9] == ' ')
            box[9] = mark;

        else
        {
            if(choice<1 || choice>9)
            {
                printf("\033[1;31m");
                printf("### Invalid choice ###\n");
                printf("\033[0m");
            }
            else
            {
                printf("\033[1;31m");
                printf("### Box %d is already marked! ###\n",choice);
                printf("\033[0m");
            }
            player--;
            getch();
        }
        i = checkwin();
        
        player++;
    }while (i ==  - 1);

    board();
    printf("\n********************************************************************\n\n");
    if (i == 1)
    {
        printf("\033[1;32m");
        printf("\t\tCongratulations!!\n\tPlayer %d won the game!", --player);
        printf("\033[0m");
    }
    else
    {
        printf("\033[1;31m");
        printf("\t\tOh Dear!!\n\tIt's a Draw!");
        printf("\033[0m");
    }

    getch();
    printf("\n********************************************************************\n\n");
    tictactoemenu();

    return 0;
}

void tictactoemenu()
{
    int z;
    printf("###########################\n");
    printf("Enter '1' to Play again.\n");
    printf("Enter '2' to return to the main menu.\n");
    printf("Enter '3' to Exit.\n");
    printf("Please Enter your choice: ");
    scanf("%d",&x);
    z=x;
    if(z==1)
    {
        tictactoe(z);
    }
    else if(z==2)
    {
        printf("********************************************************************\n\n");
        mainmenu();
    }
    else if(z==3)
    {
        printf("\033[1;33m");
        printf("\nThank You!!");
        printf("\033[0m");
    }
    else 
    {
        printf("\033[1;31m");
        printf("### Invalid choice ###\n");
        printf("\033[0m");
        tictactoemenu();
    }
}

void guessthenumberrules()
{
    printf("\033[0;33m");
    printf("GAME RULES:\n");
    printf("1.You have to guess the number generated by the computer which is \n  between 0 and 100.\n");
    printf("2.You have only 7 chances to guess the number.\n");
    printf("3.If your choice is not in between 0 and 100, then this choice will \n  also be counted.\n");
    printf("4.Hints are given to guess the number.\n");
    printf("\033[0m");
}

void guess(int n)
{
    int r,count=1;
    srand(time(0));
    r=rand()%100 + 1;
    if(n!=r)
    {
        for (int i=1;n!=r&&i<=7;i++)
        {
                
            printf("Turn-%d:\n",i);
            printf("Guess the number:");
            scanf("%d",&n);
            if(n>100||n<0)
            {
                printf("\033[1;31m");
                printf("### Invalid choice ###\n");
                printf("\033[0m");
                count++;
            }
            else if(r>n)
            {
                if(r-n<=2)
                {
                    printf("Ohh Dear!! You Just missed!\n");
                    count++;
                }
                else if(r-n<10&&r-n>2)
                {
                    printf("You are closer! Try higher number!\n");
                    count++;
                }
                else if(r-n>=10)
                {
                    printf("Your number is too low.\n");
                    count++;
                }
            }
            else if(r<n)
            {
                if(n-r<=2)
                {
                    printf("Ohh Dear!! You Just missed!\n");
                    count++;
                }
                else if(n-r<10&&n-r>2)
                {
                    printf("You are closer! Try lesser number!\n");
                    count++;
                }
                else if(n-r>=10)
                {
                    printf("Your number is too high.\n");
                    count++;
                }
            }
        printf("You have %d turns left!\n",7-i);
        printf("--------------------------------------------------------------------\n");
        }
    }

    if(n==r&&count<=7)
    {
        printf("\033[1;32m");
        printf("\t\tCongratulations!!\nYou have guessed the number in %d turns!!",count);
        printf("\033[0m");
    }
    else
    {
        printf("\033[1;31m");
        printf("You have crossed the maximum guessing limit!!\n\t\tBETTER LUCK NEXT TIME!!\n");
        printf("The correct number is %d!",r);
        printf("\033[0m");
    }
    printf("\n********************************************************************\n\n");
    guessthenumbermenu();
    
}
void guessthenumbermenu()
{
    printf("###########################\n");
    printf("Enter '1' to Play again.\n");
    printf("Enter '2' to return to the main menu.\n");
    printf("Enter '3' to Exit.\n");
    printf("Please Enter your choice: ");
    scanf("%d",&x);
    if(x==1)
    {
        guessthenumber();
    }
    else if(x==2)
    {
        printf("********************************************************************\n\n");
        mainmenu();
    }
    else if(x==3)
    {
        printf("\033[1;33m");
        printf("\nThank You!!");
        printf("\033[0m");
    }
    else 
    {
        printf("\033[1;31m");
        printf("### Invalid choice ###\n");
        printf("\033[0m");
        guessthenumbermenu();
    }
}

int guessthenumber()
{
    int n;
    char s[10];
    printf("\n********************************************************************\n");
    printf("\033[1;32m");
    printf("\t\tGUESS THE NUMBER\n\n");
    printf("\033[0m");
    printf("********************************************************************\n\n");
    guessthenumberrules();
    printf("\n********************************************************************\n");
    printf("\n");
    guess(n);
    
    return 0;
}

