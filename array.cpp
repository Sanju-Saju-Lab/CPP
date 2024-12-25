#include <iostream>
using namespace std;

#define MAX_SIZE 10 // Maximum size of the array

int array[MAX_SIZE]; // Array to store elements
int size = 0; // Current number of elements in the array

// Function to display all elements in the array
void traverse() {
    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " "; // Print each element
    }
    cout << endl;
}

// Function to insert a new element at a specific index
void insert(int index, int value) {
    if (size >= MAX_SIZE) { // Check if the array is full
        cout << "Array is full. Cannot insert new element." << endl;
        return;
    }
    if (index < 0 || index > size) { // Check for a valid index
        cout << "Invalid index." << endl;
        return;
    }
    // Shift elements to the right to make space for the new element
    for (int i = size; i > index; i--) {
        array[i] = array[i - 1];
    }
    array[index] = value; // Insert the new element
    size++; // Increase the size of the array
    cout << "Element inserted successfully." << endl;
}

// Function to delete an element at a specific index
void deleteElement(int index) {
    if (index < 0 || index >= size) { // Check for a valid index
        cout << "Invalid index." << endl;
        return;
    }
    // Shift elements to the left to fill the gap
    for (int i = index; i < size - 1; i++) {
        array[i] = array[i + 1];
    }
    size--; // Decrease the size of the array
    cout << "Element deleted successfully." << endl;
}

// Function to search for an element by its index
void searchByIndex(int index) {
    if (index < 0 || index >= size) { // Check for a valid index
        cout << "Invalid index." << endl;
        return;
    }
    // Display the element at the specified index
    cout << "Element at index " << index << ": " << array[index] << endl;
}

// Function to search for an element by its value
void searchByValue(int value) {
    for (int i = 0; i < size; i++) {
        if (array[i] == value) { // Check if the value matches
            cout << "Value " << value << " found at index " << i << "." << endl;
            return;
        }
    }
    // If the value is not found
    cout << "Value not found." << endl;
}

// Function to update an element at a specific index
void update(int index, int value) {
    if (index < 0 || index >= size) { // Check for a valid index
        cout << "Invalid index." << endl;
        return;
    }
    array[index] = value; // Update the element
    cout << "Element updated successfully." << endl;
}

// Main function to run the program
int main() {
    int choice; // Variable to store user choice
    while (true) { // Infinite loop for menu
        cout << "\nChoose an operation:\n1. Insert\n2. Delete\n3. Traverse\n4. Search\n5. Update\n6. Exit\nYour Choice: ";
        cin >> choice;

        if (choice == 1) { // Insert operation
            int index, value;
            cout << "Enter index to insert (0-" << MAX_SIZE - 1 << "): ";
            cin >> index;
            cout << "Enter value to insert: ";
            cin >> value;
            insert(index, value);
        } else if (choice == 2) { // Delete operation
            int index;
            cout << "Enter index to delete: ";
            cin >> index;
            deleteElement(index);
        } else if (choice == 3) { // Traverse operation
            traverse();
        } else if (choice == 4) { // Search operation
            int searchType;
            cout << "Enter 1 to search by index, 2 by value: ";
            cin >> searchType;
            if (searchType == 1) {
                int index;
                cout << "Enter index to search: ";
                cin >> index;
                searchByIndex(index);
            } else if (searchType == 2) {
                int value;
                cout << "Enter value to search: ";
                cin >> value;
                searchByValue(value);
            } else {
                cout << "Invalid option." << endl;
            }
        } else if (choice == 5) { // Update operation
            int index, value;
            cout << "Enter index to update: ";
            cin >> index;
            cout << "Enter new value: ";
            cin >> value;
            update(index, value);
        } else if (choice == 6) { // Exit the program
            cout << "Exiting program." << endl;
            break;
        } else { // Handle invalid choices
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0; // End of program
}
