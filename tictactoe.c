#include <stdio.h>

char board[3][3];

// Function to initialize the board
void initializeBoard()
{
    char ch = '1';
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            board[i][j] = ch++;
        }
    }
}

// Function to display the board
void displayBoard()
{
    printf("\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

// Function to check winner
int checkWinner()
{
    // Rows
    for(int i = 0; i < 3; i++)
    {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return 1;
    }

    // Columns
    for(int i = 0; i < 3; i++)
    {
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return 1;
    }

    // Diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;

    if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;

    return 0;
}

// Check if board is full
int isBoardFull()
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board[i][j] != 'X' && board[i][j] != 'O')
                return 0;
        }
    }
    return 1;
}

// Main function
int main()
{
    int choice, row, col;
    char player = 'X';

    initializeBoard();

    while(1)
    {
        displayBoard();

        printf("Player %c, enter position (1-9): ", player);
        scanf("%d", &choice);

        if(choice < 1 || choice > 9)
        {
            printf("Invalid position! Try again.\n");
            continue;
        }

        row = (choice - 1) / 3;
        col = (choice - 1) % 3;

        if(board[row][col] == 'X' || board[row][col] == 'O')
        {
            printf("Position already taken! Try again.\n");
            continue;
        }

        board[row][col] = player;

        if(checkWinner())
        {
            displayBoard();
            printf("Player %c wins!\n", player);
            break;
        }

        if(isBoardFull())
        {
            displayBoard();
            printf("It's a Draw!\n");
            break;
        }

        if(player == 'X')
            player = 'O';
        else
            player = 'X';
    }

    return 0;
}