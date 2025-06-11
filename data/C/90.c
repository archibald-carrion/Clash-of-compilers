#include <stdio.h>
#include <stdlib.h>

struct Node {
  int key;
  struct Node* left;
  struct Node* right;
  int height;
};

int max(int a, int b) { return (a > b) ? a : b; }

int height(struct Node* node) {
  if (node == NULL)
    return 0;
  return node->height;
}

// Crea un nuevo nodo
struct Node* newNode(int key) {
  struct Node* node = (struct Node*)malloc(sizeof(struct Node));
  node->key = key;
  node->left = NULL;
  node->right = NULL;
  node->height = 1;
  return node;
}

int main() {
  struct Node* root = newNode(10);
  root->left = newNode(5);
  root->right = newNode(15);

  printf("Altura del nodo root: %d\n", height(root));
  printf("Altura del nodo root->left: %d\n", height(root->left));
  printf("Altura del nodo root->right: %d\n", height(root->right));

  // Liberar memoria
  free(root->left);
  free(root->right);
  free(root);

  return 0;
}
