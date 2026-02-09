#include <iostream>
using namespace std;

char board[3][3] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};

char currentPlayer = 'X';

void drawBoard() {
    system("cls"); // Use "clear" for Linux/Mac
    cout << "\n Tic Tac Toe Game\n\n";
    cout << " Player 1 (X)  -  Player 2 (O)\n\n";

    for(int i = 0; i < 3; i++) {
        cout << " ";
        for(int j = 0; j < 3; j++) {
            cout << board[i][j];
            if(j < 2) cout << " | ";
        }
        cout << endl;
        if(i < 2) cout << " ---+---+---\n";
    }
    cout << endl;
}

bool isWinner() {
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return true;
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return true;
    }

    if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return true;

    if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return true;

    return false;
}

bool isDraw() {
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

void makeMove() {
    int choice;
    cout << "Player " << currentPlayer << ", enter your move (1-9): ";
    cin >> choice;

    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if(choice < 1 || choice > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
        cout << "Invalid move! Try again.\n";
        system("pause");
        makeMove();
    } else {
        board[row][col] = currentPlayer;
    }
}

int main() {
    char choice;
    do {
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                board[i][j] = '1' + i*3 + j;

        currentPlayer = 'X';

        while(true) {
            drawBoard();
            makeMove();

            if(isWinner()) {
                drawBoard();
                cout << " Player " << currentPlayer << " Wins!\n";
                break;
            }

            if(isDraw()) {
                drawBoard();
                cout << " It's a Draw!\n";
                break;
            }

            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }

        cout << "\nPlay Again? (y/n): ";
        cin >> choice;

    } while(choice == 'y' || choice == 'Y');

    return 0;
}
