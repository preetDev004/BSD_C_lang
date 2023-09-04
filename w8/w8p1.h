// **********************************************************************************************
//   <assessment name example: Workshop - #8 (Part-1)>

// Authenticity Declaration :
// I declare this submission is the result of my own work and has not been shared with any other student or 3rd party content provider. This submitted piece of work is entierly of my own creation.

// **********************************************************************************************

#define MAX_NUMBER_OF_PRODUCTS 3
#define SUGGESTED_NUMBER_OF_GRAMS 64

struct CatFoodInfo
{
    int sku;
    int calPerSugServing;
    double productPrice; 
    double productWeight;

};

int getIntPositive(int* intPositive);
double getDoublePositive(double* doublePositive);

void openingMessage(const int nProducts);

struct CatFoodInfo getCatFoodInfo(const int sOfProduct);
void displayCatFoodHeader(void);

void displayCatFoodData(int sku, double* productPrice, double* productWeight, int calPerSugServing);

void start(void);
