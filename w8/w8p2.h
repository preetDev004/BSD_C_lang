// **********************************************************************************************
//   <assessment name example: Workshop - #8 (Part-2)>

// Full Name   : Preet Dineshkumar Patel
// Student ID# : 123845224
// Email       : pdpatel51@myseneca.ca
// Section     : NAA

// Authenticity Declaration :
// I declare this submission is the result of my own work and has not been shared with any other student or 3rd party content provider. This submitted piece of work is entierly of my own creation.

// **********************************************************************************************

#define MAX_NUMBER_OF_PRODUCTS 3
#define SUGGESTED_NUMBER_OF_GRAMS 64
#define LBS_TO_KGS 2.20462

struct CatFoodInfo
{
    int sku;
    int calPerSugServing;
    double productPrice;
    double productWeight;
};

int getIntPositive(int *intPositive);

double getDoublePositive(double *doublePositive);

void openingMessage(const int nProducts);

struct CatFoodInfo getCatFoodInfo(const int sOfProduct);

void displayCatFoodHeader(void);

void displayCatFoodData(int sku, double *productPrice, double *productWeight, int calPerSugServing);

void start(void);

//-------------------------PART_2----------------------------------

struct ReportData
{
    int sku;
    int calPerSugServing;
    int productWeightGs;
    double productPrice;
    double costPerServing;
    double costOfCaloriesPerServing;
    double totalServings;
    double productWeightLbs;
    double productWeightKgs;
};

double convertLbsKg(const double *lbsToConvert, double *kgsFromLbs);

int convertLbsG(const double *lbsToConvert, int *gsFromLbs);

void convertLbs(const double *lbsToConvert, double *kgsFromLbs, int *gsFromLbs);

double calculateServings(const int servingInGrams, const int totalGramsForProduct, double *numberOfServings);

double calculateCostPerServing(const double *productPrice, const double *totalNumberOfServings, double *costPerServing);

double calculateCostPerCal(const double *productPrice, const double *totalNumberOfCalories, double *costPerCalorie);

struct ReportData calculateReportData(const struct CatFoodInfo cfi);

void displayReportHeader(void);

void displayReportData(const struct ReportData rd, const int cheapestProduct);

void displayFinalAnalysis(const struct CatFoodInfo cfi);

