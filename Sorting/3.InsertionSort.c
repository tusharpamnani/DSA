#include <stdio.h>

// Function to perform insertion sort
void insertionSort(int arr[], int n) {
    int i, key, j;
    
    // Iterate through each element of the array starting from the second element
    for (i = 1; i < n; i++) {
        // Current element to be compared
        key = arr[i];
        
        // Move elements of arr[0..i-1] that are greater than key
        // to one position ahead of their current position
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        
        // Place the current element at its correct position
        arr[j + 1] = key;
    }
}

int main() {
    int n;
    
    // Input the size of the array
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    
    // Input the elements of the array
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Call the insertionSort function to sort the array
    insertionSort(arr, n);
    
    // Display the sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}
