#include <stdio.h>
#include <string.h>

#define MAX 100

// Function declarations
int stringLength(char str[]);
void reverseString(char str[]);
void checkPalindrome(char str[]);
void countVowelsDigitsSpaces(char str[]);
void characterFrequency(char str[]);

int main()
{
    char str[MAX];
    int choice;

    printf("Enter a string: ");
    fgets(str, MAX, stdin);

    // Remove newline character if present
    str[strcspn(str, "\n")] = '\0';

    do
    {
        printf("\n===== String Utility Toolkit =====\n");
        printf("1. Find String Length\n");
        printf("2. Reverse String\n");
        printf("3. Check Palindrome\n");
        printf("4. Count Vowels, Digits, and Spaces\n");
        printf("5. Display Character Frequency\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Length of String = %d\n", stringLength(str));
                break;

            case 2:
                reverseString(str);
                break;

            case 3:
                checkPalindrome(str);
                break;

            case 4:
                countVowelsDigitsSpaces(str);
                break;

            case 5:
                characterFrequency(str);
                break;

            case 6:
                printf("Exiting Program...\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while(choice != 6);

    return 0;
}

// Function to find string length
int stringLength(char str[])
{
    int i = 0;
    while(str[i] != '\0')
        i++;
    return i;
}

// Function to reverse string
void reverseString(char str[])
{
    int i, len = stringLength(str);

    printf("Reversed String: ");

    for(i = len - 1; i >= 0; i--)
        printf("%c", str[i]);

    printf("\n");
}

// Function to check palindrome
void checkPalindrome(char str[])
{
    int i, len = stringLength(str);
    int flag = 1;

    for(i = 0; i < len / 2; i++)
    {
        if(str[i] != str[len - i - 1])
        {
            flag = 0;
            break;
        }
    }

    if(flag)
        printf("The string is a Palindrome.\n");
    else
        printf("The string is NOT a Palindrome.\n");
}

// Function to count vowels, digits, and spaces
void countVowelsDigitsSpaces(char str[])
{
    int i;
    int vowels = 0, digits = 0, spaces = 0;

    for(i = 0; str[i] != '\0'; i++)
    {
        char ch = str[i];

        if(ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U'||
           ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
            vowels++;

        else if(ch >= '0' && ch <= '9')
            digits++;

        else if(ch == ' ')
            spaces++;
    }

    printf("Vowels : %d\n", vowels);
    printf("Digits : %d\n", digits);
    printf("Spaces : %d\n", spaces);
}

// Function to display character frequency
void characterFrequency(char str[])
{
    int freq[256] = {0};
    int i;

    for(i = 0; str[i] != '\0'; i++)
        freq[(unsigned char)str[i]]++;

    printf("\nCharacter Frequency:\n");

    for(i = 0; i < 256; i++)
    {
        if(freq[i] != 0)
            printf("%c : %d\n", i, freq[i]);
    }
}