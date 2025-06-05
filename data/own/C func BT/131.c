// Snippet 1: Depth-First Search (DFS) on a Grid
void dfs_grid() {
    int n = 1000, m = 1000;  // Grid size
    int **grid = (int**) malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        grid[i] = (int*) malloc(m * sizeof(int));
    }

    int *visited = (int*) malloc(n * m * sizeof(int));

    // Directions: up, down, left, right
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    void dfs(int x, int y) {
        visited[x * m + y] = 1;
        for (int i = 0; i < 4; i++) {
            int nx = x + directions[i][0];
            int ny = y + directions[i][1];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && !visited[nx * m + ny]) {
                dfs(nx, ny);
            }
        }
    }

    // Initialize grid and visited array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            grid[i][j] = 1;  // All cells are open for DFS
            visited[i * m + j] = 0;
        }
    }

    // Start DFS from top-left corner
    dfs(0, 0);

    // Free memory
    free(visited);
    for (int i = 0; i < n; i++) {
        free(grid[i]);
    }
    free(grid);
}