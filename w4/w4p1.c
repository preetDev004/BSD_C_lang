// **********************************************************************************************
//   <assessment name example: Workshop - #4 (Part-1)>

// Authenticity Declaration :
// I declare this submission is the result of my own work and has not been shared with any other student or 3rd party content provider. This submitted piece of work is entierly of my own creation.

// **********************************************************************************************

#include <stdio.h>
int main()
{
    char loopType;
    int nIteration, nPrints = 1;
    printf("+----------------------+\n");
    printf("Loop application STARTED\n");
    printf("+----------------------+\n");

    while (nPrints)
    {
        printf("\n");
        printf("D = do/while | W = while | F = for | Q = quit\n");
        printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
        scanf(" %c%d", &loopType, &nIteration);

        switch (loopType)
        {
            case 'W':
                if (nIteration >= 3 && nIteration <= 20)
                {
                    printf("WHILE   : ");
                    while (nPrints <= nIteration)
                    {
                        printf("W");
                        nPrints++;
                    }
                    printf("\n");
                    nPrints = 1;
                } else{
                    printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
                }
                break;

            case 'D':
                if (nIteration >= 3 && nIteration <= 20)
                {
                    printf("DO-WHILE: ");
                    while (nPrints <= nIteration)
                    {
                        printf("D");
                        nPrints++;
                    }
                    printf("\n");
                    nPrints = 1;
                } else{
                    printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
                }
                break;

            case 'F':
                if (nIteration >= 3 && nIteration <= 20)
                {
                    printf("FOR     : ");
                    while (nPrints <= nIteration)
                    {
                        printf("F");
                        nPrints++;
                    }
                    printf("\n");
                    nPrints = 1;
                } else{
                    printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
                }
                break;

            case 'Q':
                if (nIteration == 0)
                {
                    printf("\n+--------------------+\n");
                    printf("Loop application ENDED\n");
                    printf("+--------------------+\n");
                    nPrints = 0;
                } else{  
                      printf("ERROR: To quit, the number of iterations should be 0!\n");
                
                }
                break;

            default:
                printf("ERROR: Invalid entered value(s)!\n");
                break;
        }

    }

    return 0;
}