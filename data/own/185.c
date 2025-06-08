// Snippet 175: Solving N-Queens Problem using Backtracking
#include <stdlib.h> // Added for malloc and free

// Check if the current placement is valid
static int is_safe_nqueens(int row, int col, int n, int *board) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || board[i] - i == col - row || board[i] + i == col + row) {
            return 0;
        }
    }
    return 1;
}

// Solve the N-Queens problem using backtracking
static int solve_nqueens_helper(int row, int n, int *board) {
    if (row == n) return 1;
    for (int col = 0; col < n; col++) {
        if (is_safe_nqueens(row, col, n, board)) {
            board[row] = col;
            if (solve_nqueens_helper(row + 1, n, board)) return 1;
        }
    }
    return 0;
}

void n_queens() {
    int n = 14;  // Size of the chessboard
    int *board = (int*) malloc(n * sizeof(int));

    solve_nqueens_helper(0, n, board);

    free(board);
}

int main() {
    n_queens();
    return 0;
}
