// **********************************************************************************************
//   <assessment name example: Workshop - #8 (Part-1)>

// Authenticity Declaration :
// I declare this submission is the result of my own work and has not been shared with any other student or 3rd party content provider. This submitted piece of work is entierly of my own creation.

// **********************************************************************************************

#include <stdio.h>
#include "w8p1.h"

int getIntPositive(int* intPositive);
double getDoublePositive(double* doublePositive);

void openingMessage(const int nProducts);

struct CatFoodInfo getCatFoodInfo(const int sOfProduct);
void displayCatFoodHeader(void);

void displayCatFoodData(int sku, double* productPrice, double* productWeight, int calPerSugServing);

void start(void);

int getIntPositive(int *intPositive)
{
    int tmp;
    do
    {
        scanf("%d", &tmp);
        if (tmp < 1)
        {
            printf("ERROR: Enter a positive value: ");
        }

    } while (tmp < 1);
    if (intPositive  != NULL)
        *(intPositive) = tmp;

    return tmp;
}

double getDoublePositive(double *doublePositive)
{
    double tmp;
    do
    {
        scanf("%lf", &tmp);
        if (tmp < 1)
        {
            printf("ERROR: Enter a positive value: ");
        }

    } while (tmp < 1);
    if (doublePositive != NULL)
        *(doublePositive) = tmp;
    return tmp;
}

void openingMessage(const int nProducts)
{
    printf("Cat Food Cost Analysis\n");
    printf("======================\n\n");
    printf("Enter the details for %d dry food bags of product data for analysis.\n", nProducts);
    printf("NOTE: A 'serving' is %dg\n", SUGGESTED_NUMBER_OF_GRAMS);
}

struct CatFoodInfo getCatFoodInfo(const int sOfProduct)
{
    struct CatFoodInfo cfi;
    printf("Cat Food Product #%d\n", sOfProduct+1);
    printf("--------------------\n");
    printf("SKU           : ");
    getIntPositive(&cfi.sku);
    printf("PRICE         : $");
    getDoublePositive(&cfi.productPrice);
    printf("WEIGHT (LBS)  : ");
    getDoublePositive(&cfi.productWeight);
    printf("CALORIES/SERV.: ");
    getIntPositive(&cfi.calPerSugServing);

    return cfi;
    
}

void displayCatFoodHeader(void)
{
    printf("SKU         $Price    Bag-lbs Cal/Serv\n");
    printf("------- ---------- ---------- --------\n");
}

void displayCatFoodData(int sku, double *productPrice, double *productWeight,int calPerSugServing){
    printf("%07d %10.2lf %10.1lf %8d\n",sku,*productPrice,*productWeight, calPerSugServing);
}

void start(void){
    struct CatFoodInfo catFood[MAX_NUMBER_OF_PRODUCTS];
    int i;

    openingMessage(MAX_NUMBER_OF_PRODUCTS);
    printf("\n");

    for ( i = 0; i < MAX_NUMBER_OF_PRODUCTS; i++)
    {
        catFood[i] = getCatFoodInfo(i);
        // getCatFoodInfo(i);
        printf("\n");
    }
    
    displayCatFoodHeader();
    for ( i = 0; i < MAX_NUMBER_OF_PRODUCTS; i++)
    {
        displayCatFoodData(catFood[i].sku, &catFood[i].productPrice, &catFood[i].productWeight, catFood[i].calPerSugServing);
    }
    
    printf("\n\n");
}
 
