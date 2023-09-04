// **********************************************************************************************
//   <assessment name example: Workshop - #5 (Part-1)>

// Authenticity Declaration :
// I declare this submission is the result of my own work and has not been shared with any other student or 3rd party content provider. This submitted piece of work is entierly of my own creation.

// **********************************************************************************************

#include <stdio.h>
#define MIN_YEAR 2012
#define MAX_YEAR 2022

int main()
{
    const int JAN = 1, DEC = 12;
    int year, month;

    printf("General Well-being Log\n");
    printf("======================\n");

    do
    {
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d %d", &year, &month);
        if (year > MAX_YEAR || year < MIN_YEAR)
        {
            printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
        }
        if (month > DEC || month < JAN)
        {
            printf("   ERROR: Jan.(1) - Dec.(12)\n");
        }
    } while ((year > MAX_YEAR || year < MIN_YEAR) || (month > DEC || month < JAN));

    printf("\n*** Log date set! ***");

    if (month == 1)
    {
        printf("\n\nLog starting date: %d-JAN-01\n", year);
    }
    else if (month == 2)
    {
        printf("\n\nLog starting date: %d-FEB-01\n", year);
    }
    else if (month == 3)
    {
        printf("\n\nLog starting date: %d-MAR-01\n", year);
    }
    else if (month == 4)
    {
        printf("\n\nLog starting date: %d-APR-01\n", year);
    }
    else if (month == 5)
    {
        printf("\n\nLog starting date: %d-MAY-01\n", year);
    }
    else if (month == 6)
    {
        printf("\n\nLog starting date: %d-JUN-01\n", year);
    }
    else if (month == 7)
    {
        printf("\n\nLog starting date: %d-JUL-01\n", year);
    }
    else if (month == 8)
    {
        printf("\n\nLog starting date: %d-AUG-01\n", year);
    }
    else if (month == 9)
    {
        printf("\n\nLog starting date: %d-SEP-01\n", year);
    }
    else if (month == 10)
    {
        printf("\n\nLog starting date: %d-OCT-01\n", year);
    }
    else if (month == 11)
    {
        printf("\n\nLog starting date: %d-NOV-01\n", year);
    }
    else if (month == 12)
    {
        printf("\n\nLog starting date: %d-DEC-01\n", year);
    }
    

    return 0;
}