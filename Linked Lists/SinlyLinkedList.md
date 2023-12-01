# Singly Linked List Implementation

This repository contains a basic implementation of a Singly Linked List in the C programming language. A Singly Linked List is a data structure where each element (node) contains data and a pointer/reference to the next node in the sequence.

## Functionality

The Singly Linked List implementation includes the following operations:

- **Insertion:**
  - At the beginning of the list
  - At the end of the list
  - At a specific position

- **Deletion:**
  - From the beginning of the list
  - From the end of the list
  - From a specific position

- **Traversal:**
  - Printing the elements of the linked list

- **Search:**
  - Finding an element in the linked list

- **Loop Detection:**
  - Detecting loops in the linked list
 
## Pseudocode

``` plaintext
Node Structure:
  - data
  - next

Function InsertAtBeginning(data):
  newNode = new Node(data)
  newNode.next = head
  head = newNode

Function InsertAtEnd(data):
  newNode = new Node(data)
  if head is null:
    head = newNode
  else:
    current = head
    while current.next is not null:
      current = current.next
    current.next = newNode

Function DeleteNode(value):
  if head is null:
    return
  if head.data is equal to value:
    head = head.next
    return
  current = head
  while current.next is not null and current.next.data is not equal to value:
    current = current.next
  if current.next is not null:
    current.next = current.next.next

Function Traverse():
  current = head
  while current is not null:
    print current.data
    current = current.next
```

## Algorithm

### Insertion at the Beginning:
1. Create a new node with the given `data`.
2. Set the `next` pointer of the new node to the `current head`.
3. Update the `head` to point to the new node.


### Insertion at the End:
1. Create a new node with the given `data`.
2. If the `head` is null, set the `head` to the new node.
3. Otherwise, traverse the list to the last node.
4. Set the `next` pointer of the last node to the new node.


### Deletion:
1. If the `head` is null, return.
2. If the `head`'s data is equal to the specified value, update the `head` to point to the next node.
3. Otherwise, traverse the list to find the node with data equal to the specified value.
4. Update the `next` pointer of the previous node to skip the node to be deleted.


### Traversal:
1. Initialize a current pointer to the `head`.
2. While the current pointer is not null:
   - Print the `data` of the current node.
   - Move the current pointer to the next node.

## Usage

- Dynamic Memory Allocation
- Undo Mechanisms in Applications
- Symbol Tables in Compilers
- Task Scheduling
- Music and Video Playlists
- Navigation Systems
- Sensor Networks

## Advantages of Singly Linked Lists

- Dynamic Size
- Efficient Insertion and Deletion
- No Fixed Size
- Ease of Implementation
- No Wasted Memory

## Disadvantages of Singly Linked Lists

- No Random Access
- Increased Memory Overhead
- Traversal Overhead
- Lack of Backtracking
- No Bidirectional Traversal
- Difficulty in Detecting Loops
- No Immediate Predecessor Access
