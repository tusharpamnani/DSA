#include<iostream>
using namespace std;

// Function to merge two sorted halves of an array
void merge(int *arr, int start, int end){

    // Find the middle of the array
    int mid = (start + end) / 2;

    // Calculate the lengths of the two halves
    int length1 = mid - start + 1;
    int length2 = end - mid;

    // Create temporary arrays to store the two halves
    int *first = new int[length1];
    int *second = new int[length2];

    // Copy values from the start of the original array to the first temporary array
    int mainArrayIndex = start;
    for(int i = 0; i < length1; i++){
        first[i] = arr[mainArrayIndex++];
    }

    // Copy values from mid + 1 of the original array to the second temporary array
    mainArrayIndex = mid + 1;
    for(int i = 0; i < length2; i++){
        second[i] = arr[mainArrayIndex++];
    }

    // Merge the two sorted arrays back into the original array
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = start;

    while(index1 < length1 && index2 < length2){
        if(first[index1] < second[index2]){
            arr[mainArrayIndex++] = first[index1++];
        } else{
            arr[mainArrayIndex++] = second[index2++];
        }
    }

    // Copy the remaining elements of the first array, if any
    while (index1 < length1){
        arr[mainArrayIndex++] = first[index1++];
    }
    
    // Copy the remaining elements of the second array, if any
    while (index2 < length2){
        arr[mainArrayIndex++] = second[index2++];
    }

    // Deallocate memory used for temporary arrays
    delete[] first;
    delete[] second;
}

// Function to perform merge sort on an array
void mergeSort(int *arr, int start, int end){

    // Base case: if the array has one element or is empty, it is already sorted
    if(start >= end){
        return;
    }

    // Find the middle of the array
    int mid = (start + end) / 2;

    // Recursively sort the left and right halves of the array
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);

    // Merge the sorted halves
    merge(arr, start, end);
}

int main(){

    // Sample array to be sorted
    int arr[5] = {2, 1, 5, 8, 7};
    int n = 5;

    // Call mergeSort to sort the array
    mergeSort(arr, 0, n - 1);

    // Print the sorted array
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    
    return 0;
}
