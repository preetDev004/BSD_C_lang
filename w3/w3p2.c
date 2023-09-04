// **********************************************************************************************
//   <assessment name example: Workshop - #3 (Part-2)>

// Authenticity Declaration :
// I declare this submission is the result of my own work and has not been shared with any other student or 3rd party content provider. This submitted piece of work is entierly of my own creation.

// **********************************************************************************************

#include <stdio.h>

int main()
{
       const double GRAMS_IN_LBS = 453.5924;
       char coffee1Type, coffee2Type, coffee3Type, isCreamNice1, isCreamNice2, isCreamNice3, userCoffee, userIsCream;
       int weight1, weight2, weight3, userServing;
       printf("Take a Break - Coffee Shop\n");
       printf("==========================\n\n");

       printf("Enter the coffee product information being sold today...\n\n");

       printf("COFFEE-1...\n");
       printf("Type ([L]ight,[M]edium,[R]ich): ");
       scanf(" %c", &coffee1Type);
       printf("Bag weight (g): ");
       scanf("%d", &weight1);
       printf("Best served with cream ([Y]es,[N]o): ");
       scanf(" %c", &isCreamNice1);

       printf("\nCOFFEE-2...\n");
       printf("Type ([L]ight,[M]edium,[R]ich): ");
       scanf(" %c", &coffee2Type);
       printf("Bag weight (g): ");
       scanf("%d", &weight2);
       printf("Best served with cream ([Y]es,[N]o): ");
       scanf(" %c", &isCreamNice2);

       printf("\nCOFFEE-3...\n");
       printf("Type ([L]ight,[M]edium,[R]ich): ");
       scanf(" %c", &coffee3Type);
       printf("Bag weight (g): ");
       scanf("%d", &weight3);
       printf("Best served with cream ([Y]es,[N]o): ");
       scanf(" %c", &isCreamNice3);

       printf("\n---+------------------------+---------------+-------+\n");
       printf("   |    Coffee              |   Packaged    | Best  |\n");
       printf("   |     Type               |  Bag Weight   | Served|\n");
       printf("   +------------------------+---------------+ With  |\n");
       printf("ID | Light | Medium | Rich  |  (G) | Lbs    | Cream |\n");
       printf("---+------------------------+---------------+-------|\n");
       printf(" 1 |   %d   |   %d    |   %d   | %4.3d |  %.3lf |   %d   |\n",
              (coffee1Type == 'L' || coffee1Type == 'l'), (coffee1Type == 'M' || coffee1Type == 'm'),
              (coffee1Type == 'R' || coffee1Type == 'r'), weight1, weight1 / GRAMS_IN_LBS,
              (isCreamNice1 == 'Y' || isCreamNice1 == 'y'));

       printf(" 2 |   %d   |   %d    |   %d   | %4.3d |  %.3lf |   %d   |\n",
              (coffee2Type == 'L' || coffee2Type == 'l'), (coffee2Type == 'M' || coffee2Type == 'm'),
              (coffee2Type == 'R' || coffee2Type == 'r'), weight2, weight2 / GRAMS_IN_LBS,
              (isCreamNice2 == 'Y' || isCreamNice2 == 'y'));

       printf(" 3 |   %d   |   %d    |   %d   | %4.3d |  %.3lf |   %d   |\n\n",
              (coffee3Type == 'L' || coffee3Type == 'l'), (coffee3Type == 'M' || coffee3Type == 'm'),
              (coffee3Type == 'R' || coffee3Type == 'r'), weight3, weight3 / GRAMS_IN_LBS,
              (isCreamNice3 == 'Y' || isCreamNice3 == 'y'));

       printf("Enter how you like your coffee...\n\n");

       printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
       scanf(" %c", &userCoffee);
       printf("Do you like your coffee with cream ([Y]es,[N]o): ");
       scanf(" %c", &userIsCream);
       printf("Typical number of daily servings: ");
       scanf("%d", &userServing);

       printf("\nThe below table shows how your preferences align to the available products:\n\n");
       printf("--------------------+-------------+-------+\n");
       printf("  |     Coffee      |  Packaged   | With  |\n");
       printf("ID|      Type       | Bag Weight  | Cream |\n");
       printf("--+-----------------+-------------+-------+\n");
       printf(" 1|       %d         |      %d      |   %d   |\n",
              ((userCoffee == coffee1Type) || (userCoffee + 32 == coffee1Type) || (userCoffee - 32 == coffee1Type)),
              ((userServing >= 1 && userServing <= 4) * (weight1 >= 250 && weight1 < 500) ||
               (userServing >= 5 && userServing <= 9) * (weight1 >= 500 && weight1 < 1000) || (userServing >= 10) * (weight1 >= 1000)),
              (userIsCream == isCreamNice1 || userIsCream + 32 == isCreamNice1 || userIsCream - 32 == isCreamNice1));

       printf(" 2|       %d         |      %d      |   %d   |\n",
              ((userCoffee == coffee2Type) || (userCoffee + 32 == coffee2Type) || (userCoffee - 32 == coffee2Type)),
              ((userServing >= 1 && userServing <= 4) * (weight2 >= 250 && weight2 < 500) ||
               (userServing >= 5 && userServing <= 9) * (weight2 >= 500 && weight2 < 1000) || (userServing >= 10) * (weight2 >= 1000)),
              (userIsCream == isCreamNice2 || userIsCream + 32 == isCreamNice2 || userIsCream - 32 == isCreamNice2));

       printf(" 3|       %d         |      %d      |   %d   |\n\n",
              ((userCoffee == coffee3Type) || (userCoffee + 32 == coffee3Type) || (userCoffee - 32 == coffee3Type)),
              ((userServing >= 1 && userServing <= 4) * (weight3 >= 250 && weight3 < 500) ||
               (userServing >= 5 && userServing <= 9) * (weight3 >= 500 && weight3 < 1000) || (userServing >= 10) * (weight3 >= 1000)),
              (userIsCream == isCreamNice3 || userIsCream + 32 == isCreamNice3 || userIsCream - 32 == isCreamNice3));
       
       userCoffee = ' ';
       userIsCream = ' ';
       userServing = 0;
       // -----------------------------------------Second time--------------------------------------------------
       printf("Enter how you like your coffee...\n\n");

       printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
       scanf(" %c", &userCoffee);
       printf("Do you like your coffee with cream ([Y]es,[N]o): ");
       scanf(" %c", &userIsCream);
       printf("Typical number of daily servings: ");
       scanf("%d", &userServing);

       printf("\nThe below table shows how your preferences align to the available products:\n\n");
       printf("--------------------+-------------+-------+\n");
       printf("  |     Coffee      |  Packaged   | With  |\n");
       printf("ID|      Type       | Bag Weight  | Cream |\n");
       printf("--+-----------------+-------------+-------+\n");
       printf(" 1|       %d         |      %d      |   %d   |\n",
              ((userCoffee == coffee1Type) || (userCoffee + 32 == coffee1Type) || (userCoffee - 32 == coffee1Type)),
              ((userServing >= 1 && userServing <= 4) * (weight1 >= 250 && weight1 < 500) ||
               (userServing >= 5 && userServing <= 9) * (weight1 >= 500 && weight1 < 1000) || (userServing >= 10) * (weight1 >= 1000)),
              (userIsCream == isCreamNice1 || userIsCream + 32 == isCreamNice1 || userIsCream - 32 == isCreamNice1));

       printf(" 2|       %d         |      %d      |   %d   |\n",
              ((userCoffee == coffee2Type) || (userCoffee + 32 == coffee2Type) || (userCoffee - 32 == coffee2Type)),
              ((userServing >= 1 && userServing <= 4) * (weight2 >= 250 && weight2 < 500) ||
               (userServing >= 5 && userServing <= 9) * (weight2 >= 500 && weight2 < 1000) || (userServing >= 10) * (weight2 >= 1000)),
              (userIsCream == isCreamNice2 || userIsCream + 32 == isCreamNice2 || userIsCream - 32 == isCreamNice2));

       printf(" 3|       %d         |      %d      |   %d   |\n\n",
              ((userCoffee == coffee3Type) || (userCoffee + 32 == coffee3Type) || (userCoffee - 32 == coffee3Type)),
              ((userServing >= 1 && userServing <= 4) * (weight3 >= 250 && weight3 < 500) ||
               (userServing >= 5 && userServing <= 9) * (weight3 >= 500 && weight3 < 1000) || (userServing >= 10) * (weight3 >= 1000)),
              (userIsCream == isCreamNice3 || userIsCream + 32 == isCreamNice3 || userIsCream - 32 == isCreamNice3));

       printf("Hope you found a product that suits your likes!\n");
       return 0;
}