#include <iostream>
using namespace std;

// Function to perform Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Find the partition index where the pivot is placed
        int pi = partition(arr, low, high);
        // Recursively sort the left part of the array
        quickSort(arr, low, pi - 1);
        // Recursively sort the right part of the array
        quickSort(arr, pi + 1, high);
    }
}

// Function to partition the array into two parts based on the pivot
int partition(int arr[], int low, int high) {
    // Choose the last element as the pivot
    int pivot = arr[high];
    // Index of the smaller element
    int i = low - 1;
    
    // Loop through the array to rearrange elements
    for (int j = low; j < high; j++) {
        // If the current element is smaller than the pivot
        if (arr[j] < pivot) {
            i++;  // Increment the index of smaller element
            // Swap the current element with the element at i
            swap(arr[i], arr[j]);
        }
    }
    
    // Place the pivot element in its correct position
    swap(arr[i + 1], arr[high]);
    return i + 1;  // Return the partition index
}

// Function to swap two elements in the array
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";  // Print each element of the array
    }
    cout << endl;  // Print a new line after printing the array
}

// Main function to input elements, perform sorting, and print the result
int main() {
    int n;
    // Ask the user for the number of elements
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    // Ask the user to input the elements of the array
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Call quickSort function to sort the array
    quickSort(arr, 0, n - 1);

    // Print the sorted array
    cout << "Sorted Array: ";
    printArray(arr, n);
    return 0;
}
