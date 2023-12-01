#include<stdio.h>
#include<stdlib.h>

// Structure to represent a stack
struct stack {
    int top;
    int *arr;
    int size;
};

// Function to push an element onto the stack
void push(struct stack *s, int a) {
    // Check if the stack is full
    if (s->top == s->size - 1) {
        printf("Stack is Full\n");
    } else {
        // Increment top and add the element to the stack
        s->top++;
        s->arr[s->top] = a;
    }
}

// Function to pop an element from the stack
int pop(struct stack *s) {
    // Check if the stack is empty
    if (s->top == -1) {
        printf("Stack is empty\n");
        return -1; // Returning -1 to indicate an error (assuming -1 is not a valid element)
    } else {
        // Decrement top and return the popped element
        s->top--;
        return s->arr[s->top + 1];
    }
}

// Function to peek at the top element of the stack without removing it
void peek(struct stack *s) {
    // Check if the stack is empty
    if (s->top == -1) {
        printf("Stack is empty\n");
    } else {
        // Print the top element of the stack
        printf("%d ", s->arr[s->top]);
    }
}

int main() {
    // Allocate memory for the stack
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));

    // Initialize stack properties
    s->top = -1;
    s->size = 3;

    // Allocate memory for the stack array
    s->arr = (int *)malloc(sizeof(int) * (s->size));

    // Push elements onto the stack
    push(s, 1);
    push(s, 2);
    push(s, 3);

    // Peek at the top element of the stack
    peek(s);

    // Free allocated memory
    free(s->arr);
    free(s);

    return 0;
}
