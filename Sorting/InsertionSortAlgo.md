# Insertion Sort Algorithm

## Overview

Insertion Sort is a simple and efficient sorting algorithm that builds the final sorted array one element at a time. It is much less efficient on large lists than more advanced algorithms such as quicksort, heapsort, or merge sort. However, it performs well for small datasets or nearly sorted datasets.

## How it Works

1. **Build:**
   - The algorithm iterates through the array, considering one element at a time.
   - It builds the sorted portion of the array by repeatedly taking elements from the unsorted portion and inserting them into their correct position in the sorted portion.

2. **Insert:**
   - For each element in the unsorted portion, the algorithm compares it with the elements in the sorted portion.
   - The element is inserted into its correct position by shifting larger elements to the right.

## Implementation

The algorithm is implemented using a simple iterative approach. The main steps are:
1. Iterate through each element in the array.
2. Compare the current element with the elements in the sorted portion.
3. Insert the current element into its correct position in the sorted portion.

## Pseudocode
  ```plaintext
      insertionSort(arr, n):
        for i from 1 to n-1:
            key = arr[i]
            j = i - 1
            while j >= 0 and arr[j] > key:
                arr[j + 1] = arr[j]
                j = j - 1
            arr[j + 1] = key
  ```

## Time Complexity

- Best Case: O(n) - when the array is already sorted.
- Average Case: O(n^2)
- Worst Case: O(n^2) - when the array is sorted in reverse order.

## Space Complexity

Insertion Sort is an in-place sorting algorithm, and its space complexity is O(1).

## Advantages

- Simple and easy to implement.
- Adaptive: Efficient for small datasets or nearly sorted datasets.
- In-place sorting algorithm.

## Disadvantages

- Inefficient for large datasets compared to more advanced algorithms.
- Quadratic time complexity in the average and worst cases.

## Applications

- **Small Datasets:**
Insertion Sort is suitable for sorting small datasets or datasets where most of the elements are already in sorted order.

- **Online Algorithms:**
Insertion Sort can be useful in online algorithms where elements are coming one by one and we need to maintain a sorted list.

- **Efficient for Partially Sorted Arrays:**
When the array is partially sorted or nearly sorted, Insertion Sort can outperform other algorithms.

- **Simple Sorting Requirements:**
Insertion Sort is a good choice when simplicity and ease of implementation are more critical than performance.

Insertion Sort is a basic yet practical sorting algorithm that finds its application in scenarios where simplicity and efficiency for small datasets are prioritized.
