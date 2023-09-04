// **********************************************************************************************
//   <assessment name example: Workshop - #7 (Part-2)>

// Authenticity Declaration :
// I declare this submission is the result of my own work and has not been shared with any other student or 3rd party content provider. This submitted piece of work is entierly of my own creation.

// **********************************************************************************************

#include <stdio.h>
#define MAX_PATH_LENGTH 70

struct Playerinfo
{
    // required variables said in the work shop instruction
    int nLives, nTreasuresFound;
    int pastMoves[MAX_PATH_LENGTH];
    char nickName;
};

struct Gameinfo
{
    // required variables said in the work shop instruction
    int nMoves, pathLength;
    int positionOfBombs[MAX_PATH_LENGTH], positionOfTreasures[MAX_PATH_LENGTH];
};

int main()
{
    int i,j, flag = 1, movesAllowed, move;
    char whatFound[MAX_PATH_LENGTH] = {' '};
    struct Playerinfo player = {0};
    struct Gameinfo game;

    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n\n");

    printf("PLAYER Configuration\n");
    printf("--------------------\n");

    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player.nickName);

    do
    {
        printf("Set the number of lives: ");
        scanf("%d", &player.nLives);
        if (player.nLives < 1 || player.nLives > 10)
        {
            printf("     Must be between 1 and 10!\n");
        }

    } while (player.nLives < 1 || player.nLives > 10);

    printf("Player configuration set-up is complete\n\n");

    printf("GAME Configuration\n");
    printf("------------------\n");

    do
    {
        printf("Set the path length (a multiple of 5 between 10-70): ");
        scanf("%d", &game.pathLength);
        if ((game.pathLength < 10 || game.pathLength > 70) || game.pathLength % 5 != 0)
        {
            printf("     Must be a multiple of 5 and between 10-70!!!\n");
        }

    } while ((game.pathLength < 10 || game.pathLength > 70) || game.pathLength % 5 != 0);
    do
    {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &game.nMoves);
        if (game.nMoves < player.nLives || game.nMoves > ((game.pathLength * 75) / 100))
        {
            printf("    Value must be between %d and %d\n", player.nLives, (game.pathLength * 75) / 100);
        }

    } while (game.nMoves < player.nLives || game.nMoves > ((game.pathLength * 75) / 100));
    movesAllowed = game.nMoves;

    printf("\nBOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of 5 where a value\nof 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);
    for (i = 0; i < game.pathLength; i += 5)
    {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        scanf("%d %d %d %d %d", &game.positionOfBombs[i], &game.positionOfBombs[i + 1], &game.positionOfBombs[i + 2],
              &game.positionOfBombs[i + 3], &game.positionOfBombs[i + 4]);
    }
    printf("BOMB placement set\n\n");

    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of 5 where a value\nof 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);
    for (i = 0; i < game.pathLength; i += 5)
    {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        scanf("%d %d %d %d %d", &game.positionOfTreasures[i], &game.positionOfTreasures[i + 1], &game.positionOfTreasures[i + 2],
              &game.positionOfTreasures[i + 3], &game.positionOfTreasures[i + 4]);
    }
    printf("TREASURE placement set\n\n");
    printf("GAME configuration set-up is complete...\n\n");

    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    printf("Player:\n");
    printf("   Symbol     : %c\n", player.nickName);
    printf("   Lives      : %d\n", player.nLives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n\n");

    printf("Game:\n");
    printf("   Path Length: %d\n", game.pathLength);
    printf("   Bombs      : ");
    for (i = 0; i < game.pathLength; i++)
    {
        printf("%d", game.positionOfBombs[i]);
    }
    printf("\n   Treasure   : ");
    for (i = 0; i < game.pathLength; i++)
    {
        printf("%d", game.positionOfTreasures[i]);
    }
    printf("\n\n====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");

    while (flag){
        if (movesAllowed != game.nMoves)
        {
            printf("\n ");
            for (i = 0; i < game.pathLength; i++)
            {
                if (i == move-1)
                {
                    for ( j = 0; j <= i; j++)
                    {
                         printf(" ");
                    }
                    
                    printf("V");
                }
               
                
            }
        }
        printf("\n  ");
        for ( i = 0; i < game.pathLength; i++)
        {
            if (whatFound[i] == '!' || whatFound[i] == '.' || whatFound[i] == '$' || whatFound[i] == '&' ){
                printf("%c",whatFound[i]);
            }
            else{
                printf("-");
            }
        }
        printf("\n  ");
        for ( i = 0; i < game.pathLength; i++)
        {
            if ((i+1)%10 == 0)
            {
                printf("%d", (i+1)/10);
            }
            else{
                printf("|");
            }
            
        }
        printf("\n  ");
        for ( i = 0; i < game.pathLength; i++)
        {
            if ((i+1)%10 == 0)
            {
                printf("0");
            }
            else{
                printf("%d",(i+1)%10);
            }
            
        }
        printf("\n");
        printf("+---------------------------------------------------+\n");
        printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n",player.nLives,player.nTreasuresFound,game.nMoves);
        printf("+---------------------------------------------------+\n");
        
        if (player.nLives == 0 || game.nMoves ==0)
        {
            flag = 0;
            continue;
        }
        

        do
        {
           printf("Next Move [1-%d]: ",game.pathLength);
           scanf("%d", &move);
           if (move > game.pathLength || move < 1)
           {
            printf("  Out of Range!!!\n");
           }
        } while ((move > game.pathLength || move < 1));
        printf("\n");

        if (player.pastMoves[move-1])
        {
            printf("===============> Dope! You've been here before!\n");
        }
        else if (game.positionOfBombs[move-1] && game.positionOfTreasures[move-1])
        {
            printf("===============> [&] !!! BOOOOOM !!! [&]\n");
            printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n");
            player.pastMoves[move-1] = 1;
            player.nLives -=1;
            game.nMoves -= 1;
            player.nTreasuresFound +=1;
            whatFound[move-1]='&';
        }
        else if (game.positionOfBombs[move-1])
        {
            printf("===============> [!] !!! BOOOOOM !!! [!]\n");
            player.pastMoves[move-1] = 1;
            player.nLives -=1;
            game.nMoves -= 1;
            whatFound[move-1]='!';
        }
        else if (game.positionOfTreasures[move-1])
        {
            printf("===============> [$] $$$ Found Treasure! $$$ [$]\n");
            player.pastMoves[move-1] = 1;
            game.nMoves -= 1;
             player.nTreasuresFound +=1;
            whatFound[move-1]='$';
        }
        else
        {
           printf("===============> [.] ...Nothing found here... [.]\n");
           player.pastMoves[move-1] = 1;
           game.nMoves -= 1;
           whatFound[move-1]='.';
        }

        
        if (player.nLives == 0)
        {
            printf("\nNo more LIVES remaining!\n");
        }
        else if (game.nMoves==0)
        {
           printf("\nNo more LIVES remaining!\n");
        }
        
        
    }
    printf("\n##################\n");
    printf("#   Game over!   #\n");
    printf("##################\n");

    printf("\nYou should play again and try to beat your score!\n");

    return 0;
}