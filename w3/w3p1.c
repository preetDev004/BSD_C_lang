// **********************************************************************************************
                //   <assessment name example: Workshop - #3 (Part-1)>

// Authenticity Declaration :
// I declare this submission is the result of my own work and has not been shared with any other student or 3rd party content provider. This submitted piece of work is entierly of my own creation.

// **********************************************************************************************


#include<stdio.h>

int main()
{
    const double testValue = 330.99;

    // necessary 9 variables
    const int p1Id = 111, p2Id = 222, p3Id = 111;
    const double p1Price = 111.49, p2Price = 222.99, p3Price = 334.49;
    const char p1Taxed = 'Y', p2Taxed = 'N', p3Taxed = 'N';

    // All products information
    printf("Product Information\n");
    printf("===================\n");
    printf("Product-1 (ID:%d)\n",p1Id);
    printf("  Taxed: %c\n", p1Taxed);
    printf("  Price: $%8.4lf\n\n",p1Price);

    printf("Product-2 (ID:%d)\n",p2Id);
    printf("  Taxed: %c\n", p2Taxed);
    printf("  Price: $%8.4lf\n\n",p2Price);

    printf("Product-3 (ID:%d)\n",p3Id);
    printf("  Taxed: %c\n", p3Taxed);
    printf("  Price: $%8.4lf\n\n",p3Price);

    //The avg of all prices
    printf("The average of all prices is: $%8.4lf\n\n",(p1Price+p2Price+p3Price)/3);

    printf("About Relational and Logical Expressions!\n");
    printf("========================================\n");
    printf("1. These expressions evaluate to TRUE or FALSE\n");
    printf("2. FALSE: is always represented by integer value 0\n");
    printf("3. TRUE : is represented by any integer value other than 0\n\n");

    printf("Some Data Analysis...\n");
    printf("=====================\n");
    printf("1. Is product 1 taxable? -> %d\n\n",(p1Taxed == 'Y'));
    printf("2. Are products 2 and 3 both NOT taxable (N)? -> %d\n\n", (p2Taxed == 'N' && p3Taxed == 'N'));
    printf("3. Is product 3 less than testValue ($%.2lf)? -> %d\n\n", testValue, (p3Price < testValue));
    printf("4. Is the price of product 3 more than both product 1 and 2 combined? -> %d\n\n",
    (p3Price > (p1Price + p2Price)));
    printf("5. Is the price of product 1 equal to or more than the price difference\n   of product 3 LESS product 2? ->  %d (price difference: $%.2lf)\n\n",
    (p1Price == (p3Price - p2Price) || p1Price >= (p3Price - p2Price)), (p3Price - p2Price));
    printf("6. Is the price of product 2 equal to or more than the average price? -> %d\n\n",
    ((p2Price == (p1Price+p2Price+p3Price)/3) || (p2Price >= (p1Price+p2Price+p3Price)/3)));
    printf("7. Based on product ID, product 1 is unique -> %d\n\n", ((p1Id != p2Id) && (p1Id != p3Id)));
    printf("8. Based on product ID, product 2 is unique -> %d\n\n", ((p2Id != p1Id) && (p2Id != p3Id)));
    printf("9. Based on product ID, product 3 is unique -> %d\n", ((p3Id != p1Id) && (p3Id != p2Id)));

return 0;
}