# Heap Sort Implementation in C++

## Overview

This C++ program demonstrates the implementation of Heap Sort using a max heap data structure. Heap Sort is a comparison-based sorting algorithm that uses a binary heap data structure to build a heap and efficiently sort the elements. The program also includes a class `heap` with methods for inserting elements into the heap, deleting the root (max element), and printing the heap.

## Heap Sort

### Algorithm

Heap Sort follows the following algorithm:

1. Build a max heap from the input array.
2. Swap the root (maximum element) with the last element of the heap.
3. Reduce the size of the heap and heapify the root.
4. Repeat steps 2-3 until the heap is empty.

### Pseudocode

```plaintext
HeapSort(arr):
    n = size of arr

    // Build max heap
    for i from n/2 down to 1:
        Heapify(arr, n, i)

    // Swap the root with the last element and heapify
    for i from n down to 2:
        Swap(arr[1], arr[i])
        Heapify(arr, i-1, 1)
```

### Implementation Details

The program includes a `heapify` function for heapifying an array and a `heapSort` function that performs the entire sorting process.

## Class: Heap

The `heap` class includes the following methods:

- `insertIntoHeap(int val)`: Inserts a value into the heap and adjusts the heap.
- `deleteFromHeap()`: Deletes the root (max element) from the heap and adjusts the heap.
- `print()`: Prints the elements of the heap.

## How to Run

Compile and run the provided C++ code. The program includes examples of heap creation, insertion, deletion, and heap sort.

```bash
g++ Heap.cpp -o HeapSort
./HeapSort
```

## Applications of Heap Sort

Heap Sort has various applications, including:

- **Sorting**: Heap Sort is used for sorting large volumes of data efficiently.

- **Priority Queues**: It is used to implement priority queues where the element with the highest priority is processed first.

- **Operating System**: Heap Sort is used in memory allocation processes by operating systems.

- **Databases**: It is utilized in database systems for sorting records efficiently.

- **Networking**: Heap Sort is employed in routing algorithms and network protocols.

- **Parallel Computing**: It can be adapted for parallel computing.

## Conclusion

Heap Sort is a robust sorting algorithm with applications in various domains. This C++ program provides a practical implementation and demonstration of Heap Sort using a max heap.
