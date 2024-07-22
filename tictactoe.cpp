#include <iostream>

using namespace std;

char board[3][3] = { {' ',' ',' '}, {' ',' ',' '}, {' ',' ',' '} };
char current_marker;
int current_player;

void drawBoard() {
    cout << "-------------\n";
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------\n";
    }
}

bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O' && board[row][col] == ' ') {
        board[row][col] = current_marker;
        return true;
    }
    return false;
}

int winner() {
    // Checking for  rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return current_player;
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return current_player;
        }
    }

    // Checking for diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return current_player;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return current_player;
    }

    return 0;
}

void swap_player_and_marker() {
    if (current_marker == 'X') {
        current_marker = 'O';
    } else {
        current_marker = 'X';
    }

    if (current_player == 1) {
        current_player = 2;
    } else {
        current_player = 1;
    }
}

void game() {
    cout << "Player 1, choose your marker (X or O): ";
    char marker_p1;
    cin >> marker_p1;

    current_player = 1;
    current_marker = marker_p1;

    drawBoard();

    int player_won;

    for (int i = 0; i < 9; i++) {
        cout << "It's player " << current_player << "'s turn. Enter your slot (1-9): ";
        int slot;
        cin >> slot;

        if (slot < 1 || slot > 9) {
            cout << "Invalid slot! Choose another slot!\n";
            i--;
            continue;
        }

        if (!placeMarker(slot)) {
            cout << "Slot occupied! Choose another slot!\n";
            i--;
            continue;
        }

        drawBoard();

        player_won = winner();

        if (player_won == 1) {
            cout << "Player 1 won! Congratulations!\n";
            break;
        }
        if (player_won == 2) {
            cout << "Player 2 won! Congratulations!\n";
            break;
        }

        swap_player_and_marker();
    }

    if (player_won == 0) {
        cout << "That's a tie game!\n";
    }
}

int main() {
    game();
    return 0;
}
