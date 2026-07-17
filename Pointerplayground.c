#include <stdio.h>

#define MAX 100

// Function declarations
void displayAddress(int *ptr);
void swap(int *a, int *b);
void traverseArray(int arr[], int n);
void pointerArithmetic(int arr[], int n);

int main()
{
    int num1, num2, n, arr[MAX];
    int *ptr;

    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter second number: ");
    scanf("%d", &num2);

    ptr = &num1;

    printf("\n===== Pointer Playground =====\n");

    // Display memory address
    printf("\n1. Memory Address and Dereferencing\n");
    displayAddress(ptr);

    // Swap numbers
    printf("\n2. Swapping Two Numbers Using Pointers\n");
    printf("Before Swap: num1 = %d, num2 = %d\n", num1, num2);
    swap(&num1, &num2);
    printf("After Swap : num1 = %d, num2 = %d\n", num1, num2);

    // Array Input
    printf("\nEnter number of elements in array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Traverse Array
    printf("\n3. Traversing Array Using Pointers\n");
    traverseArray(arr, n);

    // Pointer Arithmetic
    printf("\n4. Pointer Arithmetic\n");
    pointerArithmetic(arr, n);

    return 0;
}

// Function to display memory address and value
void displayAddress(int *ptr)
{
    printf("Memory Address = %p\n", (void *)ptr);
    printf("Value Stored   = %d\n", *ptr);
}

// Function to swap two numbers
void swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

// Function to traverse array using pointers
void traverseArray(int arr[], int n)
{
    int *ptr = arr;

    printf("Array Elements:\n");

    for(int i = 0; i < n; i++)
    {
        printf("%d ", *(ptr + i));
    }

    printf("\n");
}

// Function to demonstrate pointer arithmetic
void pointerArithmetic(int arr[], int n)
{
    int *ptr = arr;

    printf("Address\t\t\tValue\n");

    for(int i = 0; i < n; i++)
    {
        printf("%p\t%d\n", (void *)(ptr + i), *(ptr + i));
    }
}