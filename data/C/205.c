#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Static globals for N-Queens board and size, specific to this "file"
static int s195_n_val;
static int *s195_board_ptr;
static int s195_solution_count;


// is_safe function for N-Queens
static int s195_is_safe(int row, int col) {
    for (int i = 0; i < row; i++) {
        // Check column conflict
        if (s195_board_ptr[i] == col) {
            return 0;
        }
        // Check diagonal conflicts
        if (abs(s195_board_ptr[i] - col) == abs(i - row)) {
            return 0;
        }
    }
    return 1;
}

// Recursive solver for N-Queens, moved to file scope
static void s195_solve_recursive(int row) {
    if (row == s195_n_val) {
        // Solution found
        s195_solution_count++;
        // Removed print statements
        return;
    }

    for (int col = 0; col < s195_n_val; col++) {
        if (s195_is_safe(row, col)) {
            s195_board_ptr[row] = col;
            s195_solve_recursive(row + 1);
            // Backtracking is implicit as s195_board_ptr[row] will be overwritten by the next iteration or call
        }
    }
}

// Snippet 195: Solving N-Queens Problem using Dynamic Programming (actually backtracking)
void n_queens_dp() {
    s195_n_val = 8;  // Size of the chessboard, reduced from 14 for reasonable execution time
    s195_board_ptr = (int*) malloc(s195_n_val * sizeof(int));
    s195_solution_count = 0;

    // DP approach to find the N-Queens solutions
    // (Actual recursive call is to s195_solve_recursive)
    s195_solve_recursive(0);

    // Removed printf statement

    free(s195_board_ptr);
}

int main() {
    n_queens_dp();
    return 0;
}
