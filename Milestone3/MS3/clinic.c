/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3


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

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date *date, int isAllRecords)
{
    printf("Clinic Appointments for the Date: ");

    if (isAllRecords)
    {
        printf("<ALL>\n\n");
        printf("Date       Time  Pat.# Name            Phone#\n"
               "---------- ----- ----- --------------- --------------------\n");
    }
    else
    {
        printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
        printf("Time  Pat.# Name            Phone#\n"
               "----- ----- --------------- --------------------\n");
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient *patient,
                         const struct Appointment *appoint,
                         int includeDateField)
{
    if (includeDateField)
    {
        printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
               appoint->date.day);
    }
    printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
           patient->patientNumber, patient->name);

    displayFormattedPhone(patient->phone.number);

    printf(" (%s)\n", patient->phone.description);
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
            menuAppointment(data);
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
            inputPhoneData(&patient->phone);
            printf("\nPatient record updated!\n\n");
        }

    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Appointment Management
void menuAppointment(struct ClinicData *data)
{
    int selection;

    do
    {
        printf("Appointment Management\n"
               "==============================\n"
               "1) VIEW   ALL Appointments\n"
               "2) VIEW   Appointments by DATE\n"
               "3) ADD    Appointment\n"
               "4) REMOVE Appointment\n"
               "------------------------------\n"
               "0) Previous menu\n"
               "------------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 4);
        putchar('\n');
        switch (selection)
        {
        case 1:
            viewAllAppointments(data); // ToDo: You will need to create this function!
            suspend();
            break;
        case 2:
            viewAppointmentSchedule(data); // ToDo: You will need to create this function!
            suspend();
            break;
        case 3:
            addAppointment(data->appointments, data->maxAppointments,
                           data->patients, data->maxPatient); // ToDo: You will need to create this function!
            suspend();
            break;
        case 4:
            removeAppointment(data->appointments, data->maxAppointments,
                              data->patients, data->maxPatient); // ToDo: You will need to create this function!
            suspend();
            break;
        }
    } while (selection);
}

// ---------------------------------------------------------------------------
// !!! INSERT/COPY YOUR MS#2 FUNCTION DEFINITIONS BELOW... !!!
// Note: Maintain the same order/sequence as it is listed in the header file
//       Properly organize/categorize any new functions accordingly
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
    int index = -1, i;
    int tmp; // this is index variable which will be used for either showing error or storing the empty space index.

    for (i = 0; i < max; i++)
    {

        if (patient[i].patientNumber == 0)
        {
            index = i;
            tmp = patient[index + 1].patientNumber;
            break;
        }
    }
    if (index == -1)
    {
        printf("ERROR: Patient listing is FULL!\n");
    }
    else
    {
        patient[index].patientNumber = nextPatientNumber(patient, max);
        clearInputBuffer();
        inputPatient(&patient[index]);
        patient[index + 1].patientNumber = tmp;
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
    char confirmation[8];
    printf("Enter the patient number: ");
    scanf("%d", &patientId);
    index = findPatientIndexByPatientNum(patientId, patient, max);
    if (index != -1)
    {
        printf("\n");
        displayPatientData(&patient[index], FMT_FORM);
        printf("\nAre you sure you want to remove this patient record? (y/n): ");
        do
        {
            clearInputBuffer();
            scanf("%s", confirmation);
            if ((strlen(confirmation)) == 1)
            {

                if (confirmation[0] == 'y')
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
                printf("ERROR: Character must be one of [yn]: ");
            }
        } while ((strlen(confirmation)) != 1);
    }
    else
    {
        printf("\nERROR: Patient record not found!\n");
    }
    printf("\n");
    clearInputBuffer();
}
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// View ALL scheduled appointments
void viewAllAppointments(struct ClinicData *data)
{
    clearInputBuffer();
    int apptNum = 0, petNum = 0;
    int i, j;
    displayScheduleTableHeader(&data->appointments->date, ALL_APPOINTSMENTS);
    while (data->appointments[apptNum].date.day != 0)
    {
        apptNum++;
    }
    while (data->patients[petNum].patientNumber != 0)
    {
        petNum++;
    }

    // sorting
    bubbleSort(data->appointments, apptNum);

    for (j = 0; j < apptNum; j++)
    {
        for (i = 0; i < petNum; i++)
        {
            if (data->appointments[j].patientNumber == data->patients[i].patientNumber)
            {
                displayScheduleData(&data->patients[i], &data->appointments[j], FMT_TABLE);
            }
        }
    }

    printf("\n");
}

void viewAppointmentSchedule(struct ClinicData *data)
{
    clearInputBuffer();
    int appLen = 0, pateintLen = 0, i = 0, j, k;
    int year, isLeapYear = 0;
    int month;
    int day;
    int patientNum[MAX_APPOINTMENTS];

    printf("Year        : ");
    scanf("%d", &year);
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        isLeapYear = 1;
    }
    printf("Month (1-12): ");
    month = inputIntRange(1, 12);
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 1 || month == 12)
    {
        printf("Day (1-31)  : ");
        day = inputIntRange(1, 31);
    }
    else if (month == 2 && isLeapYear)
    {
        printf("Day (1-29)  : ");
        day = inputIntRange(1, 29);
    }
    else if (month == 2)
    {
        printf("Day (1-28)  : ");
        day = inputIntRange(1, 28);
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        printf("Day (1-30)  : ");
        day = inputIntRange(1, 30);
    }

    do
    {
        if ((data->appointments[appLen].date.year == year) && (data->appointments[appLen].date.month == month) &&
            (data->appointments[appLen].date.day == day))
        {

            patientNum[i] = data->appointments[appLen].patientNumber;
            if (i == 0)
            {
                printf("\n");
                displayScheduleTableHeader(&data->appointments[appLen].date, APPOINTMENTS_BY_DATE);
            }
            i++;
        }
        appLen++;

    } while (data->appointments[appLen].date.day != 0 && data->appointments[appLen].date.year != 0);
    do
    {
        if (data->patients[pateintLen].patientNumber != 0)
        {
            pateintLen++;
        }

    } while (data->patients[pateintLen].patientNumber != 0);

    // sorting
    bubbleSort(data->appointments, appLen);
    i = 0;
    for (j = 0; j < appLen; j++)
    {
        if (data->appointments[j].patientNumber == patientNum[i])
        {
            for (k = 0; k < pateintLen; k++)
            {

                if (data->patients[k].patientNumber == patientNum[i])
                {

                    displayScheduleData(&data->patients[k], &data->appointments[j], APPOINTMENTS_BY_DATE);
                }
            }
            i++;
        }
    }
    printf("\n");
    clearInputBuffer();
}

// Add an appointment record to the appointment array
void addAppointment(struct Appointment *appointments, int maxAppointments, struct Patient *patients, int maxPatient)
{
    clearInputBuffer();
    struct Date date;
    int patientNumber, i, isPatient = -1, isTimeslot;
    int hour;
    int minute;

    printf("Patient Number: ");
    scanf("%d", &patientNumber);
    isPatient = findPatientIndexByPatientNum(patientNumber, patients, maxPatient);
    if (isPatient == -1)
    {
        printf("\nNo Patient exists!\n");
    }
    else
    {
        do
        {
            isTimeslot = 1;
            date = inputDate();
            do
            {
                printf("Hour (0-23)  : ");
                scanf("%d", &hour);
                printf("Minute (0-59): ");
                scanf("%d", &minute);
                if (((hour < 10 || hour > 14) || (minute != 0 && minute != 30)) || (hour == 14 && minute == 30))
                {

                    printf("ERROR: Time must be between 10:00 and 14:00 in 30 minute intervals.\n\n");
                }

            } while (((hour < 10 || hour > 14) || (minute != 0 && minute != 30)) || (hour == 14 && minute == 30));

            i = 0;
            do
            {
                if ((appointments[i].date.year == date.year) && (appointments[i].date.month == date.month) &&
                    (appointments[i].date.day == date.day) && (appointments[i].time.hour == hour) &&
                    (appointments[i].time.min == minute))
                {
                    printf("\nERROR: Appointment timeslot is not available!\n\n");
                    isTimeslot = 0;
                }
                i++;
            } while (appointments[i].date.year != 0 && appointments[i].date.day != 0);

        } while (isTimeslot == 0);

        if (isTimeslot == 1)
        {
            appointments[i].patientNumber = patientNumber;
            appointments[i].date.year = date.year;
            appointments[i].date.month = date.month;
            appointments[i].date.day = date.day;
            appointments[i].time.hour = hour;
            appointments[i].time.min = minute;

            printf("\n*** Appointment scheduled! ***\n");
        }
    }
    printf("\n");
    clearInputBuffer();
}

// Remove an appointment record from the appointment array
void removeAppointment(struct Appointment *appointments, int maxAppointments, struct Patient *patients, int maxPatient)
{
    struct Date date;
    int patientNumber, i, isPatient = -1;
    char confirmation;

    printf("Patient Number: ");
    scanf("%d", &patientNumber);
    isPatient = findPatientIndexByPatientNum(patientNumber, patients, maxPatient);
    if (isPatient == -1)
    {
        printf("ERROR: Patient record not found!\n");
    }
    else
    {
        date = inputDate();
        i = 0;
        do
        {
            if ((appointments[i].date.year == date.year) && (appointments[i].date.month == date.month) &&
                (appointments[i].date.day == date.day && appointments[i].patientNumber == patientNumber))
            {
                printf("\n");
                displayPatientData(&patients[isPatient], FMT_FORM);
                printf("Are you sure you want to remove this appointment (y,n): ");
                clearInputBuffer();
                confirmation = getchar();
                if (confirmation == 'y')
                {

                    appointments[i].patientNumber = 0;
                    appointments[i].date.month = date.month;
                    printf("\nAppointment record has been removed!\n");
                }
                else
                {
                    printf("Operation aborted.");
                }
            }
            i++;
        } while (i < maxAppointments);
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

struct Date inputDate() {
    struct Date date;
    int isLeapYear = 0;

    printf("Year        : ");
    scanf("%d", &date.year);
    if ((date.year % 4 == 0 && date.year % 100 != 0) || (date.year % 400 == 0))
    {
        isLeapYear = 1;
    }
    printf("Month (1-12): ");
    date.month = inputIntRange(1, 12);
    if (date.month == 1 || date.month == 3 || date.month == 5 || date.month == 7 || date.month == 8 || date.month == 10 || date.month == 1 || date.month == 12)
    {
        printf("Day (1-31)  : ");
        date.day = inputIntRange(1, 31);
    }
    else if (date.month == 2 && isLeapYear)
    {
        printf("Day (1-29)  : ");
        date.day = inputIntRange(1, 29);
    }
    else if (date.month == 2)
    {
        printf("Day (1-28)  : ");
        date.day = inputIntRange(1, 28);
    }
    else if (date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11)
    {
        printf("Day (1-30)  : ");
        date.day = inputIntRange(1, 30);
    }

    return date;
}

void bubbleSort(struct Appointment *appointments, int n)
{
    int i, j;
    struct Appointment temp;
    // sorting
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {

            if (appointments[j].date.year > appointments[j + 1].date.year ||

                (appointments[j].date.year == appointments[j + 1].date.year &&
                 appointments[j].date.month > appointments[j + 1].date.month) ||

                (appointments[j].date.year == appointments[j + 1].date.year &&
                 appointments[j].date.month == appointments[j + 1].date.month &&
                 appointments[j].date.day > appointments[j + 1].date.day) ||

                (appointments[j].date.year == appointments[j + 1].date.year &&
                 appointments[j].date.month == appointments[j + 1].date.month &&
                 appointments[j].date.day == appointments[j + 1].date.day &&
                 appointments[j].time.hour > appointments[j + 1].time.hour) ||

                (appointments[j].date.year == appointments[j + 1].date.year &&
                 appointments[j].date.month == appointments[j + 1].date.month &&
                 appointments[j].date.day == appointments[j + 1].date.day &&
                 appointments[j].time.hour == appointments[j + 1].time.hour &&
                 appointments[j].time.min > appointments[j + 1].time.min))
            {
                temp = appointments[j];
                appointments[j] = appointments[j + 1];
                appointments[j + 1] = temp;
            }
        }
    }
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

        if (i <= 15)
        {
            patient->name[i] = c;
            i++;
        }
        else
        {
            printf("ERROR: String length must be no more than 15 chars: ");
            clearInputBuffer();
            i = 0;    // reset the counter
            continue; // start again from the beginning of the loop
        }
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
        printf("\nContact: %s\n", phone->description);
        int len;
        printf("Number : ");
        do
        {
            scanf("%s", phone->number);
            len = strlen(phone->number);
            if (len != 10)
            {
                printf("Invalid 10-digit number! ");
                printf("Number: ");
            }

        } while (len != 10);
    }
}

//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
int importPatients(const char *datafile, struct Patient patients[], int max)
{
    int i, status;
    FILE *fptr = NULL;
    char fname[MAX_FILE_NAME_LEN];
    strcpy(fname, datafile);
    fptr = fopen(fname, "r");
    if (fptr != NULL)
    {
        i = 0;
        status = 3;
        while (status >= 3 && i < max)
        {
            status = fscanf(fptr,
                            "%d|%[^|]|%[^|]|%[^\n]",
                            &patients[i].patientNumber, patients[i].name, patients[i].phone.description, patients[i].phone.number);
            if (status >= 3)
                i++;
        }
    }

    fclose(fptr);

    return i;
}

// Import appointment data from file into an Appointment array (returns # of records read)
int importAppointments(const char *datafile, struct Appointment appoints[], int max)
{
    int i, status;
    FILE *fptr = NULL;
    char fname[MAX_FILE_NAME_LEN];
    strcpy(fname, datafile);
    fptr = fopen(fname, "r");
    if (fptr != NULL)
    {
        i = 0;
        status = 6;
        while (status == 6 && i < max)
        {
            status = fscanf(fptr,
                            "%d,%d,%d,%d,%d,%d",
                            &appoints[i].patientNumber, &appoints[i].date.year, &appoints[i].date.month,
                            &appoints[i].date.day, &appoints[i].time.hour, &appoints[i].time.min);
            if (status == 6)
                i++;
        }
    }

    fclose(fptr);

    return i;
}



