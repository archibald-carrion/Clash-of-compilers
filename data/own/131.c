#include <stdio.h>
#include <stdlib.h>

// Position structure for the stack
typedef struct Position {
    int x, y;
} Position;

// Structure for stack node
typedef struct StackNode {
    Position pos;
    struct StackNode* next;
} StackNode;

// Structure for stack
typedef struct Stack {
    StackNode* top;
} Stack;

// Function to create a new stack node
StackNode* createNode(int x, int y) {
    StackNode* node = (StackNode*) malloc(sizeof(StackNode));
    if (!node) {
        perror("Failed to allocate memory for stack node");
        exit(EXIT_FAILURE);
    }
    node->pos.x = x;
    node->pos.y = y;
    node->next = NULL;
    return node;
}

// Function to create an empty stack
Stack* createStack() {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    if (!stack) {
        perror("Failed to allocate memory for stack");
        exit(EXIT_FAILURE);
    }
    stack->top = NULL;
    return stack;
}

// Function to check if stack is empty
int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// Function to push a position to stack
void push(Stack* stack, int x, int y) {
    StackNode* node = createNode(x, y);
    node->next = stack->top;
    stack->top = node;
}

// Function to pop a position from stack
Position pop(Stack* stack) {
    Position empty = {-1, -1};
    if (isEmpty(stack)) return empty;
    StackNode* temp = stack->top;
    stack->top = stack->top->next;
    Position popped = temp->pos;
    free(temp);
    return popped;
}

// Free stack memory
void freeStack(Stack* stack) {
    StackNode* current = stack->top;
    StackNode* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(stack);
}

// Iterative DFS implementation
void dfs_iterative(int start_x, int start_y, int *visited, int n, int m, int directions[4][2]) {
    Stack* stack = createStack();
    
    // Push starting position
    push(stack, start_x, start_y);
    
    while (!isEmpty(stack)) {
        Position current = pop(stack);
        int x = current.x;
        int y = current.y;
        
        // Skip invalid positions
        if (x < 0 || y < 0 || x >= n || y >= m) continue;
        
        // Skip already visited positions
        if (visited[x * m + y]) continue;
        
        // Mark as visited
        visited[x * m + y] = 1;
        
        // Push all four adjacent cells
        for (int i = 0; i < 4; i++) {
            int nx = x + directions[i][0];
            int ny = y + directions[i][1];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && !visited[nx * m + ny]) {
                push(stack, nx, ny);
            }
        }
    }
    
    freeStack(stack);
}

// Snippet 1: Depth-First Search (DFS) on a Grid
void dfs_grid() {
    int n = 100, m = 100;  // Reduced grid size from 1000x1000
    
    // Allocate grid
    int **grid = (int**) malloc(n * sizeof(int*));
    if (!grid) {
        perror("Failed to allocate memory for grid rows");
        return;
    }
    
    for (int i = 0; i < n; i++) {
        grid[i] = (int*) malloc(m * sizeof(int));
        if (!grid[i]) {
            perror("Failed to allocate memory for grid columns");
            // Free previously allocated rows
            for (int j = 0; j < i; j++) {
                free(grid[j]);
            }
            free(grid);
            return;
        }
    }

    int *visited = (int*) malloc(n * m * sizeof(int));
    if (!visited) {
        perror("Failed to allocate memory for visited array");
        for (int i = 0; i < n; i++) {
            free(grid[i]);
        }
        free(grid);
        return;
    }

    // Directions: up, down, left, right
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    // Initialize grid and visited array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            grid[i][j] = 1;  // All cells are open for DFS
            visited[i * m + j] = 0;
        }
    }

    // Start iterative DFS from top-left corner
    dfs_iterative(0, 0, visited, n, m, directions);

    // Free memory
    free(visited);
    for (int i = 0; i < n; i++) {
        free(grid[i]);
    }
    free(grid);
}

int main() {
    dfs_grid();
    return 0;
}