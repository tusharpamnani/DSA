#include<iostream>
using namespace std;

// Function to perform binary search in a sorted array
// Parameters:
//   arr: the sorted array
//   size: the size of the array
//   key: the element to search for
// Returns:
//   The index of the searched element if found, -1 otherwise
int binarySearch(int arr[], int size, int key){
    int start = 0;
    int end = size - 1;
    int mid = (start + end) / 2;

    // Continue searching until the search space is not empty
    while (start <= end){
        // If the middle element is the key, return its index
        if (arr[mid] == key){
            return mid;
        }

        // If the key is in the right part, update the start index
        if (arr[mid] < key){
            start = mid + 1;
        }
        // If the key is in the left part, update the end index
        else{
            end = mid - 1;
        }

        // Recalculate the middle index for the next iteration
        mid = (start + end) / 2;
    }

    // If the key is not found, return -1
    return -1;
}

int main(){

    int even[6] = {2, 4, 6, 8, 12, 18};
    int odd[5] = {3, 8, 11, 13, 16};

    // Search for the key (12) in the even array
    int evenIndex = binarySearch(even, 6, 12);

    // Search for the key (12) in the odd array
    int oddIndex = binarySearch(odd, 5, 12);

    // Print the results
    cout << "Index of searched element in even array: " << evenIndex << endl;
    cout << "Index of searched element in odd array: " << oddIndex << endl;

    return 0;
}
