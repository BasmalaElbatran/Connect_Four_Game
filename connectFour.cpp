#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout << "Program has started!" << endl;
    char board[4][4] = {
        {'-', '-', '-', '-'},
        {'-', '-', '-', '-'},
        {'-', '-', '-', '-'},
        {'-', '-', '-', '-'}};

    // print current board
    cout << "Current board is:" << endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
    char userChoice = 'n';
    bool winner = false;
    int playerTurn = 1; // by default player one
    string player = "one";
    char currElement = 'x';
    int row, col;
    int prevRow, prevCol;

    while (winner == false)
    {

        if (playerTurn % 2 != 0)
        {
            player = "one";
            currElement = 'x';
        }
        else
        {
            player = "two";
            currElement = 'o';
        };
        cout << "It's Player " + player + " turn to play!" << endl;
        cout << "☺️Please enter row & col corresponds to an empty cell:" << endl;
        cin >> row >> col;
        cout << endl;

        // validate input
        while (row > 4 || row < 1 || col > 4 || col < 1)
        {
            cout << "Error!! Please enter any row or column from 1 to 4: " << endl;
            cin >> row >> col;
            cout << endl;
        }
        while (board[row - 1][col - 1] != '-')
        {
            cout << "Error!! this place is taken! " << endl;
            cin >> row >> col;
            cout << endl;
        }
        // update the player's turn
        ++playerTurn;
        // update board after this move
        board[--row][--col] = currElement;

        cout << "Current board is:" << endl;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                cout << board[i][j] << ' ';
            }
            cout << endl;
        }
        // Check after each move if there is a winner
        //==============================rows check===========================
        // 1st row check
        if (board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][2] == board[0][3] && board[0][1] != '-')
        {
            winner = true;
            if (board[0][0] == 'x')
            {
                player = "one";
            }
            else
            {
                player = "two";
            }
        }
        // 2nd row check
        else if (board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][2] == board[1][3] && board[1][1] != '-')
        {
            winner = true;
            if (board[1][0] == 'x')
            {
                player = "one";
            }
            else
            {
                player = "two";
            }
        }
        // 3rd row check
        else if (board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][2] == board[2][3] && board[2][1] != '-')
        {
            winner = true;
            if (board[2][0] == 'x')
            {
                player = "one";
            }
            else
            {
                player = "two";
            }
        }
        // 4th row check
        else if (board[3][0] == board[3][1] && board[3][1] == board[3][2] && board[3][2] == board[3][3] && board[3][1] != '-')
        {
            winner = true;
            if (board[3][0] == 'x')
            {
                player = "one";
            }
            else
            {
                player = "two";
            }
        }
        //===================cols check=========================
        // 1st col check
        if (board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[2][0] == board[3][0] && board[0][0] != '-')
        {
            winner = true;
            if (board[0][0] == 'x')
            {
                player = "one";
            }
            else
            {
                player = "two";
            }
        }
        // 2nd col check
        else if (board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[2][1] == board[3][1] && board[0][1] != '-')
        {
            winner = true;
            if (board[0][1] == 'x')
            {
                player = "one";
            }
            else
            {
                player = "two";
            }
        }
        // 3rd col check
        else if (board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[2][2] == board[3][2] && board[0][2] != '-')
        {
            winner = true;
            if (board[0][2] == 'x')
            {
                player = "one";
            }
            else
            {
                player = "two";
            }
        }
        // 4th col check
        else if (board[0][3] == board[1][3] && board[1][3] == board[2][3] && board[2][3] == board[3][3] && board[0][3] != '-')
        {
            winner = true;
            if (board[0][3] == 'x')
            {
                player = "one";
            }
            else
            {
                player = "two";
            }
        }
        // diagonals check
        //  left diagonal check
        else if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == board[3][3] && board[0][0] != '-')
        {
            winner = true;
            if (board[0][0] == 'x')
            {
                player = "one";
            }
            else
            {
                player = "two";
            }
        }
        // right diagonal check
        else if (board[0][3] == board[1][2] && board[1][2] == board[2][1] && board[2][1] == board[3][0] && board[0][3] != '-')
        {
            winner = true;
            if (board[0][3] == 'x')
            {
                player = "one";
            }
            else
            {
                player = "two";
            }
        }

        if (winner == true)
        {

            cout << "Congratulations! player " + player + " is the winner" << endl;
            cout << "Do you want to continue(y/n)?" << endl;
            cin >> userChoice;
            cout << endl;
            if (userChoice == 'y')
            {
                cout << "Let's play again!" << endl;
                // set winner to false
                winner = false;
                // initialize the board again
                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        board[i][j] = '-';
                    }
                }
                // print current board
                cout << "Current board is:" << endl;
                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        cout << board[i][j] << ' ';
                    }
                    cout << endl;
                }
            }
        }
    };
    return 0;
}