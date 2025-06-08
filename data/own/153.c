// Snippet 3: Binary Search Tree (BST) Insertion and Traversal
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* left;
    struct Node* right;
};

struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        struct Node* node = (struct Node*) malloc(sizeof(struct Node));
        node->value = value;
        node->left = node->right = NULL;
        return node;
    }

    if (value < root->value) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

void inorder_traversal(struct Node* root) {
    if (root == NULL) return;
    inorder_traversal(root->left);
    printf("%d ", root->value);
    inorder_traversal(root->right);
}

void bst_insertion() {
    struct Node* root = NULL;
    for (int i = 0; i < 1000; i++) {
        root = insert(root, rand() % 1000);
    }

    inorder_traversal(root);
}

int main() {
    bst_insertion();
    return 0;
}