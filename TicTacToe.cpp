#include <iostream>
#include <string>
using namespace std;

char space[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
string p1 = "";
string p2 = "";
int row;
int col;
char token = 'x';
bool tie = false;

void DisplayBoard()
{
    cout << "  |      |    \n";
    cout << " " << space[0][0] << "| " << space[0][1] << "    | " << space[0][2] << " \n";
    cout << "__|______|___\n";
    cout << "  |      |    \n";
    cout << " " << space[1][0] << "| " << space[1][1] << "    | " << space[1][2] << " \n";
    cout << "__|______|___\n";
    cout << "  |      |    \n";
    cout << " " << space[2][0] << "| " << space[2][1] << "    | " << space[2][2] << " \n";
    cout << "  |      |    \n";
}

void PlayerMove()
{
    int digit;
    
    if (token == 'x')
    {
        cout << p1 << ", please enter a number: ";
        cin >> digit;
    }
    else
    {
        cout << p2 << ", please enter a number: ";
        cin >> digit;
    }
    
    switch (digit)
    {
        case 1: row = 0; col = 0; break;
        case 2: row = 0; col = 1; break;
        case 3: row = 0; col = 2; break;
        case 4: row = 1; col = 0; break;
        case 5: row = 1; col = 1; break;
        case 6: row = 1; col = 2; break;
        case 7: row = 2; col = 0; break;
        case 8: row = 2; col = 1; break;
        case 9: row = 2; col = 2; break;
        default:
            cout << "Invalid input! Try again." << endl;
            PlayerMove();
            return;
    }
    
    if (space[row][col] != 'x' && space[row][col] != '0')
    {
        space[row][col] = token;
        token = (token == 'x') ? '0' : 'x';
    }
    else
    {
        cout << "This spot is already taken! Try again." << endl;
        PlayerMove();
    }
}

bool CheckWin()
{
    // Check rows and columns
    for (int i = 0; i < 3; i++)
    {
        if ((space[i][0] == space[i][1] && space[i][1] == space[i][2]) || 
            (space[0][i] == space[1][i] && space[1][i] == space[2][i]))
            return true;
    }
    
    // Check diagonals
    if ((space[0][0] == space[1][1] && space[1][1] == space[2][2]) ||
        (space[0][2] == space[1][1] && space[1][1] == space[2][0]))
        return true;
    
    // Check for tie
    tie = true;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (space[i][j] != 'x' && space[i][j] != '0')
            {
                tie = false;
                return false;
            }
        }
    }
    
    return false;
}

int main()
{
    cout << "Enter the name of Player1: ";
    getline(cin, p1);
    cout << "Enter the name of Player2: ";
    getline(cin, p2);
    
    cout << p1 << " is Player 1 and will play first.\n";
    cout << p2 << " is Player 2 and will play second.\n";

    while (!CheckWin())
    {
        DisplayBoard();
        PlayerMove();
        if (CheckWin())
            break;
    }

    DisplayBoard();
    
    if (tie)
    {
        cout << "It's a draw!" << endl;
    }
    else
    {
        if (token == 'x')
            cout << p2 << " wins!" << endl;
        else
            cout << p1 << " wins!" << endl;
    }

    return 0;
}
