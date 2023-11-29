#include <iostream>
using namespace std;

// Function to partition the array and return the index of the pivot element
int partition(int arr[], int start, int end){
    // Choose the first element as the pivot
    int pivot = arr[start];

    // Count the number of elements less than or equal to the pivot
    int count = 0;

    for (int i = start + 1; i <= end; i++){
        if(arr[i] <= pivot){
            count++;
        }
    }
    
    // Place the pivot at the right place in the sorted array
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);

    // Initialize two pointers
    int i = start, j = end;

    // Partition the array into elements less than or equal to the pivot and greater than the pivot
    while(i < pivotIndex && j > pivotIndex){
        while(arr[i] <= pivot){
            i++;
        }
        while(arr[j] > pivot){ 
            j--;
        }
        // Swap elements to maintain the partition
        if(i < pivotIndex && j > pivotIndex){
            swap(arr[i++], arr[j--]);
        }
    }

    // Return the index of the pivot element
    return pivotIndex;
}

// Function to perform quicksort on an array
void quickSort(int arr[], int start, int end){
    // Base case: if the array has one element or is empty, it is already sorted
    if(start >= end){
        return;
    }

    // Partition the array and get the index of the pivot element
    int p = partition(arr, start, end);

    // Recursively sort the left and right parts of the array
    quickSort(arr, start, p - 1);
    quickSort(arr, p + 1, end);
}

int main(){

    int arr[5] = {9, 8, 85, 1, 31};
    int n = 5;

    // Call quickSort to sort the array
    quickSort(arr, 0, n - 1);

    // Print the sorted array
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}
