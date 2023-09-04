// **********************************************************************************************
//   <assessment name example: Workshop - #8 (Part-2)>

// Full Name   : Preet Dineshkumar Patel
// Student ID# : 123845224
// Email       : pdpatel51@myseneca.ca
// Section     : NAA

// Authenticity Declaration :
// I declare this submission is the result of my own work and has not been
// shared with any other student or 3rd party content provider.
// This submitted piece of work is entierly of my own creation.

// **********************************************************************************************
#include <stdio.h>
#include "w8p2.h"


int getIntPositive(int *intPositive);
double getDoublePositive(double *doublePositive);

void openingMessage(const int nProducts);

struct CatFoodInfo getCatFoodInfo(const int sOfProduct);
void displayCatFoodHeader(void);

void displayCatFoodData(int sku, double *productPrice, double *productWeight, int calPerSugServing);

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
    if (intPositive != NULL)
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
    printf("Cat Food Product #%d\n", sOfProduct + 1);
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

void displayCatFoodData(int sku, double *productPrice, double *productWeight, int calPerSugServing)
{
    printf("%07d %10.2lf %10.1lf %8d\n", sku, *productPrice, *productWeight, calPerSugServing);
}

//  ------------------------------------------ PART 2 ---------------------------------------------

double convertLbsKg(const double *lbsToConvert, double *kgsFromLbs)
{
    double kgs;
    kgs = *(lbsToConvert) / LBS_TO_KGS;
    if (kgsFromLbs != NULL)
    {
        *(kgsFromLbs) = kgs;
    }
    return kgs;
}

int convertLbsG(const double *lbsToConvert, int *gsFromLbs)
{
    int grams;
    grams = convertLbsKg(lbsToConvert, NULL) * 1000;
    if (gsFromLbs != NULL)
    {
        *(gsFromLbs) = grams;
    }
    return grams;
}

void convertLbs(const double *lbsToConvert, double *kgsFromLbs, int *gsFromLbs)
{

    *(kgsFromLbs) = convertLbsKg(lbsToConvert, NULL);
    *(gsFromLbs) = convertLbsG(lbsToConvert, NULL);
}

double calculateServings(const int servingInGrams, const int totalGramsForProduct, double *numberOfServings)
{
    double totalServings;
    totalServings = servingInGrams / (double)totalGramsForProduct;
    if (numberOfServings != NULL)
    {
        *(numberOfServings) = totalServings;
    }
    return totalServings;
}

double calculateCostPerServing(const double *productPrice, const double *totalNumberOfServings, double *costPerServing)
{
    double perServingCost;
    perServingCost = *(productPrice) / *(totalNumberOfServings);
    if (costPerServing != NULL)
    {
        *(costPerServing) = perServingCost;
    }
    return perServingCost;
}

double calculateCostPerCal(const double *productPrice, const double *totalNumberOfCalories, double *costPerCalorie)
{
    double calOnCost;
    calOnCost = *(productPrice) / *(totalNumberOfCalories);
    if (costPerCalorie != NULL)
    {
        *(costPerCalorie) = calOnCost;
    }
    return calOnCost;
}

struct ReportData calculateReportData(const struct CatFoodInfo cfi)
{
    struct ReportData rd;
    double totalCalories;
    rd.sku = cfi.sku;
    rd.calPerSugServing = cfi.calPerSugServing;
    rd.productPrice = cfi.productPrice;
    rd.productWeightLbs = cfi.productWeight;
    rd.productWeightKgs = convertLbsKg(&rd.productWeightLbs, NULL);
    rd.productWeightGs = convertLbsG(&rd.productWeightLbs, NULL);
    rd.totalServings = calculateServings(rd.productWeightGs, SUGGESTED_NUMBER_OF_GRAMS, NULL);
    rd.costPerServing = calculateCostPerServing(&rd.productPrice, &rd.totalServings, NULL);
    totalCalories = (double)rd.calPerSugServing;
    rd.costOfCaloriesPerServing = calculateCostPerCal(&rd.costPerServing, &totalCalories, NULL);

    return rd;
}

void displayReportHeader(void)
{
    printf("Analysis Report (Note: Serving = %dg)\n", SUGGESTED_NUMBER_OF_GRAMS);
    printf("---------------\n");
    printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
    printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

void displayReportData(const struct ReportData rd, const int cheapestProduct)
{
    printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", rd.sku, rd.productPrice, rd.productWeightLbs,
    rd.productWeightKgs, rd.productWeightGs, rd.calPerSugServing, rd.totalServings, rd.costPerServing, rd.costOfCaloriesPerServing);
    if (cheapestProduct != 0)
    {
        printf(" ***\n");
    }
    else
    {
        printf("\n");
    }
}

void displayFinalAnalysis(const struct CatFoodInfo cfi)
{
    printf("\nFinal Analysis\n");
    printf("--------------\n");
    printf("Based on the comparison data, the PURRR-fect economical option is:\n");
    printf("SKU:%07d Price: $%.2lf\n\n", cfi.sku, cfi.productPrice);
    printf("Happy shopping!\n");
}

void start(void)
{
    struct CatFoodInfo catFood[MAX_NUMBER_OF_PRODUCTS];
    struct ReportData reData[MAX_NUMBER_OF_PRODUCTS];
    int cheapestProduct[MAX_NUMBER_OF_PRODUCTS] = {0};
    int i, minIndex;

    openingMessage(MAX_NUMBER_OF_PRODUCTS);
    printf("\n");

    for (i = 0; i < MAX_NUMBER_OF_PRODUCTS; i++)
    {
        catFood[i] = getCatFoodInfo(i);
        // getCatFoodInfo(i);
        printf("\n");
    }

    displayCatFoodHeader();
    for (i = 0; i < MAX_NUMBER_OF_PRODUCTS; i++)
    {
        displayCatFoodData(catFood[i].sku, &catFood[i].productPrice, &catFood[i].productWeight, catFood[i].calPerSugServing);
    }

    printf("\n");

    displayReportHeader();

    for (i = 0; i < MAX_NUMBER_OF_PRODUCTS; i++)
    {
        reData[i] = calculateReportData(catFood[i]);
    }

    for ( i = 1; i < MAX_NUMBER_OF_PRODUCTS; i++)
    {
        if(reData[i-1].costPerServing < reData[i].costPerServing){
            minIndex = i-1;
        }
    }
    cheapestProduct[minIndex] = 1;
    

    for (i = 0; i < MAX_NUMBER_OF_PRODUCTS; i++)
    {
        displayReportData(reData[i], cheapestProduct[i]);
    }
    for (i = 0; i < MAX_NUMBER_OF_PRODUCTS; i++)
    {
        if (cheapestProduct[i])
        {
            displayFinalAnalysis(catFood[i]);
        }
    }
}