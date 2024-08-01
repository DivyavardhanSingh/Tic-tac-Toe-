#include <stdio.h>

char board[3][3];
char currentPlayer;

void initializeBoard();
void printBoard();
void switchPlayer();
int makeMove(int row, int col);
int checkWin();
int checkDraw();

int main() {
    int row, col, gameStatus = 0;

    initializeBoard();
    currentPlayer = 'X';

    while (1) {
        printBoard();

        printf("Player %c, enter row (0-2) and column (0-2) for your move: ", currentPlayer);
        scanf("%d %d", &row, &col);

        if (makeMove(row, col)) {
            gameStatus = checkWin();
            if (gameStatus) break;
            if (checkDraw()) {
                gameStatus = 2;
                break;
            }
            switchPlayer();
        } else {
            printf("Invalid move, try again.\n");
        }
    }

    printBoard();
    if (gameStatus == 1) {
        printf("Player %c wins!\n", currentPlayer);
    } else if (gameStatus == 2) {
        printf("It's a draw!\n");
    }

    return 0;
}

void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

int makeMove(int row, int col) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
        board[row][col] = currentPlayer;
        return 1;
    }
    return 0;
}

int checkWin() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) {
            return 1;
        }
    }

    // Check diagonals
    if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
        return 1;
    }

    return 0;
}

int checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}
