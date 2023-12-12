#include<iostream>
using namespace std;

class heap {
public:
    int arr[100];
    int size;

    heap() {
        // Constructor to initialize the heap with a sentinel value and size 0
        arr[0] = -1;
        size = 0;
    }

    void insertIntoHeap(int val) {
        // Function to insert a value into the heap
        size += 1;
        int index = size;

        arr[index] = val;

        // Adjust the heap by swapping with the parent if necessary
        while (index > 1) {
            int parent = index / 2;

            if (arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else {
                return; // Break the loop if the heap property is restored
            }
        }
    }

    void print() {
        // Function to print the elements of the heap
        cout << "Heap: ";
        for (int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void deleteFromHeap() {
        // Function to delete the root (max element) from the heap
        if (size == 0) {
            cout << "Nothing to delete from" << endl;
        }

        // Replace the root with the last element and reduce the size
        arr[1] = arr[size];
        size--;

        int i = 1;
        // Adjust the heap by swapping with the larger child if necessary
        while (i < size) {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;

            if (leftIndex <= size && arr[i] < arr[leftIndex]) {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }
            else if (rightIndex <= size && arr[i] < arr[rightIndex]) {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else {
                return; // Break the loop if the heap property is restored
            }
        }
    }
};

void heapify(int arr[], int n, int i) {
    // Function to heapify an array
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[largest] < arr[left]) {
        largest = left;
    }
    if (right <= n && arr[largest] < arr[right]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    // Function to perform heap sort on an array
    int size = n;
    while (size > 1) {
        // Swap the root (max element) with the last element
        swap(arr[size], arr[1]);

        // Remove the last element from consideration
        size--;

        // Heapify the remaining elements
        heapify(arr, size, 1);
    }
}

int main() {

    heap h;
    h.insertIntoHeap(50);
    h.insertIntoHeap(55);
    h.insertIntoHeap(60);
    h.insertIntoHeap(70);
    h.insertIntoHeap(21);
    h.insertIntoHeap(80);
    h.insertIntoHeap(2);

    // Print the original heap
    h.print();

    // Delete the root (max element) from the heap
    h.deleteFromHeap();
    // Print the heap after deletion
    h.print();

    int arr[8] = {-1, 50, 55, 60, 70, 21, 80, 2};
    int n = 7;

    // Heap creation for an array
    for (int i = n / 2; i > 0; i--) {
        heapify(arr, n, i);
    }

    cout << "printing the array now" << endl;

    // Print the array after heap creation
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Perform heap sort
    heapSort(arr, n);

    cout << "printing the sorted array now" << endl;

    // Print the sorted array after heap sort
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
