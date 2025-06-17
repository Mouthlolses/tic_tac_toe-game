#include <iostream>
using namespace std;

char tabuleiro[3][3] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};

void exibirTabuleiro() {
    cout << tabuleiro[0][0] << " | " << tabuleiro [0][1] << " | " << tabuleiro[0][2] << endl;
    cout << "---------\n";
    cout << tabuleiro[1][0] << " | " << tabuleiro[1][1] << " | " << tabuleiro[1][2] << endl;
    cout << "---------\n";
    cout << tabuleiro[2][0] << " | " << tabuleiro[2][1] << " | " << tabuleiro[2][2] << endl;

}

bool winner()
{
    for(int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2]) return true;
        if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i]) return true;
    }
    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2]) return true;
    if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0]) return true;

    return false;
}

bool loot()
{
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if (tabuleiro[i][j] != 'X' && tabuleiro[i][j] != 'O') return false;
        }
    }
    return true;
}

void fazerJogada(char jogador)
{
    int pos;
    cout << "Jogador " << jogador << ", escolha uma posicao (1-9): "; cin >> pos;

    int i = (pos - 1) / 3;
    int j = (pos - 1) % 3;

    if (tabuleiro[i][j] == 'X' || tabuleiro[i][j] == 'O') {
        cout << "Posicao ocupada! Tente novamente.\n";
        fazerJogada(jogador);
    } else {
        tabuleiro[i][j] = jogador;
    }
}

int main()
{
    char jogador = 'X';

    while (true) {
        exibirTabuleiro();
        fazerJogada(jogador);

        if (winner()) {
            exibirTabuleiro();
            cout << "Jogador " << jogador << " venceu!\n";
            break;
        }
        if (loot()) {
            exibirTabuleiro();
            cout << "Deu velha!\n";
            break;
        }
        jogador = (jogador == 'X') ? 'O' : 'X';
    }
}