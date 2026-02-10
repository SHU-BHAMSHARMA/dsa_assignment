#include <stdio.h>
#include <stdlib.h>

// Structure for a Singly Linked List node
struct Node {
    int value;
    struct Node *next;
};

// Function to append a node at the end of the list
void append(struct Node **head_ref, int new_data) {
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node *last = *head_ref;

    new_node->value = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

// Recursive function for reverse traversal
void traverseBackward(struct Node *n) {
    if (n == NULL) {
        return;
    }
    
    // Recursive call to reach the end first
    traverseBackward(n->next);
    
    // Print data during backtracking
    printf("%d ", n->value);
}

int main() {
    struct Node *head = NULL;

    // Building the list
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    append(&head, 40);

    printf("Original List: 10 20 30 40\n");
    printf("Reverse Traversal: ");
    traverseBackward(head);
    printf("\n");

    return 0;
}