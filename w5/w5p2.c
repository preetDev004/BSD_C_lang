// **********************************************************************************************
//   <assessment name example: Workshop - #5 (Part-2)>

// Authenticity Declaration :
// I declare this submission is the result of my own work and has not been shared with any other student or 3rd party content provider. This submitted piece of work is entierly of my own creation.

// **********************************************************************************************

#include <stdio.h>
#define MIN_YEAR 2012
#define MAX_YEAR 2022
#define LOG_DAYS 3

int main()
{
    const int JAN = 1, DEC = 12;
    int year, month, day;

    // New variables for part-2
    double mRating, eRating, mTotalRating, eTotalRating;

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

    printf("\n*** Log date set! ***\n");

    if (month == 1)
    {
        for (day = 1; day <= LOG_DAYS; day++)
        {
            printf("\n%d-JAN-%.2d\n", year, day);
            do
            {
                printf("   Morning rating (0.0-5.0): ");
                scanf("%lf", &mRating);
                if ((mRating < 0.0 || mRating > 5.0))
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
            } while ((mRating < 0.0 || mRating > 5.0));
            do
            {
                printf("   Evening rating (0.0-5.0): ");
                scanf("%lf", &eRating);
                if ((eRating < 0.0 || eRating > 5.0))
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
            } while ((eRating < 0.0 || eRating > 5.0));
            mTotalRating += mRating;
            eTotalRating += eRating;
        }
    }
    else if (month == 2)
    {
        for (day = 1; day <= LOG_DAYS; day++)
        {
            printf("\n%d-FEB-%.2d\n", year, day);
            do
            {
                printf("   Morning rating (0.0-5.0): ");
                scanf("%lf", &mRating);
                if ((mRating < 0.0 || mRating > 5.0))
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
            } while ((mRating < 0.0 || mRating > 5.0));
            do
            {
                printf("   Evening rating (0.0-5.0): ");
                scanf("%lf", &eRating);
                if ((eRating < 0.0 || eRating > 5.0))
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
            } while ((eRating < 0.0 || eRating > 5.0));
            mTotalRating += mRating;
            eTotalRating += eRating;
        }
    }
    else if (month == 3)
    {
        for (day = 1; day <= LOG_DAYS; day++)
        {
            printf("\n%d-MAR-%.2d\n", year, day);
            do
            {
                printf("   Morning rating (0.0-5.0): ");
                scanf("%lf", &mRating);
                if ((mRating < 0.0 || mRating > 5.0))
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
            } while ((mRating < 0.0 || mRating > 5.0));
            do
            {
                printf("   Evening rating (0.0-5.0): ");
                scanf("%lf", &eRating);
                if ((eRating < 0.0 || eRating > 5.0))
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
            } while ((eRating < 0.0 || eRating > 5.0));
            mTotalRating += mRating;
            eTotalRating += eRating;
        }
    }
    else if (month == 4)
    {
        for (day = 1; day <= LOG_DAYS; day++)
        {
            printf("\n%d-APR-%.2d\n", year, day);
            do
            {
                printf("   Morning rating (0.0-5.0): ");
                scanf("%lf", &mRating);
                if ((mRating < 0.0 || mRating > 5.0))
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
            } while ((mRating < 0.0 || mRating > 5.0));
            do
            {
                printf("   Evening rating (0.0-5.0): ");
                scanf("%lf", &eRating);
                if ((eRating < 0.0 || eRating > 5.0))
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
            } while ((eRating < 0.0 || eRating > 5.0));
            mTotalRating += mRating;
            eTotalRating += eRating;
        }
    }
    else if (month == 5)
    {
        for (day = 1; day <= LOG_DAYS; day++)
        {
            printf("\n%d-MAY-%.2d\n", year, day);
            do
            {
                printf("   Morning rating (0.0-5.0): ");
                scanf("%lf", &mRating);
                if ((mRating < 0.0 || mRating > 5.0))
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
            } while ((mRating < 0.0 || mRating > 5.0));
            do
            {
                printf("   Evening rating (0.0-5.0): ");
                scanf("%lf", &eRating);
                if ((eRating < 0.0 || eRating > 5.0))
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
            } while ((eRating < 0.0 || eRating > 5.0));
            mTotalRating += mRating;
            eTotalRating += eRating;
        }
    }
    else if (month == 6)
    {
        for (day = 1; day <= LOG_DAYS; day++)
        {
            printf("\n%d-JUN-%.2d\n", year, day);
            do
            {
                printf("   Morning rating (0.0-5.0): ");
                scanf("%lf", &mRating);
                if ((mRating < 0.0 || mRating > 5.0))
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
            } while ((mRating < 0.0 || mRating > 5.0));
            do
            {
                printf("   Evening rating (0.0-5.0): ");
                scanf("%lf", &eRating);
                if ((eRating < 0.0 || eRating > 5.0))
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
            } while ((eRating < 0.0 || eRating > 5.0));
            mTotalRating += mRating;
            eTotalRating += eRating;
        }
    }
    else if (month == 7)
    {
        for (day = 1; day <= LOG_DAYS; day++)
        {
            printf("\n%d-JUL-%.2d\n", year, day);
            do
            {
                printf("   Morning rating (0.0-5.0): ");
                scanf("%lf", &mRating);
                if ((mRating < 0.0 || mRating > 5.0))
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
            } while ((mRating < 0.0 || mRating > 5.0));
            do
            {
                printf("   Evening rating (0.0-5.0): ");
                scanf("%lf", &eRating);
                if ((eRating < 0.0 || eRating > 5.0))
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
            } while ((eRating < 0.0 || eRating > 5.0));
            mTotalRating += mRating;
            eTotalRating += eRating;
        }
    }
    else if (month == 8)
    {
        for (day = 1; day <= LOG_DAYS; day++)
        {
            printf("\n%d-AUG-%.2d\n", year, day);
            do
            {
                printf("   Morning rating (0.0-5.0): ");
                scanf("%lf", &mRating);
                if ((mRating < 0.0 || mRating > 5.0))
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
            } while ((mRating < 0.0 || mRating > 5.0));
            do
            {
                printf("   Evening rating (0.0-5.0): ");
                scanf("%lf", &eRating);
                if ((eRating < 0.0 || eRating > 5.0))
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
            } while ((eRating < 0.0 || eRating > 5.0));
            mTotalRating += mRating;
            eTotalRating += eRating;
        }
    }
    else if (month == 9)
    {
        for (day = 1; day <= LOG_DAYS; day++)
        {
            printf("\n%d-SEP-%.2d\n", year, day);
            do
            {
                printf("   Morning rating (0.0-5.0): ");
                scanf("%lf", &mRating);
                if ((mRating < 0.0 || mRating > 5.0))
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
            } while ((mRating < 0.0 || mRating > 5.0));
            do
            {
                printf("   Evening rating (0.0-5.0): ");
                scanf("%lf", &eRating);
                if ((eRating < 0.0 || eRating > 5.0))
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
            } while ((eRating < 0.0 || eRating > 5.0));
            mTotalRating += mRating;
            eTotalRating += eRating;
        }
    }
    else if (month == 10)
    {
        for (day = 1; day <= LOG_DAYS; day++)
        {
            printf("\n%d-OCT-%.2d\n", year, day);
            do
            {
                printf("   Morning rating (0.0-5.0): ");
                scanf("%lf", &mRating);
                if ((mRating < 0.0 || mRating > 5.0))
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
            } while ((mRating < 0.0 || mRating > 5.0));
            do
            {
                printf("   Evening rating (0.0-5.0): ");
                scanf("%lf", &eRating);
                if ((eRating < 0.0 || eRating > 5.0))
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
            } while ((eRating < 0.0 || eRating > 5.0));
            mTotalRating += mRating;
            eTotalRating += eRating;
        }
    }
    else if (month == 11)
    {
        for (day = 1; day <= LOG_DAYS; day++)
        {
            printf("\n%d-NOV-%.2d\n", year, day);
            do
            {
                printf("   Morning rating (0.0-5.0): ");
                scanf("%lf", &mRating);
                if ((mRating < 0.0 || mRating > 5.0))
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
            } while ((mRating < 0.0 || mRating > 5.0));
            do
            {
                printf("   Evening rating (0.0-5.0): ");
                scanf("%lf", &eRating);
                if ((eRating < 0.0 || eRating > 5.0))
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
            } while ((eRating < 0.0 || eRating > 5.0));
            mTotalRating += mRating;
            eTotalRating += eRating;
        }
    }
    else if (month == 12)
    {
        for (day = 1; day <= LOG_DAYS; day++)
        {
            printf("\n%d-DEC-%.2d\n", year, day);
            do
            {
                printf("   Morning rating (0.0-5.0): ");
                scanf("%lf", &mRating);
                if ((mRating < 0.0 || mRating > 5.0))
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
            } while ((mRating < 0.0 || mRating > 5.0));
            do
            {
                printf("   Evening rating (0.0-5.0): ");
                scanf("%lf", &eRating);
                if ((eRating < 0.0 || eRating > 5.0))
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
            } while ((eRating < 0.0 || eRating > 5.0));
            mTotalRating += mRating;
            eTotalRating += eRating;
        }

    }
    printf("\nSummary");
    printf("\n=======");
    printf("\nMorning total rating: %5.3lf",mTotalRating);
    printf("\nEvening total rating: %6.3lf",eTotalRating);
    printf("\n----------------------------");
    printf("\nOverall total rating: %5.3lf\n",(mTotalRating + eTotalRating));
    printf("\nAverage morning rating: %4.1lf",mTotalRating/LOG_DAYS);
    printf("\nAverage evening rating: %4.1lf",eTotalRating/LOG_DAYS);
    printf("\n----------------------------");
    printf("\nAverage overall rating: %4.1lf\n",(mTotalRating + eTotalRating)/(LOG_DAYS*2));



        return 0;
}