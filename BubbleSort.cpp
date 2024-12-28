#include <iostream>
using namespace std;

// Function to perform Bubble Sort on the given array
void bubbleSort(int arr[], int n) {
    // Outer loop: Repeats passes to move elements to their correct positions
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;  // Flag to track if any elements were swapped in this pass
        // Inner loop: Compares adjacent elements and swaps them if they are in the wrong order
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {  // If the current element is greater than the next
                swap(arr[j], arr[j + 1]);  // Swap the two elements
                swapped = true;  // Mark that a swap occurred
            }
        }
        // If no swaps were made, the list is already sorted, so exit the loop early
        if (!swapped) {
            break;
        }
    }
}

int main() {
    int n;
    // Asking the user for the number of elements they want to sort
    cout << "Enter the number of elements: ";
    cin >> n;
    
    int arr[n];  // Declaring an array of size n
    cout << "Enter the elements: " << endl;
    // Reading the elements from the user and storing them in the array
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Calling the bubbleSort function to sort the array
    bubbleSort(arr, n);

    // Displaying the sorted array to the user
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";  // Printing each element of the sorted array
    }
    return 0;
}
