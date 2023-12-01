# Stack Implementation in C

## Overview

This directory contains a basic implementation of a stack in the C programming language. The stack is a fundamental data structure that follows the Last In, First Out (LIFO) principle. It includes functions for push, pop, and peek operations.

## Files

- `stack.c`: Contains the implementation of the stack operations.
- `stack.h`: Header file for the stack implementation, defining the structure and function prototypes.
- `main.c`: Example usage of the stack implementation.

## Algorithm

### Stack Operations

#### 1. Push Operation

```plaintext
push(stack, element):
    if stack is full:
        print "Stack Overflow"
    else:
        stack.top += 1
        stack.arr[stack.top] = element
```

#### 2. Pop Operation

```plaintext
pop(stack):
    if stack is empty:
        print "Stack Underflow"
        return -1 // Error indicator
    else:
        poppedElement = stack.arr[stack.top]
        stack.top -= 1
        return poppedElement
```

#### 3. Peek Operation

```plaintext
peek(stack):
    if stack is empty:
        print "Stack is empty"
    else:
        print "Top element: ", stack.arr[stack.top]
```

## Advantages of Stacks

- Simplicity: Stacks are simple to understand and implement.
- Efficiency: Push and pop operations have a constant time complexity.
- Memory Management: Memory is managed efficiently with LIFO order.

## Disadvantages of Stacks

- Limited Access: Random access to elements is not allowed.
- Size Limitation: The size of the stack needs to be predefined.
- Complexity: Some operations may become complex for large stacks.

## Types of Stacks

- Fixed-size Stack: The size of the stack is fixed at the time of creation.
- Dynamic Stack: The size of the stack can grow or shrink dynamically.
- Call Stack: Used in programming to manage function calls and returns.
- Undo Stack: Keeps track of operations to support undo functionality.

## Usage

- Function Call Management
- Expression Evaluation
- Undo Mechanisms
- Backtracking Algorithms
- Memory Management
- Browser History
- Task Scheduling:
