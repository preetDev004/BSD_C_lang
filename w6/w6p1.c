// **********************************************************************************************
//   <assessment name example: Workshop - #6 (Part-1)>

// Authenticity Declaration :
// I declare this submission is the result of my own work and has not been shared with any other student or 3rd party content provider. This submitted piece of work is entierly of my own creation.

// **********************************************************************************************

#include <stdio.h>
#define MAX_FORECAST 10
int main()
{
    int nItemsForcast, importance, imp[3], i;
    char financeOption, fOptions[3];
    const double minIncome = 500.00, maxIncome = 400000.00, minItemValue = 100.00;
    double income, itemValue, itemCosts[3], totalCost;

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
        printf("%3d  %5d    %5c    %11.2lf\n",i+1,imp[i],fOptions[i],itemCosts[i]);
        totalCost += itemCosts[i]; 
    }
    
    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n\n",totalCost);
    printf("Best of luck in all your future endeavours!\n");
    return 0;
}