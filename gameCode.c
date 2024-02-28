#include <stdio.h>
#include <time.h>
#include <windows.h>

int main()
{
    int playercard1, playercard2, playertotal, dealercard1, dealercard2, dealertotal; // initialising variables
    char move;

    srand(time(NULL));

    // player code
    playercard1 = (rand() % 11) + 1;
    playercard2 = (rand() % 11) + 1;

    printf("%d %d\n", playercard1, playercard2);
    playertotal = playercard1 + playercard2;
    printf("%d\n", playertotal);

    while (move != "s")
    {
        printf("Twist (t) or Stick (s)?\n");
        scanf("%c", &move);

        if (move == "t")
        {
            playertotal = playertotal + ((rand() % 11) + 1);
            printf("%d\n", playertotal);
        }
        else
            break;
    }

    if (playertotal > 21)
    {
        printf("%d \nYou Lose!", playertotal);
    }

    // dealer code
    dealercard1 = (rand() % 11) + 1;
    dealercard2 = (rand() % 11) + 1;

    printf("%d %d\n", dealercard1, dealercard2);
    dealertotal = dealercard1 + dealercard2;
    printf("%d\n", dealertotal);

    int dealerchoice = (rand() % 2) + 1;
    while (dealerchoice != 2)
    {

        if (dealerchoice == 1)
        {
            dealertotal = dealercard1 + ((rand() % 11) + 1);
            Sleep(1000);
            printf("%d\n", dealertotal);
        }
        else
        {
            break;
            printf(dealertotal);
        }
    }

    // winning code

    if ((playertotal <= 21) && (playertotal > dealertotal))
    {
        printf("You Win!");
    }
    else if (dealertotal > playertotal)
    {
        printf("Dealer Wins!");
    }
    else if (playertotal = dealertotal)
    {
        printf("Draw - Nobody wins!");
    }
}
