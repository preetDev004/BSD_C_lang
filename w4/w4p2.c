// **********************************************************************************************
//   <assessment name example: Workshop - #4 (Part-2)>

// Authenticity Declaration :
// I declare this submission is the result of my own work and has not been shared with any other student or 3rd party content provider. This submitted piece of work is entierly of my own creation.

// **********************************************************************************************
#include <stdio.h>
int main()
{
    int nApplesNeed, nOrangesNeed, nPearsNeed, nTomatoesNeed, nCabbagesNeed,
        nApplesPick, nOrangesPick, nPearsPick, nTomatoesPick, nCabbagesPick, shopping = 1;

    while (shopping)
    {
        printf("Grocery Shopping\n");
        printf("================\n");
        do
        {
            printf("How many APPLES do you need? : ");
            scanf("%d", &nApplesNeed);
            if (nApplesNeed < 0)
                printf("ERROR: Value must be 0 or more.\n");
        } while (nApplesNeed < 0);
        printf("\n");
        do
        {
            printf("How many ORANGES do you need? : ");
            scanf("%d", &nOrangesNeed);
            if (nOrangesNeed < 0)
                printf("ERROR: Value must be 0 or more.\n");
        } while (nOrangesNeed < 0);
        printf("\n");
        do
        {
            printf("How many PEARS do you need? : ");
            scanf("%d", &nPearsNeed);
            if (nPearsNeed < 0)
                printf("ERROR: Value must be 0 or more.\n");
        } while (nPearsNeed < 0);
        printf("\n");
        do
        {
            printf("How many TOMATOES do you need? : ");
            scanf("%d", &nTomatoesNeed);
            if (nTomatoesNeed < 0)
                printf("ERROR: Value must be 0 or more.\n");
        } while (nTomatoesNeed < 0);
        printf("\n");
        do
        {
            printf("How many CABBAGES do you need? : ");
            scanf("%d", &nCabbagesNeed);
            if (nCabbagesNeed < 0)
                printf("ERROR: Value must be 0 or more.\n");
        } while (nCabbagesNeed < 0);
        printf("\n");

        printf("--------------------------\n");
        printf("Time to pick the products!\n");
        printf("--------------------------\n\n");

        if (nApplesNeed != 0)
        {
            do
            {
                printf("Pick some APPLES... how many did you pick? : ");
                scanf("%d", &nApplesPick);
                if (nApplesPick > nApplesNeed)
                    printf("You picked too many... only %d more APPLE(S) are needed.\n", nApplesNeed);
                else if (nApplesPick <= 0)
                    printf("ERROR: You must pick at least 1!\n");
                else
                {
                    nApplesNeed -= nApplesPick;
                    if (nApplesNeed != 0)
                        printf("Looks like we still need some APPLES...\n");
                    else
                        printf("Great, that's the apples done!\n\n");
                      
                }

            } while (nApplesNeed != 0);
        }
        if (nOrangesNeed != 0)
        {
            do
            {
                printf("Pick some ORANGES... how many did you pick? : ");
                scanf("%d", &nOrangesPick);
                if (nOrangesPick > nOrangesNeed)
                    printf("You picked too many... only %d more ORANGE(S) are needed.\n", nOrangesNeed);
                else if (nOrangesPick <= 0)
                    printf("ERROR: You must pick at least 1!\n");
                else
                {
                    nOrangesNeed -= nOrangesPick;
                    if (nOrangesNeed != 0)
                        printf("Looks like we still need some ORANGES...\n");
                    else
                        printf("Great, that's the oranges done!\n\n");
                      
                }

            } while (nOrangesNeed != 0);
        }
        if (nPearsNeed != 0)
        {
            do
            {
                printf("Pick some PEARS... how many did you pick? : ");
                scanf("%d", &nPearsPick);
                if (nPearsPick > nPearsNeed)
                    printf("You picked too many... only %d more PEAR(S) are needed.\n", nPearsNeed);
                else if (nPearsPick <= 0)
                    printf("ERROR: You must pick at least 1!\n");
                else
                {
                    nPearsNeed -= nPearsPick;
                    if (nPearsNeed != 0)
                        printf("Looks like we still need some PEARS...\n");
                    else
                        printf("Great, that's the pears done!\n\n");
                      
                }

            } while (nPearsNeed != 0);
        }
        if (nTomatoesNeed != 0)
        {
            do
            {
                printf("Pick some TOMATOES... how many did you pick? : ");
                scanf("%d", &nTomatoesPick);
                if (nTomatoesPick > nTomatoesNeed)
                    printf("You picked too many... only %d more TOMATO(ES) are needed.\n", nTomatoesNeed);
                else if (nTomatoesPick <= 0)
                    printf("ERROR: You must pick at least 1!\n");
                else
                {
                    nTomatoesNeed -= nTomatoesPick;
                    if (nTomatoesNeed != 0)
                        printf("Looks like we still need some TOMATOES...\n");
                    else
                        printf("Great, that's the tomatoes done!\n\n");         
                }

            } while (nTomatoesNeed != 0);
        }
        if (nCabbagesNeed != 0)
        {
            do
            {
                printf("Pick some CABBAGES... how many did you pick? : ");
                scanf("%d", &nCabbagesPick);
                if (nCabbagesPick > nCabbagesNeed)
                    printf("You picked too many... only %d more CABBAGE(S) are needed.\n", nCabbagesNeed);
                else if (nCabbagesPick <= 0)
                    printf("ERROR: You must pick at least 1!\n");
                else
                {
                    nCabbagesNeed -= nCabbagesPick;
                    if (nCabbagesNeed != 0)
                        printf("Looks like we still need some CABBAGES...\n");
                    else
                        printf("Great, that's the cabbages done!\n\n");
                        
                }

            } while (nCabbagesNeed != 0);
        }

        printf("All the items are picked!\n\n");
        printf("Do another shopping? (0=NO): ");
        scanf("%d", &shopping);
        printf("\n");
    }
    printf("Your tasks are done for today - enjoy your free time!\n");

    return 0;
}