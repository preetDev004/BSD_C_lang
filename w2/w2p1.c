// **********************************************************************************************
                //   <assessment name example: Workshop - #2 (Part-1)>

// Authenticity Declaration :
// I declare this submission is the result of my own work and has not been shared with any other student or 3rd party content provider. This submitted piece of work is entierly of my own creation.

// **********************************************************************************************


#include <stdio.h>
int main()
{
    double smallShirts, mediumShirts, largeShirts;
    printf("Set Shirt Prices\n");
    printf("================\n");
    printf("Enter the price for a SMALL shirt: $");
    scanf("%lf", &smallShirts);
    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%lf", &mediumShirts);
    printf("Enter the price for a LARGE shirt: $");
    scanf("%lf", &largeShirts);

    int nShirts, subTotal, smallShirtsCent = smallShirts * 100, mediumShirtsCent = mediumShirts * 100, largeShirtsCent = largeShirts * 100;

    printf("\n");
    printf("Shirt Store Price List\n");
    printf("======================\n");
    printf("SMALL  : $%.2lf\n", (double)(smallShirtsCent)/100);
    printf("MEDIUM : $%.2lf\n", (double)(mediumShirtsCent)/100);
    printf("LARGE  : $%.2lf\n\n", (double)(largeShirtsCent)/100);
    printf("Patty's shirt size is 'S'\n");
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &nShirts);
    printf("\nPatty's shopping cart...\n");
    printf("Contains : %d shirts\n", nShirts);
    subTotal = smallShirtsCent * nShirts;

    printf("Sub-total: $%8.4lf\n", ((double)(subTotal)) / 100);
    printf("Taxes    : $%8.4lf\n", (((double)((subTotal * 13) / 100)+1) /100));
    printf("Total    : $%8.4lf\n", ((double)(subTotal + ((subTotal * 13) / 100)+1) / 100));

    return 0;
}