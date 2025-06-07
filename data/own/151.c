// Snippet 1: Solving the Traveling Salesman Problem (TSP) using Brute Force
// Forward declaration of swap (assumed to exist)
void swap(int *a, int *b);

// Forward declaration of permute
void permute(int *arr, int l, int r, int n, int **dist, int *min_path_length);

// Snippet 1: Solving the Traveling Salesman Problem (TSP) using Brute Force
void traveling_salesman() {
    int n = 20;  // Number of cities
    int **dist = (int**) malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        dist[i] = (int*) malloc(n * sizeof(int));
    }

    // Initialize distance matrix (simulating random distances)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = (i == j) ? 0 : rand() % 100 + 1;  // Random distance
        }
    }

    // Brute force to calculate all permutations and find the minimum route
    int min_path_length = 1000000;
    int *path = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) path[i] = i;

    permute(path, 0, n - 1, n, dist, &min_path_length);

    free(path);
    for (int i = 0; i < n; i++) {
        free(dist[i]);
    }
    free(dist);
}

// Helper function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Permutation function moved outside
void permute(int *arr, int l, int r, int n, int **dist, int *min_path_length) {
    if (l == r) {
        int path_length = 0;
        for (int i = 0; i < n - 1; i++) {
            path_length += dist[arr[i]][arr[i + 1]];
        }
        path_length += dist[arr[n - 1]][arr[0]];  // Return to starting point
        if (path_length < *min_path_length) *min_path_length = path_length;
    } else {
        for (int i = l; i <= r; i++) {
            swap(&arr[l], &arr[i]);
            permute(arr, l + 1, r, n, dist, min_path_length);
            swap(&arr[l], &arr[i]);  // Backtrack
        }
    }
}