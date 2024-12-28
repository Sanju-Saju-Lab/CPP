#include <iostream>
#include <vector>
using namespace std;

// Function to perform merge sort
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;  // Find the middle of the array
        mergeSort(arr, left, mid);  // Recursively sort the first half
        mergeSort(arr, mid + 1, right);  // Recursively sort the second half

        // Merge the sorted halves
        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<int> leftArr(n1), rightArr(n2);
        for (int i = 0; i < n1; i++) leftArr[i] = arr[left + i];
        for (int i = 0; i < n2; i++) rightArr[i] = arr[mid + 1 + i];

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (leftArr[i] <= rightArr[j]) {
                arr[k] = leftArr[i];
                i++;
            } else {
                arr[k] = rightArr[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k] = leftArr[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = rightArr[j];
            j++;
            k++;
        }
    }
}

// Function to print an array
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// Main function
int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Original Array:" << endl;
    printArray(arr);

    mergeSort(arr, 0, n - 1);  // Perform merge sort

    cout << "Sorted Array:" << endl;
    printArray(arr);

    return 0;
}
