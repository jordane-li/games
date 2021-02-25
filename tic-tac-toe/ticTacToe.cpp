#include <iostream>

using namespace std;

void printBoard(char board[][3]) {
    cout << "-----------" << endl;
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "-----------" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "-----------" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
    cout << "-----------" << endl;
}

bool win(char board[][3]) {
    if ((board[0][0]==board[0][1]&&board[0][1]==board[0][2]&&board[0][0]!=' ') ||
        (board[1][0]==board[1][1]&&board[1][1]==board[1][2]&&board[1][0]!=' ') ||
        (board[2][0]==board[2][1]&&board[2][1]==board[2][2]&&board[2][0]!=' '))
        return true;
    if ((board[0][0]==board[1][0]&&board[0][0]==board[2][0]&&board[0][0]!=' ') ||
        (board[0][1]==board[1][1]&&board[0][1]==board[2][1]&&board[0][1]!=' ') ||
        (board[0][2]==board[1][2]&&board[0][2]==board[2][2]&&board[0][2]!=' '))
        return true;
    if ((board[0][0]==board[1][1]&&board[0][0]==board[2][2]&&board[0][0]!=' ') ||
        (board[0][2]==board[1][1]&&board[0][2]==board[2][0]&&board[0][2]!=' '))
        return true;
    return false;
}

bool full(char board[][3]) {
    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
            if (board[i][j]==' ')
                    return false;
    return true;
}

void ticTacToe()
{
    char board[3][3];
    for (int i=0;i<3;i++)
        for (int j=0;j<3;j++)
            board[i][j]=' ';
    cout << "Game Started!" << endl;

    int time = 0; // game time
    int player; // 0: player1 use 'O', 1:player2 use 'X'
    int row, column;

    while (!(win(board)||full(board))) {
        player = time%2;
        printBoard(board);
        cout << "Player " << player << ", please input the row and column that you want to place your piece: ";
        cin >> row >> column;
        while (row<0||row>2||column<0||column>2||board[row][column]!=' ') {
            cout << "You can't place your piece here, please retry: ";
            cin>>row>>column;
        }

        if (player==0) board[row][column]='O';
        if (player==1) board[row][column]='X';

        time++;
    }

    printBoard(board);
    if (win(board)) {
        cout << "Player " << player << " has won the game!!!" << endl;
    }
    if (full(board)) {
        cout << "This is a tie!" << endl;
    }
}

int main()
{
    ticTacToe();
    return 0;
}
