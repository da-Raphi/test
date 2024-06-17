#include <stdio.h>


void printBoard(char board[3][3]) ;



int checkWin(char board[3][3], char player) ;


int main() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int position;
    char currentPlayer = 'X';

    printf("Willkommen zu Tic-Tac-Toe!\n");

    for (int i = 0; i < 9; ++i) {

        printBoard(board);


        printf("Spieler %c, gib deine Position:", currentPlayer);
        scanf("%d", &position);


        int row = (position - 1) / 3;
        int col = (position - 1) % 3;


        if (position < 1 || position > 9 || board[row][col] != ' ') {
            printf("Ungültige Position! Bitte gib eine gültige Position ein.\n");
            --i;
            continue;
        }


        board[row][col] = currentPlayer;


        if (checkWin(board, currentPlayer)) {
            printf("\nSpieler %c hat gewonnen!\n", currentPlayer);
            printBoard(board);
            return 0;
        }


        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }


    printf("Unentschieden!\n");
    printBoard(board);

    return 0;
}


int checkWin(char board[3][3], char player) {

    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return 1;
        }
    }

    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return 1;
    }
    return 0;
}

void printBoard(char board[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; ++i) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i < 2)
            printf("---+---+---\n");
    }
    printf("\n");
}