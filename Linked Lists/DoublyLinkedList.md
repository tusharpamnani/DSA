# Doubly Linked List Implementation

This directory contains a basic implementation of a Doubly Linked List in the C programming language. A Doubly Linked List is a data structure where each element (node) contains data and pointers/references to both the next and previous nodes in the sequence.

## Functionality

The Doubly Linked List implementation includes the following operations:

- **Insertion:**
  - At the beginning of the list
  - At the end of the list
  - At a specific position

- **Deletion:**
  - From the beginning of the list
  - From the end of the list
  - From a specific position

- **Traversal:**
  - Printing the elements of the linked list in both forward and reverse order

- **Search:**
  - Finding an element in the linked list

- **Loop Detection:**
  - Detecting loops in the linked list

## Pseudocode

```plaintext
Node Structure:
  - data
  - next
  - prev

Function InsertAtBeginning(data):
  newNode = new Node(data)
  newNode.next = head
  newNode.prev = NULL
  if head is not null:
    head.prev = newNode
  head = newNode

Function InsertAtEnd(data):
  newNode = new Node(data)
  newNode.next = NULL
  if head is null:
    head = newNode
  else:
    current = head
    while current.next is not null:
      current = current.next
    current.next = newNode
    newNode.prev = current

Function DeleteNode(value):
  if head is null:
    return
  if head.data is equal to value:
    head = head.next
    head.prev = NULL
    return
  current = head
  while current.next is not null and current.next.data is not equal to value:
    current = current.next
  if current.next is not null:
    current.next = current.next.next
    if current.next is not null:
      current.next.prev = current

Function Traverse():
  current = head
  while current is not null:
    print current.data
    current = current.next

Function TraverseReverse():
  current = head
  while current.next is not null:
    current = current.next
  while current is not null:
    print current.data
    current = current.prev
```

## Algorithm

### Insertion at the Beginning

- Create a new node with the given data.
- Set the next pointer of the new node to the current head.
- Set the prev pointer of the new node to NULL.
- If the head is not null, update the prev pointer of the current head to the new node.
- Update the head to point to the new node.

### Insertion at the End

- Create a new node with the given data.
- Set the next pointer of the new node to NULL.
- If the head is null, set the head to the new node.
- Otherwise, traverse the list to the last node.
- Set the next pointer of the last node to the new node.
- Set the prev pointer of the new node to the last node.

### Deletion

- If the head is null, return.
- If the head's data is equal to the specified value:
  - Update the head to point to the next node.
  - If the new head is not null, update its prev pointer to NULL.
  - Return.
- Otherwise, traverse the list to find the node with data equal to the specified value.
- Update pointers to skip the node to be deleted:
  - Update the next pointer of the previous node to the next node.
  - If the next node is not null, update its prev pointer to the previous node.


### Traversal

- Initialize a current pointer to the head.
- While the current pointer is not null:
  - Print the data of the current node.
  - Move the current pointer to the next node.


### Reverse Traversal
- Initialize a current pointer to the head.
- While the next pointer of the current node is not null:
  - Move the current pointer to the next node.
- While the current pointer is not null:
  - Print the data of the current node.
  - Move the current pointer to the previous node.
  
 
## Advantages of Doubly Linked Lists:

1. Bidirectional Traversal
2. Easy Deletion of Nodes
3. Insertion and Deletion at Both Ends
4. Reverse Traversal


## Disadvantages of Doubly Linked Lists:

1. Increased Memory Overhead
2. Complexity and Overhead
3. Additional Pointer Operations
4. Storage Overhead
5. Difficulty in Implementing and Debugging
6. Increased Initialization Complexity
7. Difficulty in Detecting Loops

## Usage of Doubly Linked List

- Forward and Backward Navigation
- Undo Mechanisms in Applications
- Task Scheduling
- Music and Video Playlists
- Text Editors and Document Processing
- Symbol Tables in Compilers
- Navigation Systems
- Doubly Ended Queues (Deque)
- Data Structures with Undo/Redo Functionality
- Sensor Networks
