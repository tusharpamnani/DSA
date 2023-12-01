#include<stdio.h>
#include<stdlib.h>

// Node structure to represent a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to print the linked list
void printLinkedList(struct Node* head) {
    struct Node* ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

// Function to insert a node at the beginning of the linked list
struct Node* insertAtBeg(struct Node* head, int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = head;
    head = temp;
    return head;
}

// Function to insert a node at the end of the linked list
struct Node* insertAtEnd(struct Node* head, int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = NULL;
    struct Node* ptr = head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = temp;
    return head;
}

// Function to insert a node at a specific position in the linked list
struct Node* insertAtBet(struct Node* head, int val, int pos) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    struct Node* prev;
    struct Node* current = head;
    int count = 1;
    while (count < pos) {
        prev = current;
        current = current->next;
        count++;
    }
    prev->next = temp;
    temp->next = current;
    return head;
}

// Function to delete a node from the beginning of the linked list
struct Node* deleteAtBeg(struct Node* head) {
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Function to delete a node from the end of the linked list
struct Node* deleteAtEnd(struct Node* head) {
    struct Node* prev;
    struct Node* current = head;
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }
    prev->next = NULL;
    free(current);
    return head;
}

int main() {
    // Creating linked list nodes
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    struct Node* third = (struct Node*)malloc(sizeof(struct Node));
  
    third->next = NULL;
    head->next = second;
    second->next = third;
  
    head->data = 1;
    second->data = 2;
    third->data = 3;

    // Print the original linked list
    printLinkedList(head);

    // Insert at the beginning
    head = insertAtBeg(head, 0);
    printLinkedList(head);

    // Insert at the end
    head = insertAtEnd(head, 4);
    printLinkedList(head);

    // Insert at a specific position
    head = insertAtBet(head, -1, 2);
    printLinkedList(head);

    // Delete from the beginning
    head = deleteAtBeg(head);
    printLinkedList(head);

    // Delete from the end
    head = deleteAtEnd(head);
    printLinkedList(head);

    return 0;
}
