#include <iostream>
using namespace std;

// Function to perform selection sort
void selectionSort(int arr[], int n) {
    // Loop through the entire array
    for (int i = 0; i < n - 1; i++) {
        // Assume the first unsorted element is the smallest
        int minIndex = i;
        
        // Loop through the remaining unsorted part of the array
        for (int j = i + 1; j < n; j++) {
            // If we find a smaller element, update minIndex
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // If the smallest element is not in the correct position, swap it
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);  // Swap the elements
        }
    }
}

int main() {
    int n;

    // Ask the user to enter the number of elements
    cout << "Enter the number of elements: ";
    cin >> n;
    
    // Declare an array of size n to hold the elements
    int arr[n];

    // Ask the user to input the elements for the array
    cout << "Enter the elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];  // Store each element in the array
    }

    // Call the selectionSort function to sort the array
    selectionSort(arr, n);

    // Display the sorted array
    cout << "Sorted array:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";  // Print each sorted element
    }

    return 0;
}
