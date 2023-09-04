// **********************************************************************************************
//   <assessment name example: Workshop - #6 (Part-2)>

// Authenticity Declaration :
// I declare this submission is the result of my own work and has not been shared with any other student or 3rd party content provider. This submitted piece of work is entierly of my own creation.

// **

#include <stdio.h>
#define MAX_FORECAST 10
int main()
{
    int nItemsForcast, importance, i, j, howForcast, exitFlag = 1, years, showByimp;
    char financeOption;
    const double minIncome = 500.00, maxIncome = 400000.00, minItemValue = 100.00;
    double income, itemValue, months, totalCost = 0, priorityCost = 0;

    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n\n");

    do
    {
        printf("Enter your monthly NET income: $");
        scanf("%lf", &income);

        if (income < minIncome)
        {
            printf("ERROR: You must have a consistent monthly income of at least $%.2lf\n\n", minIncome);
        }
        else if (income > maxIncome)
        {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $%.2lf\n\n", maxIncome);
        }
        else
            printf("\n");

    } while (income < minIncome || income > maxIncome);

    do
    {
        printf("How many wish list items do you want to forecast?: ");
        scanf("%d", &nItemsForcast);

        if (nItemsForcast > MAX_FORECAST || nItemsForcast < 1)
        {
            printf("ERROR: List is restricted to between 1 and 10 items.\n\n");
        }
        else
            printf("\n");
    } while (nItemsForcast > MAX_FORECAST || nItemsForcast < 1);
    int imp[nItemsForcast];
    char fOptions[nItemsForcast];
    double itemCosts[nItemsForcast];
    for (i = 0; i < nItemsForcast; i++)
    {

        printf("Item-%d Details:\n", i + 1);
        do
        {
            printf("   Item cost: $");
            scanf("%lf", &itemValue);
            if (itemValue < minItemValue)
            {
                printf("      ERROR: Cost must be at least $%.2lf\n", minItemValue);
            }
            else
            {
                do
                {
                    printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
                    scanf("%d", &importance);
                    if (importance < 1 || importance > 3)
                    {
                        printf("      ERROR: Value must be between 1 and 3\n");
                    }
                    else
                    {
                        do
                        {
                            printf("   Does this item have financing options? [y/n]: ");
                            scanf(" %c", &financeOption);

                            if (financeOption != 'y' && financeOption != 'n')
                            {
                                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
                            }
                            else
                            {
                                printf("\n");
                                itemCosts[i] = itemValue;
                                imp[i] = importance;
                                fOptions[i] = financeOption;
                            }

                        } while (financeOption != 'y' && financeOption != 'n');
                    }

                } while (importance < 1 || importance > 3);
            }

        } while (itemValue < minItemValue);
    }

    printf("Item Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");
    for (i = 0; i < nItemsForcast; i++)
    {
        printf("%3d  %5d    %5c    %11.2lf\n", i + 1, imp[i], fOptions[i], itemCosts[i]);
        totalCost += itemCosts[i];
    }

    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n\n", totalCost);

    while (exitFlag)
    {
        do
        {
            printf("How do you want to forecast your wish list?\n");
            printf(" 1. All items (no filter)\n");
            printf(" 2. By priority\n");
            printf(" 0. Quit/Exit\n");
            printf("Selection: ");
            scanf("%d", &howForcast);
            if (howForcast < 0 || howForcast > 2)
            {
                printf("\nERROR: Invalid menu selection.\n\n");
            }
        } while (howForcast < 0 || howForcast > 2);

        if (howForcast == 0)
        {
            exitFlag = 0;
        }
        else if (howForcast == 1)
        {
            printf("\n====================================================\n");
            years = (totalCost / income) / 12;
            months = ((totalCost / income)) - years * 12;
            printf("Filter:   All items\n");
            printf("Amount:   $%1.2lf\n", totalCost);
            printf("Forecast: %d years, %d months\n", years, (int)months + 1);
            for (i = 0; i < nItemsForcast; i++)
            {
                if (fOptions[i] == 'y')
                {
                    printf("NOTE: Financing options are available on some items.\n");
                    printf("      You can likely reduce the estimated months.\n");
                    i += nItemsForcast;
                }
            }
            printf("====================================================\n\n");
        }
        else if (howForcast == 2)
        {

            do
            {
                printf("\nWhat priority do you want to filter by? [1-3]: ");
                scanf("%d", &showByimp);
                if (showByimp < 1 || showByimp > 3)
                {
                    printf("\nERROR: Value must be between 1 and 3.\n");
                }
                else
                {
                    for (j = 0; j < nItemsForcast; j++)
                    {
                        if (imp[j] == showByimp)
                        {
                            priorityCost += itemCosts[j];
                        }
                    }
                    years = ((priorityCost / income) / 12);
                    months = ((priorityCost / income) - years * 12);
                    printf("\n====================================================\n");
                    printf("Filter:   by priority (%d)\n", showByimp);
                    printf("Amount:   $%1.2lf\n", priorityCost);
                    printf("Forecast: %d years, %d months\n", years, (int)months + 1);
                    priorityCost = 0;
                    for (i = 0; i < nItemsForcast; i++)
                    {
                        if (fOptions[i] == 'y')
                        {
                            printf("NOTE: Financing options are available on some items.\n");
                            printf("      You can likely reduce the estimated months.\n");
                            i += nItemsForcast;
                        }
                    }
                    printf("====================================================\n\n");
                }

            } while (showByimp < 1 || showByimp > 3);
        }
    }
    printf("\nBest of luck in all your future endeavours!\n");

    return 0;
}