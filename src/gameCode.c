#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
    int playercard1,
        playercard2,
        playertotal = 0,
        dealercard1,
        dealercard2,
        dealertotal = 0; // initialising variables

    srand(time(NULL));
    printf("Welcome to BlackJack!\n");

    // player code
    playercard1 = (rand() % 11) + 1; // playercard is assigned a random integer variable between 1 & 11
    playercard2 = (rand() % 11) + 1;

    printf("Your Cards: %d %d\n", playercard1, playercard2);
    playertotal = playercard1 + playercard2; // blackjack works by taking the total of two cards - here the players two cards
    printf("Your total: %d\n", playertotal); // added together to get the total player value

    while (playertotal <= 21) // now onto the game phase.
    {
        char move;
        printf("Twist (t) or Stick (s)? \n"); // Player is asked whether they want to draw another card (Twist), or Stick with the
        scanf(" %c", &move);                  // two cards they were assigned as their total.

        if (move == 't')
        {
            playertotal = playertotal + ((rand() % 11) + 1);

            printf("Player Total: %d\n", playertotal);
        }
        else if (move == 's')
        {
            printf("You choose to Stick\n");
            break;
        }
        else
        {
            printf("Invalid input, please try again.\n"); // An invalid format checker - if player inputs anything other than "t" or "s"
        }                                                 // this clasue will run and the loop will loop again.

        if (playertotal == 21)
        {
            printf("Natural Blackjack!\n");
            break;
        }
        else if (playertotal > 21)
        {
            printf("You Bust!\n");
            break;
        }
    }

    // dealer code
    dealercard1 = (rand() % 11) + 1; // Similar to playerCard1/2
    dealercard2 = (rand() % 11) + 1;

    printf("Dealer's Cards: %d %d\n", dealercard1, dealercard2);
    dealertotal = dealercard1 + dealercard2;
    printf("Dealer's Total: %d\n", dealertotal);

    while (dealertotal < 17) // In blackjack, it is common for the dealer to draw a card (twist) whilst their total
    {                        // is less than 17. This means the dealer will keep drawing cards whilst the total is under 17.
                             // This doesn't make it unfair for the dealer however, it still has a good chance at winning.

        dealertotal = dealertotal + ((rand() % 11) + 1);
        Sleep(2000); // Added a sleep function to wait between dealers card being revealed - adds to tension of the game.
        printf("%d\n", dealertotal);

        if (dealertotal > 21)
        {
            printf("Dealer Bust!\n");
            break;
        }
    }

    // win conditions
    if ((playertotal <= 21) && (playertotal > dealertotal)) // I tried to make a switch statement for the final win conditions
    {                                                       // but there is too many differentiables and too many combinations.
        printf("Player Wins!\n");
    }
    else if ((dealertotal > playertotal) && (dealertotal <= 21))
    {
        printf("Dealer Wins!\n");
    }
    else if ((playertotal > 21) && (dealertotal > 21))
    {
        printf("Nobody Wins!\n");
    }
    else if (dealertotal > 21)
    {
        printf("Player Wins!\n");
    }
    else if (playertotal > 21)
    {
        printf("Dealer Wins!\n");
    }
    else if (playertotal = dealertotal)
    {
        printf("It's a draw!\n");
    }
    else
    {
        printf("Something broke! Get out of my Casino!");
    }
}
