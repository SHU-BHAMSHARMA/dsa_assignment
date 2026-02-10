#include <stdio.h>
#include <stdlib.h>

// Structure for a Doubly Linked List Node
struct dNode {
    int data;
    struct dNode *next;
    struct dNode *prev;
};

// Function to insert a node after a specific target value
void insertAfterValue(struct dNode *head, int target, int newValue) {
    struct dNode *temp = head;

    // Traverse to find the target node
    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Target value %d not found in the list.\n", target);
        return;
    }

    // Create and link the new node
    struct dNode *newNode = (struct dNode*)malloc(sizeof(struct dNode));
    newNode->data = newValue;
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

// Function to delete a node with a specific value
void deleteByValue(struct dNode **head_ref, int target) {
    struct dNode *temp = *head_ref;

    // Search for the node to delete
    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value %d not found for deletion.\n", target);
        return;
    }

    // Update neighboring pointers
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        *head_ref = temp->next; // Deleting the head node
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
}

// Function to print the list from front to back
void printList(struct dNode *node) {
    printf("Current List: ");
    while (node != NULL) {
        printf("%d <-> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    // Initialize head node
    struct dNode *head = (struct dNode*)malloc(sizeof(struct dNode));
    head->data = 100;
    head->prev = NULL;
    head->next = NULL;

    // Demonstrate insertion
    insertAfterValue(head, 100, 200);
    insertAfterValue(head, 200, 300);
    printList(head);

    // Demonstrate deletion
    printf("Deleting 200...\n");
    deleteByValue(&head, 200);
    printList(head);

    return 0;
}