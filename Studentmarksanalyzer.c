#include <stdio.h>

#define MAX 100

// Function declarations
void inputMarks(int marks[], int n);
void displayMarks(int marks[], int n);
int highestMarks(int marks[], int n);
int lowestMarks(int marks[], int n);
int totalMarks(int marks[], int n);
float averageMarks(int marks[], int n);
void searchMarks(int marks[], int n);
void sortMarks(int marks[], int n);

int main()
{
    int marks[MAX], n, choice;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    inputMarks(marks, n);

    do
    {
        printf("\n===== Student Marks Analyzer =====\n");
        printf("1. Display Marks\n");
        printf("2. Highest Marks\n");
        printf("3. Lowest Marks\n");
        printf("4. Total Marks\n");
        printf("5. Average Marks\n");
        printf("6. Search Student Marks\n");
        printf("7. Sort Marks (Ascending)\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                displayMarks(marks, n);
                break;

            case 2:
                printf("Highest Marks = %d\n", highestMarks(marks, n));
                break;

            case 3:
                printf("Lowest Marks = %d\n", lowestMarks(marks, n));
                break;

            case 4:
                printf("Total Marks = %d\n", totalMarks(marks, n));
                break;

            case 5:
                printf("Average Marks = %.2f\n", averageMarks(marks, n));
                break;

            case 6:
                searchMarks(marks, n);
                break;

            case 7:
                sortMarks(marks, n);
                printf("Marks sorted successfully.\n");
                displayMarks(marks, n);
                break;

            case 8:
                printf("Thank you!\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while(choice != 8);

    return 0;
}

// Function to input marks
void inputMarks(int marks[], int n)
{
    int i;
    printf("\nEnter student marks:\n");
    for(i = 0; i < n; i++)
    {
        printf("Student %d: ", i + 1);
        scanf("%d", &marks[i]);
    }
}

// Function to display marks
void displayMarks(int marks[], int n)
{
    int i;
    printf("\nStudent Marks:\n");
    for(i = 0; i < n; i++)
    {
        printf("Student %d = %d\n", i + 1, marks[i]);
    }
}

// Function to find highest marks
int highestMarks(int marks[], int n)
{
    int i, max = marks[0];

    for(i = 1; i < n; i++)
    {
        if(marks[i] > max)
            max = marks[i];
    }

    return max;
}

// Function to find lowest marks
int lowestMarks(int marks[], int n)
{
    int i, min = marks[0];

    for(i = 1; i < n; i++)
    {
        if(marks[i] < min)
            min = marks[i];
    }

    return min;
}

// Function to calculate total marks
int totalMarks(int marks[], int n)
{
    int i, sum = 0;

    for(i = 0; i < n; i++)
        sum += marks[i];

    return sum;
}

// Function to calculate average
float averageMarks(int marks[], int n)
{
    return (float)totalMarks(marks, n) / n;
}

// Function to search marks
void searchMarks(int marks[], int n)
{
    int i, key, found = 0;

    printf("Enter marks to search: ");
    scanf("%d", &key);

    for(i = 0; i < n; i++)
    {
        if(marks[i] == key)
        {
            printf("Marks found for Student %d\n", i + 1);
            found = 1;
        }
    }

    if(found == 0)
        printf("Marks not found.\n");
}

// Function to sort marks (Ascending)
void sortMarks(int marks[], int n)
{
    int i, j, temp;

    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(marks[i] > marks[j])
            {
                temp = marks[i];
                marks[i] = marks[j];
                marks[j] = temp;
            }
        }
    }
}