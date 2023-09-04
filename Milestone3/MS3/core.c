/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3


Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include "core.h"

//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

//
// Copy your work done from Milestone #2 (core.c) into this file
// - Organize your functions in the same order as they are listed in the core.h file
//
int inputInt()
{
    int valInt, isErr, flag = 1;
    do
    {
        isErr = scanf("%d", &valInt);
        if (isErr == 0)
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
        else
            flag = 0;
    } while (flag);
    return valInt;
}
int inputIntPositive()
{
    int positiveInt, flag = 1;
    do
    {
        scanf("%d", &positiveInt);
        if (positiveInt <= 0)
        {
            printf("ERROR! Value must be > 0: ");
        }
        else
            flag = 0;

    } while (flag);

    return positiveInt;
}
int inputIntRange(int a, int b)
{
    int tmp, isErr, flag = 1;
    do
    {
        isErr = scanf("%d", &tmp);
        if (isErr == 0)
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
        else if (tmp < a || tmp > b)
        {
            printf("ERROR! Value must be between %d and %d inclusive: ",a,b);
        }
        else
            flag = 0;
    } while (flag);
    return tmp;
}

char inputCharOption(const char str[])
{
    int i, len = 0, flag = 1;
    char opChar;

    // fine length of string - do not use library function for finding string length
    while ((str[len]) != '\0')
    {
        len++;
    }
    // use loop to check whether giveChar matches one of str characters
    while (flag)
    {
        opChar = getchar();
        clearInputBuffer();
        for (i = 0; i < len; i++)
        {
            if (opChar == str[i])
            {
                flag = 0;
            }
        }
        if (flag == 1)
        {
            printf("ERROR: Character must be one of [%s]: ", str);
        }
    }

    return opChar;
}

void inputCString(char *str, int l, int u)
{
    int exit = 1;
    do
    {
        int len = 0;
        char c;

        while ((c = getchar()) != '\n')
        {
            str[len] = c;
            len++;
        }
        str[len] = '\0';
        if ((len < l || len > u) && (l == u))
        {
            printf("ERROR: String length must be exactly %d chars: ", l);
        }
        else if (len < l)
        {
            printf("ERROR: String length must be between %d and %d chars: ", l, u);
        }
        else if (len > u)
        {
            printf("ERROR: String length must be no more than %d chars: ", u);
        }
        else
            exit = 0;

    } while (exit);
}

void displayFormattedPhone(const char *phone)
{
    int len = 0, digitLen = 0, i;
    if (phone != NULL)
    {
        while (phone[len] != '\0')
        {

            if (phone[len] >= 48 && phone[len] <= 57)
            {
                digitLen++;
            }
            len++;
        }
        if (digitLen == 10)
        {
            for (i = 0; i < digitLen; i++)
            {
                if (i == 0)
                {
                    printf("(");
                }
                else if (i == 3)
                {
                    printf(")");
                }
                else if (i == 6)
                {
                    printf("-");
                }
                printf("%c", phone[i]);
            }
        }
    }
    if ((digitLen < 10 || digitLen > 10) || phone == NULL)
    {
        printf("(___)___-____");
    }
}



//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

