// Snippet 3: N-Queens Problem (Backtracking)
#include <stdlib.h>

static int n;  // Size of the chessboard
static int *board;  // board[i] is the column position of queen in row i

// Check if the current placement is valid
int is_safe(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || board[i] - i == col - row || board[i] + i == col + row) {
            return 0;
        }
    }
    return 1;
}

// Solve the N-Queens problem using backtracking
int solve(int row) {
    if (row == n) return 1;
    for (int col = 0; col < n; col++) {
        if (is_safe(row, col)) {
            board[row] = col;
            if (solve(row + 1)) return 1;
        }
    }
    return 0;
}

void n_queens() {
    n = 14;  // Size of the chessboard
    board = (int*) malloc(n * sizeof(int));  // board[i] is the column position of queen in row i

    solve(0);

    free(board);
}