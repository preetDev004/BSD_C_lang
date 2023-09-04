// **********************************************************************************************
                //   <assessment name example: Workshop - #2 (Part-2)>

// Authenticity Declaration :
// I declare this submission is the result of my own work and has not been shared with any other student or 3rd party content provider. This submitted piece of work is entierly of my own creation.

// **********************************************************************************************

#include<stdio.h>
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

    int pattySize, tommySize, sallySize, smallShirtsCent = smallShirts * 100,
    mediumShirtsCent = mediumShirts * 100, largeShirtsCent = largeShirts * 100, balance, remaining, withTaxBalance, withTaxRemaining;

    printf("\n");
    printf("Shirt Store Price List\n");
    printf("======================\n");
    printf("SMALL  : $%.2lf\n", (double)(smallShirtsCent)/100);
    printf("MEDIUM : $%.2lf\n", (double)(mediumShirtsCent)/100);
    printf("LARGE  : $%.2lf\n\n", (double)(largeShirtsCent)/100);
    printf("Patty's shirt size is 'S'\n");
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &pattySize);
    printf("\nTommy's shirt size is 'L'\n");
    printf("Number of shirts Tommy is buying: ");
    scanf("%d", &tommySize);
    printf("\nSally's shirt size is 'M'\n");
    printf("Number of shirts Sally is buying: ");
    scanf("%d", &sallySize);

    printf("\nCustomer Size Price Qty Sub-Total       Tax     Total");
    printf("\n-------- ---- ----- --- --------- --------- ---------");
    printf("\nPatty    S    %.2lf   %d  %8.4lf  %8.4lf  %8.4lf",((double)(smallShirtsCent)/100),
    pattySize,(((double)(smallShirtsCent * pattySize)) / 100),
    (((double)((smallShirtsCent * pattySize * 13) / 100)+1) /100)
    ,((double)(smallShirtsCent * pattySize + ((smallShirtsCent * pattySize * 13) / 100)+1) / 100));

    printf("\nSally    M    %.2lf   %d  %8.4lf  %8.4lf  %8.4lf",((double)(mediumShirtsCent)/100),
    sallySize,(((double)(mediumShirtsCent * sallySize)) / 100),
    (((double)((mediumShirtsCent * sallySize * 13) / 100)+1) /100),
    ((double)(mediumShirtsCent * sallySize + ((mediumShirtsCent * sallySize * 13) / 100)+1) / 100));

    printf("\nTommy    L    %.2lf   %d  %8.4lf  %8.4lf  %8.4lf",((double)(largeShirtsCent)/100),
    tommySize,(((double)(largeShirtsCent * tommySize)) / 100),
    (((double)((largeShirtsCent * tommySize * 13) / 100)+1) /100),
    ((double)(largeShirtsCent * tommySize + ((largeShirtsCent * tommySize * 13) / 100)+1) / 100));

    printf("\n-------- ---- ----- --- --------- --------- ---------");
    printf("\n                         %8.4lf  %8.4lf  %8.4lf",((((double)(mediumShirtsCent * sallySize)) / 100)+
    (((double)(largeShirtsCent * tommySize)) / 100)+
    (((double)(smallShirtsCent * pattySize)) / 100)),
    ((((double)((mediumShirtsCent * sallySize * 13) / 100)+1) /100)+
    (((double)((largeShirtsCent * tommySize * 13) / 100)+1) /100)+
    (((double)((smallShirtsCent * pattySize * 13) / 100)+1) /100)),
    (((double)(mediumShirtsCent * sallySize + ((mediumShirtsCent * sallySize * 13) / 100)+1) / 100)+
    ((double)(smallShirtsCent * pattySize + ((smallShirtsCent * pattySize * 13) / 100)+1) / 100)+
    ((double)(largeShirtsCent * tommySize + ((largeShirtsCent * tommySize * 13) / 100)+1) / 100)));
//--------------------------------------------------------------------------------------------------------------------------------
    balance = ((((double)(mediumShirtsCent * sallySize)))+
    (((double)(largeShirtsCent * tommySize)))+
    (((double)(smallShirtsCent * pattySize)))) ;
    
    printf("\n\nDaily retail sales represented by coins");
    printf("\n=======================================\n\n");
    printf("Sales EXCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("              %8.4lf\n",((((double)(mediumShirtsCent * sallySize)) / 100)+
    (((double)(largeShirtsCent * tommySize)) / 100)+
    (((double)(smallShirtsCent * pattySize)) / 100)));

    printf("Toonies  %d  %8.4lf\n",(balance/200),
     ((((double)(mediumShirtsCent * sallySize)) / 100)+
     (((double)(largeShirtsCent * tommySize)) / 100)+
     (((double)(smallShirtsCent * pattySize)) / 100)-(double)((balance/200)*2)));

    remaining = balance - ((balance/200)*200);
    printf("Loonies    %d  %8.4lf\n",(remaining/100),((double)remaining/100)-((remaining/100)*1));
    remaining -=  (remaining/100)*100;
    printf("Quarters   %d  %8.4lf\n",(remaining/25),(((double)remaining)-((remaining/25)*25))/100);
    remaining -=  (remaining/25)*25;
    printf("Dimes      %d  %8.4lf\n",(remaining/10),(((double)remaining)-((remaining/10)*10))/100);
    remaining -=  (remaining/10)*10;
    printf("Nickels    %d  %8.4lf\n",(remaining/5),(((double)remaining)-((remaining/5)*5))/100);
    remaining -=  (remaining/5)*5;
    printf("Pennies    %d  %8.4lf\n",(remaining/1),(((double)remaining)-((remaining/1)*1))/100);

    printf("\nAverage cost/shirt: $%.4lf\n\n",(double)(((((double)(mediumShirtsCent * sallySize)) / 100)+
    (((double)(largeShirtsCent * tommySize)) / 100)+
    (((double)(smallShirtsCent * pattySize)) / 100))/(pattySize+sallySize+tommySize)));


// ------------------------------------------------------------------------------------------------------------------------------


    withTaxBalance = (((double)(mediumShirtsCent * sallySize + ((mediumShirtsCent * sallySize * 13) / 100)+1))+
    ((double)(smallShirtsCent * pattySize + ((smallShirtsCent * pattySize * 13) / 100)+1) )+
    ((double)(largeShirtsCent * tommySize + ((largeShirtsCent * tommySize * 13) / 100)+1) ));

    printf("Sales INCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("              %8.4lf\n",(((double)(mediumShirtsCent * sallySize + ((mediumShirtsCent * sallySize * 13) / 100)+1) / 100)+
    ((double)(smallShirtsCent * pattySize + ((smallShirtsCent * pattySize * 13) / 100)+1) / 100)+
    ((double)(largeShirtsCent * tommySize + ((largeShirtsCent * tommySize * 13) / 100)+1) / 100)));

    printf("Toonies  %d  %8.4lf\n",(withTaxBalance/200), (((double)(mediumShirtsCent * sallySize + ((mediumShirtsCent * sallySize * 13) / 100)+1) / 100)+((double)(smallShirtsCent * pattySize + ((smallShirtsCent * pattySize * 13) / 100)+1) / 100)+((double)(largeShirtsCent * tommySize + ((largeShirtsCent * tommySize * 13) / 100)+1) / 100)-((double)(withTaxBalance/200)*2)));
    withTaxRemaining = withTaxBalance - ((withTaxBalance/200)*200);
    printf("Loonies    %d  %8.4lf\n",(withTaxRemaining/100),((double)withTaxRemaining/100)-((withTaxRemaining/100)*1));
    withTaxRemaining -=  (withTaxRemaining/100)*100;
    printf("Quarters   %d  %8.4lf\n",(withTaxRemaining/25),(((double)withTaxRemaining)-((withTaxRemaining/25)*25))/100);
    withTaxRemaining -=  (withTaxRemaining/25)*25;
    printf("Dimes      %d  %8.4lf\n",(withTaxRemaining/10),(((double)withTaxRemaining)-((withTaxRemaining/10)*10))/100);
    withTaxRemaining -=  (withTaxRemaining/10)*10;
    printf("Nickels    %d  %8.4lf\n",(withTaxRemaining/5),(((double)withTaxRemaining)-((withTaxRemaining/5)*5))/100);
    withTaxRemaining -=  (withTaxRemaining/5)*5;
    printf("Pennies    %d  %8.4lf\n",(withTaxRemaining/1),(((double)withTaxRemaining)-((withTaxRemaining/1)*1))/100);

    printf("\nAverage cost/shirt: $%.4lf\n",((double)(withTaxBalance)/(pattySize+sallySize+tommySize))/100);


return 0;
}