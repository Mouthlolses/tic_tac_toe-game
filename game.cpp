#include <iostream>
using namespace std;

char board[3][3] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};

void displayBoard() {
    cout << board[0][0] << " | " << board [0][1] << " | " << board[0][2] << endl;
    cout << "---------\n";
    cout << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "---------\n";
    cout << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;

}

bool winner()
{
    for(int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;

    return false;
}

bool loot()
{
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') return false;
        }
    }
    return true;
}

void makeMove(char player)
{
    int pos;
    cout << "Player " << player << ", escolha uma posicao (1-9): "; cin >> pos;

    int i = (pos - 1) / 3;
    int j = (pos - 1) % 3;

    if (board[i][j] == 'X' || board[i][j] == 'O') {
        cout << "Posicao ocupada! Tente novamente.\n";
        makeMove(player);
    } else {
        board[i][j] = player;
    }
}

int main()
{
    char player = 'X';

    while (true) {
        displayBoard();
        makeMove(player);

        if (winner()) {
            displayBoard();
            cout << "Player " << player << " winner!\n";
            break;
        }
        if (loot()) {
            displayBoard();
            cout << "Deu velha!\n";
            break;
        }
        player = (player == 'X') ? 'O' : 'X';
    }
}