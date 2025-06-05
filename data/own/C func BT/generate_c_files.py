def generate_c_files(snippets, start, end):
    for i in range(start, end + 1):
        filename = f"{i}.c"
        with open(filename, "w") as file:
            file.write(snippets[i - start])
        print(f"Archivo {filename} generado.")

# Los 10 snippets de código que proporcioné previamente
snippets = [
    '''// Snippet 1: Longest Common Subsequence (LCS)
void longest_common_subsequence() {
    int n = 1000, m = 1000;  // Lengths of strings
    char *X = (char*) malloc(n * sizeof(char));
    char *Y = (char*) malloc(m * sizeof(char));

    // LCS DP array
    int **L = (int**) malloc((n + 1) * sizeof(int*));
    for (int i = 0; i <= n; i++) {
        L[i] = (int*) malloc((m + 1) * sizeof(int));
    }

    // Fill the LCS DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (X[i - 1] == Y[j - 1]) {
                L[i][j] = L[i - 1][j - 1] + 1;
            } else {
                L[i][j] = (L[i - 1][j] > L[i][j - 1]) ? L[i - 1][j] : L[i][j - 1];
            }
        }
    }

    // Free memory
    for (int i = 0; i <= n; i++) {
        free(L[i]);
    }
    free(L);
    free(X);
    free(Y);
}''',

    '''// Snippet 2: Floyd-Warshall Algorithm for All-Pairs Shortest Path
void floyd_warshall() {
    int n = 1000;  // Number of nodes
    int **dist = (int**) malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        dist[i] = (int*) malloc(n * sizeof(int));
    }

    // Initialize distance matrix (simulating a graph)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                dist[i][j] = 0;
            } else {
                dist[i][j] = 1000000;  // Large number to simulate no path
            }
        }
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Free memory
    for (int i = 0; i < n; i++) {
        free(dist[i]);
    }
    free(dist);
}''',

    '''// Snippet 3: N-Queens Problem (Backtracking)
void n_queens() {
    int n = 14;  // Size of the chessboard
    int *board = (int*) malloc(n * sizeof(int));  // board[i] is the column position of queen in row i

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

    solve(0);

    free(board);
}''',

    '''// Snippet 4: Matrix Multiplication with Strassen's Algorithm
void strassens_matrix_multiply() {
    int n = 512;  // Matrix size
    int **A = (int**) malloc(n * sizeof(int*));
    int **B = (int**) malloc(n * sizeof(int*));
    int **C = (int**) malloc(n * sizeof(int*));

    // Allocate memory for matrices
    for (int i = 0; i < n; i++) {
        A[i] = (int*) malloc(n * sizeof(int));
        B[i] = (int*) malloc(n * sizeof(int));
        C[i] = (int*) malloc(n * sizeof(int));
    }

    // Matrix multiplication with Strassen's Algorithm (simplified for readability)
    void strassen(int **A, int **B, int **C, int n) {
        if (n <= 1) {
            C[0][0] = A[0][0] * B[0][0];
            return;
        }
        // Splitting matrices into sub-matrices (omitted for brevity)
        // Recursive calls to multiply sub-matrices and add them
    }

    strassen(A, B, C, n);

    // Free memory
    for (int i = 0; i < n; i++) {
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }
    free(A);
    free(B);
    free(C);
}''',

    '''// Snippet 5: Sieve of Eratosthenes (Finding Primes up to a Large Number)
void sieve_of_eratosthenes() {
    int n = 1000000;  // Upper limit
    int *sieve = (int*) malloc((n + 1) * sizeof(int));
    for (int i = 0; i <= n; i++) sieve[i] = 1;  // Assume all numbers are prime

    sieve[0] = sieve[1] = 0;  // 0 and 1 are not prime
    for (int i = 2; i * i <= n; i++) {
        if (sieve[i] == 1) {
            for (int j = i * i; j <= n; j += i) {
                sieve[j] = 0;
            }
        }
    }

    // Free memory
    free(sieve);
}''',

    '''// Snippet 6: Dijkstra's Algorithm for Single-Source Shortest Path
void dijkstra() {
    int n = 1000;  // Number of nodes
    int **graph = (int**) malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        graph[i] = (int*) malloc(n * sizeof(int));
    }
    int *dist = (int*) malloc(n * sizeof(int));
    int *visited = (int*) malloc(n * sizeof(int));

    // Initialize graph, dist, and visited
    for (int i = 0; i < n; i++) {
        dist[i] = 1000000;  // Set all distances to infinity
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            graph[i][j] = (i == j) ? 0 : 1000000;
        }
    }

    // Dijkstra's algorithm
    dist[0] = 0;  // Start from node 0
    for (int i = 0; i < n - 1; i++) {
        int u = -1;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 1000000 && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Free memory
    for (int i = 0; i < n; i++) {
        free(graph[i]);
    }
    free(graph);
    free(dist);
    free(visited);
}''',

    '''// Snippet 7: Largest Contiguous Subarray Sum (Kadane's Algorithm)
void kadane_algorithm() {
    int n = 1000000;  // Array size
    int *arr = (int*) malloc(n * sizeof(int));

    int max_sum = arr[0], current_sum = arr[0];
    for (int i = 1; i < n; i++) {
        current_sum = (arr[i] > current_sum + arr[i]) ? arr[i] : current_sum + arr[i];
        max_sum = (max_sum > current_sum) ? max_sum : current_sum;
    }

    free(arr);
}''',

    '''// Snippet 8: K-Nearest Neighbors (Simple Implementation for Classification)
void knn_classification() {
    int n = 10000, k = 3;  // Number of data points and neighbors
    double *data = (double*) malloc(n * sizeof(double));  // Example data
    int *labels = (int*) malloc(n * sizeof(int));  // Labels (0 or 1)

    // Find k-nearest neighbors (distance calculation omitted for brevity)
    int classify(double *data_point) {
        // Find k nearest neighbors and classify based on majority vote
        return 1;  // Example return (just a placeholder)
    }

    for (int i = 0; i < n; i++) {
        classify(&data[i]);
    }

    free(data);
    free(labels);
}''',

    '''// Snippet 9: Matrix Inversion (Using Gaussian Elimination)
void matrix_inversion() {
    int n = 1000;  // Matrix size
    double **A = (double**) malloc(n * sizeof(double*));
    double **I = (double**) malloc(n * sizeof(double*));

    for (int i = 0; i < n; i++) {
        A[i] = (double*) malloc(n * sizeof(double));
        I[i] = (double*) malloc(n * sizeof(double));
    }

    // Initialize matrix A and identity matrix I
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            I[i][j] = (i == j) ? 1.0 : 0.0;  // Identity matrix
        }
    }

    // Perform Gaussian elimination (simplified)
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double factor = A[j][i] / A[i][i];
            for (int k = 0; k < n; k++) {
                A[j][k] -= factor * A[i][k];
                I[j][k] -= factor * I[i][k];
            }
        }
    }

    // Free memory
    for (int i = 0; i < n; i++) {
        free(A[i]);
        free(I[i]);
    }
    free(A);
    free(I);
}''',

    '''// Snippet 10: Generate All Subsets of a Set
void generate_subsets() {
    int n = 20;  // Number of elements in the set
    int *set = (int*) malloc(n * sizeof(int));

    // Generate all subsets (using bitmasking)
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                // Add set[i] to the current subset
            }
        }
    }

    free(set);
}'''
]

# Ejemplo de uso
generate_c_files(snippets, 141, 150)
