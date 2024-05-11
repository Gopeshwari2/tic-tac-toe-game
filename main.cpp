#include <iostream>
#include <string>
using namespace std;

// Function to display the game board
void drawBoard(const char board[3][3]) {
    cout << "   |   |   " << endl;
    for (int r = 0; r < 3; r++) {
        cout << " " << board[r][0] << " | " << board[r][1] << " | " << board[r][2] << endl;
        if (r < 2) {
            cout << "___|___|___" << endl;
        }
    }
    cout << "   |   |   " << endl;
}

// Function to check if the player has won
bool checkWin(const char board[3][3], char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true; // Horizontal win
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true; // Vertical win
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true; // Diagonal from top-left to bottom-right
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true; // Diagonal from top-right to bottom-left
    return false;
}

int main() {
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    string playerNameX, playerNameO;
    cout << "Enter Player X's name: ";
    cin >> playerNameX;
    cout << "Enter Player O's name: ";
    cin >> playerNameO;

    char currentPlayer = 'X';
    int turnLimit = 9; // Total turns allowed

    while (true) {
        drawBoard(board);
        cout << "Current Player: " << (currentPlayer == 'X' ? playerNameX : playerNameO) << endl;
        cout << "Enter row (0-2) and column (0-2): ";
        int r, c;
        cin >> r >> c;

        if (r < 0 || r > 2 || c < 0 || c > 2 || board[r][c] != ' ') {
            cout << "Invalid move. Try again.\n";
            continue;
        }

        board[r][c] = currentPlayer;
        if (checkWin(board, currentPlayer)) {
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }

        if (turnLimit == 0) {
            cout << "It's a tie!\n";
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        turnLimit--;
    }

    return 0;
}
