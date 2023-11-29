# Binary Search Algorithm

## Overview

Binary Search is a highly efficient searching algorithm that works on the principle of divide and conquer. It is applicable to a sorted array and repeatedly divides the search interval in half to locate the target element. The algorithm efficiently reduces the search space by half with each comparison, making it particularly useful for large datasets.

## How it Works

1. **Initialize:** Set the start and end indices to define the search interval.
2. **Midpoint Calculation:** Calculate the midpoint of the search interval.
3. **Comparison:** Compare the element at the midpoint with the target element.
4. **Adjustment:** Adjust the search interval based on the result of the comparison.
5. **Repeat:** Repeat the process until the target element is found or the search interval is empty.


## Pseudocode

```plaintext
binarySearch(arr, size, key):
    start = 0
    end = size - 1
    mid = (start + end) / 2

    while start <= end:
        if arr[mid] == key:
            return mid
        if arr[mid] < key:
            start = mid + 1
        else:
            end = mid - 1
        mid = (start + end) / 2

    return -1
```

## Time Complexity

- **Best Case:** O(1) (constant time for a single comparison)
- **Average Case:** O(log n) (base 2 logarithm)
- **Worst Case:** O(log n)

## Space Complexity

Binary Search is an in-place algorithm, meaning it doesn't require additional memory proportional to the size of the input.

## Advantages

- Efficient for large datasets.
- Logarithmic time complexity.

## Disadvantages

- Requires a sorted array.
- Not applicable to unsorted or dynamically changing datasets.

## Applications

1. **Searching in Databases:**
   Binary Search is commonly used in database systems to quickly locate records.

2. **Sorting Algorithms:**
   Binary Search is an integral part of many sorting algorithms.

3. **Computer Graphics:**
   Used in computer graphics algorithms for tasks like ray tracing.

4. **Game Development:**
   Applied in game development for searching and retrieving game elements efficiently.

## Usage

Binary Search is a fundamental algorithm widely used in various applications where efficient searching is required. It is especially suitable for scenarios with large sorted datasets.
