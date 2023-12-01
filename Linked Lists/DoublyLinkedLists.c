#include <stdio.h>
#include <stdlib.h>

// Node structure for a doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to insert a new node at the beginning of the doubly linked list
void insertAtBeginning(struct Node** head, int data) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    newNode->prev = NULL;

    // Update the previous pointer of the current head if it exists
    if (*head != NULL) {
        (*head)->prev = newNode;
    }

    // Update the head to the new node
    *head = newNode;
}

// Function to insert a new node at the end of the doubly linked list
void insertAtEnd(struct Node** head, int data) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    // If the list is empty, set the new node as the head
    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    // Traverse to the last node
    struct Node* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }

    // Update pointers for the new node
    last->next = newNode;
    newNode->prev = last;
}

// Function to delete a node with a specific value from the doubly linked list
void deleteNode(struct Node** head, int value) {
    // If the list is empty, return
    if (*head == NULL) {
        return;
    }

    // If the node to be deleted is the head
    if ((*head)->data == value) {
        struct Node* temp = *head;
        *head = (*head)->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
        return;
    }

    // Traverse to find the node with the specified value
    struct Node* current = *head;
    while (current != NULL && current->data != value) {
        current = current->next;
    }

    // If the node is not found, return
    if (current == NULL) {
        return;
    }

    // Update pointers to skip the node to be deleted
    if (current->prev != NULL) {
        current->prev->next = current->next;
    }
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    // Free the memory of the deleted node
    free(current);
}

// Function to print the doubly linked list in forward order
void printForward(struct Node* head) {
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to print the doubly linked list in reverse order
void printReverse(struct Node* head) {
    // Traverse to the last node
    while (head != NULL && head->next != NULL) {
        head = head->next;
    }

    // Print in reverse order
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->prev;
    }
    printf("NULL\n");
}

// Main function for testing the doubly linked list implementation
int main() {
    struct Node* head = NULL;
    int choice, data;

    while (1) {
        printf("\n1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Delete a node\n");
        printf("4. Print in forward order\n");
        printf("5. Print in reverse order\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 4:
                printf("Doubly Linked List (Forward): ");
                printForward(head);
                break;
            case 5:
                printf("Doubly Linked List (Reverse): ");
                printReverse(head);
                break;
            case 6:
                // Free memory and exit
                return 0;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
