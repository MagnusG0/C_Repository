#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
    int playercard1, playercard2, playertotal = 0, dealercard1, dealercard2, dealertotal = 0; // initialising variables

    srand(time(NULL));
    printf("Welcome to BlackJack!\n");
    // player code
    playercard1 = (rand() % 11) + 1;
    playercard2 = (rand() % 11) + 1;

    printf("Your Cards: %d %d\n", playercard1, playercard2);
    playertotal = playercard1 + playercard2;
    printf("Your total: %d\n", playertotal);

    while (playertotal <= 21)
    {
        char move;
        printf("Twist (t) or Stick (s)? \n");
        scanf("%c", &move);

        if (move == 't')
        {
            playertotal = playertotal + ((rand() % 11) + 1);

            printf("Player Total: %d\n", playertotal);
        }

        if (playertotal > 21)
        {
            printf("You Bust!\n");
            break;
        }
        else if (move == 's')
        {
            printf("You choose to Stick\n");
            break;
        }
        else
        {
            printf("Invalid input, please try again.\n");
        }

        // if (playertotal == 21)
        // {
        //     printf("Natural Blackjack!\n");
        // }
    }

    // dealer code
    dealercard1 = (rand() % 11) + 1;
    dealercard2 = (rand() % 11) + 1;

    printf("Dealer's Cards: %d %d\n", dealercard1, dealercard2);

    dealertotal = dealercard1 + dealercard2;

    printf("Dealer's Total: %d\n", dealertotal);

    // int dealerchoice = (rand() % 2) + 1;

    while (dealertotal < 17)
    {

        dealertotal = dealertotal + ((rand() % 11) + 1);
        Sleep(1000);
        printf("%d\n", dealertotal);

        if (dealertotal > 21)
        {
            printf("Dealer Bust!\n");
            break;
        }
    }
    // win conditions
    // if ((playertotal <= 21) && (playertotal > dealertotal))
    // {
    //     printf("Player Wins!\n"); // test
    // }
    // else if ((dealertotal > playertotal) && (dealertotal <= 21))
    // {
    //     printf("Dealer Wins!\n");
    // }
    // else if (dealertotal > 21)
    // {
    //     printf("Player Wins!\n");
    // }
    // else if (playertotal > 21)
    //  {
    //     printf("Dealer Wins!\n");
    // }
    //  else if (playertotal = dealertotal)
    // {
    //      printf("It's a draw!\n");
    // }
    //  else if ((playertotal && dealertotal) > 21)
    // {
    //      printf("Nobody Wins!\n");
    // }
    //  else
    // {
    //      printf("Something broke! Get out of my Casino!");
    // }
    switch (playertotal)
    {
    case ((playertotal <= 21) && (playertotal > dealertotal)):
        printf("Player Wins!\n");
        break;
    case ((dealertotal > playertotal) && (dealertotal <= 21)):
        printf("Dealer Wins!\n");
        break;
    case (dealertotal > 21):
        printf("Player Wins!\n");
        break;
    case (playertotal > 21):
        printf("Dealer Wins!\n");
        break;
    case (playertotal = dealertotal):
        printf("It's a draw!\n");
        break;
    case ((playertotal > 21) && (dealertotal > 21)):
        printf("Nobody Wins!\n");
        break;
    default:
        printf("Something broke! Get out of my Casino!");
    }
}
