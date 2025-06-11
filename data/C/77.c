#include <stdio.h>
#include <stdlib.h>

#define ALPHABET_SIZE 26

struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    int isEndOfWord;
};

struct TrieNode* getNode() {
    struct TrieNode* node = (struct TrieNode*)malloc(sizeof(struct TrieNode));
    node->isEndOfWord = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        node->children[i] = NULL;
    }
    return node;
}

void insert(struct TrieNode* root, const char* key) {
    struct TrieNode* pCrawl = root;
    for (int i = 0; key[i]; i++) {
        int index = key[i] - 'a';
        if (!pCrawl->children[index]) {
            pCrawl->children[index] = getNode();
        }
        pCrawl = pCrawl->children[index];
    }
    pCrawl->isEndOfWord = 1;
}

int search(struct TrieNode* root, const char* key) {
    struct TrieNode* pCrawl = root;
    for (int i = 0; key[i]; i++) {
        int index = key[i] - 'a';
        if (!pCrawl->children[index]) {
            return 0;
        }
        pCrawl = pCrawl->children[index];
    }
    return pCrawl != NULL && pCrawl->isEndOfWord;
}

int main() {
    struct TrieNode* root = getNode();
    insert(root, "hello");
    insert(root, "world");

    printf("Search for 'hello': %d\n", search(root, "hello"));
    printf("Search for 'world': %d\n", search(root, "world"));
    printf("Search for 'hell': %d\n", search(root, "hell"));
    return 0;
}
