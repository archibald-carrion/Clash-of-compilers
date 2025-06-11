#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define V 5

struct Node {
    int x, y;
    int gCost, hCost;
    struct Node* parent;
};

struct Node* newNode(int x, int y, int gCost, int hCost) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->x = x;
    node->y = y;
    node->gCost = gCost;
    node->hCost = hCost;
    node->parent = NULL;
    return node;
}

int heuristic(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

void astar(int grid[V][V], int startX, int startY, int goalX, int goalY) {
    int closedList[V][V] = {0};
    struct Node* openList[V * V];
    int openListSize = 0;

    struct Node* startNode = newNode(startX, startY, 0, heuristic(startX, startY, goalX, goalY));
    openList[openListSize++] = startNode;

    while (openListSize > 0) {
        int minIndex = 0;
        for (int i = 1; i < openListSize; i++) {
            if (openList[i]->gCost + openList[i]->hCost < openList[minIndex]->gCost + openList[minIndex]->hCost) {
                minIndex = i;
            }
        }

        struct Node* currentNode = openList[minIndex];
        openList[minIndex] = openList[--openListSize];

        if (currentNode->x == goalX && currentNode->y == goalY) {
            printf("Goal reached! Path: ");
            while (currentNode != NULL) {
                printf("(%d, %d) ", currentNode->x, currentNode->y);
                currentNode = currentNode->parent;
            }
            printf("\n");
            return;
        }

        closedList[currentNode->x][currentNode->y] = 1;

        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (dx == 0 && dy == 0) continue;

                int newX = currentNode->x + dx;
                int newY = currentNode->y + dy;

                if (newX >= 0 && newX < V && newY >= 0 && newY < V && !closedList[newX][newY] && grid[newX][newY] == 0) {
                    struct Node* neighbor = newNode(newX, newY, currentNode->gCost + 1, heuristic(newX, newY, goalX, goalY));
                    neighbor->parent = currentNode;
                    openList[openListSize++] = neighbor;
                }
            }
        }
    }

    printf("No path found\n");
}

int main() {
    int grid[V][V] = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    astar(grid, 0, 0, 4, 4);
    return 0;
}
