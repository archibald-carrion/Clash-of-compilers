#include <stdio.h>
#include <stdlib.h>

// Structure for stack node
typedef struct StackNode {
    int vertex;
    struct StackNode* next;
} StackNode;

// Structure for stack
typedef struct Stack {
    StackNode* top;
} Stack;

// Function to create a new stack node
StackNode* createNode(int v) {
    StackNode* node = (StackNode*) malloc(sizeof(StackNode));
    if (node == NULL) {
        perror("Failed to allocate memory for stack node");
        exit(EXIT_FAILURE);
    }
    node->vertex = v;
    node->next = NULL;
    return node;
}

// Function to create an empty stack
Stack* createStack() {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    if (stack == NULL) {
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

// Function to push a vertex to stack
void push(Stack* stack, int v) {
    StackNode* node = createNode(v);
    node->next = stack->top;
    stack->top = node;
}

// Function to pop a vertex from stack
int pop(Stack* stack) {
    if (isEmpty(stack)) return -1;
    StackNode* temp = stack->top;
    stack->top = stack->top->next;
    int popped = temp->vertex;
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

// Iterative DFS function
void dfs_iterative(int start, int n, int **graph, int *visited) {
    Stack* stack = createStack();
    
    // Push the start vertex
    push(stack, start);
    
    while (!isEmpty(stack)) {
        int v = pop(stack);
        
        // If vertex is not visited, mark it
        if (!visited[v]) {
            visited[v] = 1;
            
            // Push all unvisited adjacent vertices
            for (int i = n-1; i >= 0; i--) {
                if (graph[v][i] && !visited[i]) {
                    push(stack, i);
                }
            }
        }
    }
    
    freeStack(stack);
}

void dfs_graph() {
    int n = 100; // Reduced from 1000 to avoid excessive memory usage
    int **graph = (int**) malloc(n * sizeof(int*));
    if (!graph) {
        perror("Failed to allocate memory for graph");
        return;
    }
    
    for (int i = 0; i < n; i++) {
        graph[i] = (int*) malloc(n * sizeof(int));
        if (!graph[i]) {
            perror("Failed to allocate memory for graph row");
            // Free previously allocated rows
            for (int j = 0; j < i; j++) {
                free(graph[j]);
            }
            free(graph);
            return;
        }
    }

    int *visited = (int*) malloc(n * sizeof(int));
    if (!visited) {
        perror("Failed to allocate memory for visited array");
        for (int i = 0; i < n; i++) {
            free(graph[i]);
        }
        free(graph);
        return;
    }

    // Initialize graph and visited array
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;  // Assume no edges initially
        }
    }
    
    // Add a few edges for testing
    if (n > 1) {
        graph[0][1] = 1;
    }
    if (n > 2) {
        graph[1][2] = 1;
    }
    
    // Start DFS from vertex 0
    dfs_iterative(0, n, graph, visited);

    free(visited);
    for (int i = 0; i < n; i++) {
        free(graph[i]);
    }
    free(graph);
}

int main() {
    dfs_graph();
    return 0;
}