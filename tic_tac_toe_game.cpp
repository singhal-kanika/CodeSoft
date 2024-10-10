#include <iostream>

using namespace std;

const int SIZE = 3;
char board[SIZE][SIZE] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char currentMarker;
int currentPlayer;

void drawBoard()
{
    cout << "Current Board:" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool placeMarker(int slot)
{
    int row = (slot - 1) / SIZE;
    int col = (slot - 1) % SIZE;

    if (board[row][col] != 'X' && board[row][col] != 'O')
    {
        board[row][col] = currentMarker;
        return true;
    }
    return false;
}

int checkWin()
{

    for (int i = 0; i < SIZE; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return currentPlayer;
    }

    for (int i = 0; i < SIZE; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return currentPlayer;
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return currentPlayer;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return currentPlayer;

    return 0;
}
bool checkDraw()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
        }
    }
    return true;
}

void switchPlayer()
{
    if (currentPlayer == 1)
    {
        currentPlayer = 2;
        currentMarker = 'O';
    }
    else
    {
        currentPlayer = 1;
        currentMarker = 'X';
    }
}

void playGame()
{
    int winner = 0;
    bool draw = false;
    int slot;

    cout << "Player 1, choose your marker (X or O): ";
    char markerP1;
    cin >> markerP1;

    currentPlayer = 1;
    currentMarker = markerP1;
    char markerP2 = (markerP1 == 'X') ? 'O' : 'X';

    drawBoard();

    while (winner == 0 && !draw)
    {
        cout << "Player " << currentPlayer << "'s turn. Enter your slot (1-9): ";
        cin >> slot;

        if (slot < 1 || slot > 9 || !placeMarker(slot))
        {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        drawBoard();
        winner = checkWin();
        draw = checkDraw();
        if (winner == 0 && !draw)
            switchPlayer();
    }

    if (winner != 0)
    {
        cout << "Player " << winner << " wins!" << endl;
    }
    else if (draw)
    {
        cout << "It's a draw!" << endl;
    }
}

int main()
{
    char playAgain = 'Y';
    do
    {
        playGame();
        cout << "Do you want to play again? (Y/N): ";
        cin >> playAgain;

        char initialBoard[SIZE][SIZE] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                board[i][j] = initialBoard[i][j];
            }
        }

    } while (playAgain == 'Y' || playAgain == 'y');

    return 0;
}
