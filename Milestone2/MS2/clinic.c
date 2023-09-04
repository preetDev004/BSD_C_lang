/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 2


Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"


//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
           "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient *patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
               "Number: %05d\n"
               "Phone : ",
               patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
               patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}

//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData *data)
{
    int selection;

    do
    {
        printf("Veterinary Clinic System\n"
               "=========================\n"
               "1) PATIENT     Management\n"
               "2) APPOINTMENT Management\n"
               "-------------------------\n"
               "0) Exit System\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            clearInputBuffer();
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            printf("<<< Feature not yet available >>>\n\n");
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do
    {
        printf("Patient Management\n"
               "=========================\n"
               "1) VIEW   Patient Data\n"
               "2) SEARCH Patients\n"
               "3) ADD    Patient\n"
               "4) EDIT   Patient\n"
               "5) REMOVE Patient\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            suspend();
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient *patient)
{
    int selection;
    do
    {
        printf("Edit Patient (%05d)\n"
               "=========================\n"
               "1) NAME : %s\n"
               "2) PHONE: ",
               patient->patientNumber, patient->name);

        displayFormattedPhone(patient->phone.number);

        printf("\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            clearInputBuffer();
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            clearInputBuffer();
            inputPhoneData(&patient->phone);
            printf("\nPatient record updated!\n\n");
        }

    } while (selection);
}

// ---------------------------------------------------------------------------
// !!! Put all the remaining function definitions below !!!
// Note: Maintain the same order/sequence as it is listed in the header file
// ---------------------------------------------------------------------------

// Display's all patient data in the FMT_FORM | FMT_TABLE format
void displayAllPatients(const struct Patient patient[], int max, int fmt)
{
    int i, found = 0;
    clearInputBuffer();
    if (fmt == FMT_TABLE)
    {
        displayPatientTableHeader();
    }
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber != 0)
        {
            displayPatientData(&patient[i], fmt);
            found = 1;
        }
    }
    if (found == 0)
    {
        printf("\n*** No records found ***\n");
    }
    printf("\n");
}

// Search for a patient record based on patient number or phone number
void searchPatientData(const struct Patient patient[], int max)
{
    int searchOption;

    do
    {

        printf("Search Options\n");
        printf("==========================\n");
        printf("1) By patient number\n");
        printf("2) By phone number\n");
        printf("..........................\n");
        printf("0) Previous menu\n");
        printf("..........................\n");
        printf("Selection: ");
        searchOption = inputIntRange(0, 2);
        switch (searchOption)
        {
        case 1:
            searchPatientByPatientNumber(patient, max);
            printf("\n");
            clearInputBuffer();
            suspend();
            break;
        case 2:
            searchPatientByPhoneNumber(patient, max);
            printf("\n");
            clearInputBuffer();
            suspend();
            break;
        }
        if (!searchOption)
        {
            printf("\n");
        }
        

    } while (searchOption);
}

// Add a new patient record to the patient array
void addPatient(struct Patient patient[], int max)
{
    int index = -1, i; // this is index variable which will be used for either showing error or storing the empty space index.
    for (i = 0; i < max; i++)
    {
        // printf("%d",patient[i].patientNumber);
        if (patient[i].patientNumber == 0)
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        printf("ERROR: Patient listing is FULL!\n");
    }
    else
    {
        // printf("((%d))",patient[index].patientNumber);
        patient[index].patientNumber = nextPatientNumber(patient, max);
        clearInputBuffer();
        inputPatient(&patient[index]);
        printf("\n*** New patient record added ***\n");
    }
    printf("\n");
    clearInputBuffer();
}

// Edit a patient record from the patient array
void editPatient(struct Patient patient[], int max)
{
    int patientId, index;
    printf("Enter the patient number: ");
    scanf("%d", &patientId);
    printf("\n");
    index = findPatientIndexByPatientNum(patientId, patient, max);
    if (index == -1)
    {
        printf("ERROR: Patient record not found!\n\n");
    }
    else
    {
        menuPatientEdit(&patient[index]);
    }
    clearInputBuffer();
    
}

// Remove a patient record from the patient array
void removePatient(struct Patient patient[], int max)
{
    int patientId, index;
    char confirmation;
    printf("Enter the patient number: ");
    scanf("%d", &patientId);
    index = findPatientIndexByPatientNum(patientId, patient, max);
    if (index != -1)
    {
        printf("\n");
        displayPatientData(&patient[index], FMT_FORM);
        printf("\nAre you sure you want to remove this patient record? (y/n): ");
        clearInputBuffer();
        confirmation = getchar();
        if (confirmation == 'y')
        {
            patient[index].patientNumber = 0;
            printf("Patient record has been removed!\n");
        }
        else
        {
            printf("Operation aborted.\n");
        }
    }
    else
    {
        printf("\nERROR: Patient record not found!\n");
    }
    printf("\n");
    clearInputBuffer();
}

//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
void searchPatientByPatientNumber(const struct Patient patient[], int max)
{
    int patientId, index;
    printf("\nSearch by patient number: ");
    scanf("%d", &patientId);
    index = findPatientIndexByPatientNum(patientId, patient, max);
    if (index == -1)
    {
        printf("\n*** No records found ***\n");
    }
    else
    {
        printf("\n");
        displayPatientData(&patient[index], FMT_FORM);
    }
}

// Search and display patient records by phone number (tabular)
void searchPatientByPhoneNumber(const struct Patient patient[], int max)
{
    int i = 0, found = 0;
    char phoneNumber[PHONE_LEN + 1];
    printf("\nSearch by phone number: ");
    scanf("%s", phoneNumber);
    printf("\n");
    displayPatientTableHeader();
    for (i = 0; i < max; i++)
    {
        if ((strcmp(patient[i].phone.number, phoneNumber)) == 0)
        {
            found++;
            if (found == 1)
            {
            }
            displayPatientData(&patient[i], FMT_TABLE);
        }
    }
    if (found == 0)
    {
        printf("\n*** No records found ***\n");
    }
}

// Get the next highest patient number
int nextPatientNumber(const struct Patient patient[], int max)
{

    int i;
    int nextNumber = 1;
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber >= nextNumber)
        {
            nextNumber = patient[i].patientNumber + 1;
        }
    }
    return nextNumber;
}

// Find the patient array index by patient number (returns -1 if not found)
int findPatientIndexByPatientNum(int patientNumber, const struct Patient patient[], int max)
{
    int i;
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber == patientNumber)
        {
            return i;
        }
    }

    return -1;
}

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
void inputPatient(struct Patient *patient)
{
    int i = 0;
    char c;
    printf("Patient Data Input\n");
    printf("------------------\n");
    printf("Number: %05d\n", patient->patientNumber);
    printf("Name  : ");
    while ((c = getchar()) != '\n')
    {
        patient->name[i] = c;
        i++;
    }
    patient->name[i] = '\0';
    printf("\n");
    inputPhoneData(&patient->phone);
}

// Get user input for phone contact information
void inputPhoneData(struct Phone *phone)
{
    int choice;
    printf("Phone Information\n");
    printf("-----------------\n");
    printf("How will the patient like to be contacted?\n");
    printf("1. Cell\n2. Home\n3. Work\n4. TBD\n");
    printf("Selection: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        strcpy(phone->description, "CELL");
        break;
    case 2:
        strcpy(phone->description, "HOME");
        break;
    case 3:
        strcpy(phone->description, "WORK");
        break;
    case 4:
        strcpy(phone->description, "TBD");
        break;

    default:
        break;
    }
    if (choice == 1 || choice == 2 || choice == 3)
    {
        printf("\nContact: %s", phone->description);
        printf("\nNumber : ");
        scanf("%s", phone->number);
    }
}