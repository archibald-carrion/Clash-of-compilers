#include <stdlib.h> // For malloc, free

// Forward declaration for solve_nqueens_recursive
int solve_nqueens_recursive(int row, int n, int *board);

// Check if the current placement is valid
int is_safe_nqueens(int row, int col, int n, int *board) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col ||                 // Check same column
            board[i] - i == col - row ||      // Check main diagonal
            board[i] + i == col + row) {      // Check anti-diagonal
            return 0;
        }
    }
    return 1;
}

// Solve the N-Queens problem using backtracking (recursive helper)
int solve_nqueens_recursive(int row, int n, int *board) {
    if (row == n) return 1; // All queens placed successfully
    for (int col = 0; col < n; col++) {
        if (is_safe_nqueens(row, col, n, board)) {
            board[row] = col;
            if (solve_nqueens_recursive(row + 1, n, board)) return 1;
            // Backtrack: board[row] = -1; // Not strictly necessary if overwritten
        }
    }
    return 0; // No solution found for this path
}

// Snippet 186: Solving N-Queens Problem using Backtracking
void n_queens() {
    int n = 14;  // Size of the chessboard
    int *board = (int*) malloc(n * sizeof(int));
    // Initialize board if needed, e.g. to -1, though current logic overwrites

    solve_nqueens_recursive(0, n, board);

    free(board);
}

int main() {
    // This file was initially empty.
    return 0;
}
