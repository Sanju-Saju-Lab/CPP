#include <iostream>
using namespace std;

const int ROWS = 4;  // Number of rows in the 2D array
const int COLS = 4;  // Number of columns in the 2D array
int array[ROWS][COLS] = {0};  // 2D array initialized with 0

// Function to display all elements in the array
void traverse() {
    cout << "Array elements:" << endl;
    // Loop through each row
    for (int i = 0; i < ROWS; i++) {
        // Loop through each column in the current row
        for (int j = 0; j < COLS; j++) {
            cout << array[i][j] << " ";  // Print each element in the array
        }
        cout << endl;  // Move to the next line after printing a row
    }
}

// Function to insert a value at a specific row and column
void insert(int row, int col, int value) {
    // Check if the provided row and column are within valid bounds
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        cout << "Invalid index." << endl;
    } else {
        array[row][col] = value;  // Insert the value at the specified position
        cout << "Element inserted successfully." << endl;
    }
}

// Function to delete an element (set it to 0) at a specific row and column
void delete_element(int row, int col) {
    // Check if the provided row and column are within valid bounds
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        cout << "Invalid index." << endl;
    } else {
        array[row][col] = 0;  // Set the specified element to 0
        cout << "Element deleted successfully." << endl;
    }
}

// Function to search for an element by its row and column index
void search_by_index(int row, int col) {
    // Check if the provided row and column are within valid bounds
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        cout << "Invalid index." << endl;
    } else {
        cout << "Element at [" << row << "][" << col << "]: " << array[row][col] << endl;
    }
}

// Function to search for an element by its value
void search_by_value(int value) {
    // Loop through each element in the array
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (array[i][j] == value) {  // If the value is found
                cout << "Value " << value << " found at index [" << i << "][" << j << "]." << endl;
                return;  // Exit the function once the value is found
            }
        }
    }
    cout << "Value not found." << endl;  // If the value is not found in the array
}

// Function to update an element at a specific row and column
void update(int row, int col, int value) {
    // Check if the provided row and column are within valid bounds
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        cout << "Invalid index." << endl;
    } else {
        array[row][col] = value;  // Update the element at the specified position
        cout << "Element updated successfully." << endl;
    }
}

// Main function to interact with the user and perform operations
int main() {
    while (true) {
        cout << "\nChoose an operation:" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Traverse" << endl;
        cout << "4. Search" << endl;
        cout << "5. Update" << endl;
        cout << "6. Exit" << endl;

        int choice;
        cout << "Your Choice: ";
        cin >> choice;  // Take user input for the operation to perform
        
        if (choice == 1) {
            // Get row, column, and value to insert
            int row, col, value;
            cout << "Enter row (0-" << ROWS-1 << "): ";
            cin >> row;
            cout << "Enter column (0-" << COLS-1 << "): ";
            cin >> col;
            cout << "Enter value to insert: ";
            cin >> value;
            insert(row, col, value);  // Call the insert function
        } else if (choice == 2) {
            // Get row and column to delete
            int row, col;
            cout << "Enter row (0-" << ROWS-1 << "): ";
            cin >> row;
            cout << "Enter column (0-" << COLS-1 << "): ";
            cin >> col;
            delete_element(row, col);  // Call the delete function
        } else if (choice == 3) {
            traverse();  // Call the traverse function to display the array
        } else if (choice == 4) {
            // Ask user whether to search by index or value
            int search_type;
            cout << "Enter 1 to search by row and column, 2 by value: ";
            cin >> search_type;
            if (search_type == 1) {
                // Get row and column for searching
                int row, col;
                cout << "Enter row (0-" << ROWS-1 << "): ";
                cin >> row;
                cout << "Enter column (0-" << COLS-1 << "): ";
                cin >> col;
                search_by_index(row, col);  // Call the search by index function
            } else if (search_type == 2) {
                // Get value to search for
                int value;
                cout << "Enter value to search: ";
                cin >> value;
                search_by_value(value);  // Call the search by value function
            } else {
                cout << "Invalid option." << endl;  // Handle invalid option
            }
        } else if (choice == 5) {
            // Get row, column, and new value to update
            int row, col, value;
            cout << "Enter row (0-" << ROWS-1 << "): ";
            cin >> row;
            cout << "Enter column (0-" << COLS-1 << "): ";
            cin >> col;
            cout << "Enter new value: ";
            cin >> value;
            update(row, col, value);  // Call the update function
        } else if (choice == 6) {
            cout << "Exiting program." << endl;  // Exit the program
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;  // Handle invalid choice
        }
    }
    return 0;  // End of the program
}
