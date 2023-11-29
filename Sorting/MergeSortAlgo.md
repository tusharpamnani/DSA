# Merge Sort Algorithm

## Overview

Merge Sort is a popular divide-and-conquer sorting algorithm. It follows the divide-and-conquer paradigm by recursively dividing the array into two halves, sorting each half, and then merging the sorted halves to produce a fully sorted array.

## How it Works

1. Divide: The array is divided into two halves until each sub-array contains only one element.
2. Conquer: Each sub-array is sorted individually.
3. Merge: The sorted sub-arrays are merged to produce a sorted array. This is the key step that combines the results of the conquer phase.

## Implementation

The algorithm is typically implemented using recursion. The main steps are:
1. Base Case: If the array has one element or is empty, it is already considered sorted, and no further action is needed.
2. Divide: Find the middle of the array.
3. Conquer: Recursively apply the merge sort to the left and right halves.
4. Merge: Merge the two sorted halves to produce a fully sorted array.

## Pseudocode
  ```plaintext
      mergeSort(arr, start, end):
        if start < end:
            mid = (start + end) / 2
            mergeSort(arr, start, mid)
            mergeSort(arr, mid + 1, end)
            merge(arr, start, mid, end)
  
      merge(arr, start, mid, end):
        // Implementation of merging two sorted sub-arrays
```

## Time Complexity

- Best Case: O(n log n)
- Average Case: O(n log n)
- Worst Case: O(n log n)

## Space Complexity

Merge Sort requires additional space for temporary arrays during the merge phase. The space complexity is O(n).

## Advantages

- Stable sorting algorithm (maintains the relative order of equal elements).
- Predictable performance.

## Disadvantages

- Requires additional space for merging.
- Slower for small datasets compared to some other algorithms.

## Usage

Merge Sort is a classic algorithm widely used in various applications where stable and predictable sorting is required. Its consistent performance makes it a reliable choice for sorting large datasets.
