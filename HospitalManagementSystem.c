#include <stdio.h>
#include <string.h>

#define MAX 100

// Structure to store patient details
struct Patient
{
    int id;
    char name[50];
    int age;
    char gender[10];
    char disease[50];
};

struct Patient patient[MAX];
int totalPatients = 0;

// Function to add a patient
void addPatient()
{
    printf("\nEnter Patient ID: ");
    scanf("%d", &patient[totalPatients].id);

    printf("Enter Patient Name: ");
    scanf(" %[^\n]", patient[totalPatients].name);

    printf("Enter Age: ");
    scanf("%d", &patient[totalPatients].age);

    printf("Enter Gender: ");
    scanf("%s", patient[totalPatients].gender);

    printf("Enter Disease: ");
    scanf(" %[^\n]", patient[totalPatients].disease);

    totalPatients++;

    printf("\nPatient Added Successfully!\n");
}

// Function to display all patients
void displayPatients()
{
    if(totalPatients == 0)
    {
        printf("\nNo Patient Records Found.\n");
        return;
    }

    printf("\n========== Patient Records ==========\n");

    for(int i = 0; i < totalPatients; i++)
    {
        printf("\nPatient %d\n", i + 1);
        printf("ID      : %d\n", patient[i].id);
        printf("Name    : %s\n", patient[i].name);
        printf("Age     : %d\n", patient[i].age);
        printf("Gender  : %s\n", patient[i].gender);
        printf("Disease : %s\n", patient[i].disease);
    }
}

// Function to search patient by ID
void searchPatient()
{
    int id, found = 0;

    printf("\nEnter Patient ID: ");
    scanf("%d", &id);

    for(int i = 0; i < totalPatients; i++)
    {
        if(patient[i].id == id)
        {
            printf("\nPatient Found\n");
            printf("ID      : %d\n", patient[i].id);
            printf("Name    : %s\n", patient[i].name);
            printf("Age     : %d\n", patient[i].age);
            printf("Gender  : %s\n", patient[i].gender);
            printf("Disease : %s\n", patient[i].disease);

            found = 1;
            break;
        }
    }

    if(!found)
        printf("\nPatient Not Found.\n");
}

// Main Function
int main()
{
    int choice;

    while(1)
    {
        printf("\n=================================\n");
        printf(" HOSPITAL MANAGEMENT SYSTEM\n");
        printf("=================================\n");
        printf("1. Add Patient\n");
        printf("2. Display All Patients\n");
        printf("3. Search Patient\n");
        printf("4. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addPatient();
                break;

            case 2:
                displayPatients();
                break;

            case 3:
                searchPatient();
                break;

            case 4:
                printf("\nThank You!\n");
                return 0;

            default:
                printf("\nInvalid Choice!\n");
        }
    }

    return 0;
}