#include <stdio.h>
#include <stdlib.h>

// Function declarations
void inputMarks(int *marks, int n);
void displayMarks(int *marks, int n);
int highestMarks(int *marks, int n);
int lowestMarks(int *marks, int n);
int totalMarks(int *marks, int n);
float averageMarks(int *marks, int n);

int main()
{
    int *marks;
    int n;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Dynamically allocate memory
    marks = (int *)malloc(n * sizeof(int));

    if (marks == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    inputMarks(marks, n);

    printf("\nStudent Marks:\n");
    displayMarks(marks, n);

    printf("\nHighest Marks : %d\n", highestMarks(marks, n));
    printf("Lowest Marks  : %d\n", lowestMarks(marks, n));
    printf("Total Marks   : %d\n", totalMarks(marks, n));
    printf("Average Marks : %.2f\n", averageMarks(marks, n));

    // Free allocated memory
    free(marks);
    marks = NULL;

    printf("\nMemory released successfully.\n");

    return 0;
}

// Function to input marks
void inputMarks(int *marks, int n)
{
    int i;

    printf("Enter marks:\n");

    for(i = 0; i < n; i++)
    {
        printf("Student %d: ", i + 1);
        scanf("%d", (marks + i));
    }
}

// Function to display marks
void displayMarks(int *marks, int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        printf("Student %d = %d\n", i + 1, *(marks + i));
    }
}

// Function to find highest marks
int highestMarks(int *marks, int n)
{
    int i, max = *marks;

    for(i = 1; i < n; i++)
    {
        if(*(marks + i) > max)
            max = *(marks + i);
    }

    return max;
}

// Function to find lowest marks
int lowestMarks(int *marks, int n)
{
    int i, min = *marks;

    for(i = 1; i < n; i++)
    {
        if(*(marks + i) < min)
            min = *(marks + i);
    }

    return min;
}

// Function to calculate total
int totalMarks(int *marks, int n)
{
    int i, sum = 0;

    for(i = 0; i < n; i++)
    {
        sum += *(marks + i);
    }

    return sum;
}

// Function to calculate average
float averageMarks(int *marks, int n)
{
    return (float)totalMarks(marks, n) / n;
}