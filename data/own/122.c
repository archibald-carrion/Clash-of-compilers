// Snippet 2: Linked List Insertion
#include <stdlib.h>
void linked_list_insertion() {
    struct Node {
        int data;
        struct Node* next;
    };

    struct Node* head = NULL;
    
    // Insert an element at the beginning
    void insert_at_beginning(struct Node** head_ref, int new_data) {
        struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
        new_node->data = new_data;
        new_node->next = (*head_ref);
        (*head_ref) = new_node;
    }

    // Insert some elements
    for (int i = 0; i < 100; i++) {
        insert_at_beginning(&head, i);
    }

    // Free memory (simple iteration)
    struct Node* current = head;
    while (current != NULL) {
        struct Node* next = current->next;
        free(current);
        current = next;
    }
}