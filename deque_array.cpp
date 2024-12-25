#include <iostream>
using namespace std;

class DequeArray {
    static const int MAX_SIZE = 10;  // Maximum size of the deque
    int* deque;                     // Pointer to dynamically allocated array for the deque
    int front, rear, size;          // Front and rear pointers, and size of the deque

public:
    // Constructor to initialize the deque
    DequeArray(int size) {
        this->size = size;           // Set the size of the deque
        deque = new int[size];       // Dynamically allocate memory for the deque array
        front = rear = -1;           // Initially, both front and rear are -1 (empty deque)
    }

    // Check if the deque is empty
    bool isEmpty() {
        return front == -1;  // The deque is empty if front is -1
    }

    // Check if the deque is full
    bool isFull() {
        // The deque is full if (rear + 1) % size equals front
        return (rear + 1) % size == front;
    }

    // Insert a value at the front of the deque
    void insertFront(int value) {
        if (isFull()) {
            cout << "Overflow" << endl;  // Display overflow message if deque is full
            return;
        }
        if (isEmpty()) {
            front = rear = 0;  // If deque is empty, set both front and rear to 0
        } else {
            front = (front - 1 + size) % size;  // Move the front pointer circularly
        }
        deque[front] = value;  // Place the value at the front of the deque
    }

    // Insert a value at the rear of the deque
    void insertRear(int value) {
        if (isFull()) {
            cout << "Overflow" << endl;  // Display overflow message if deque is full
            return;
        }
        if (isEmpty()) {
            front = rear = 0;  // If deque is empty, set both front and rear to 0
        } else {
            rear = (rear + 1) % size;  // Move the rear pointer circularly
        }
        deque[rear] = value;  // Place the value at the rear of the deque
    }

    // Delete an element from the front of the deque
    void deleteFront() {
        if (isEmpty()) {
            cout << "Underflow" << endl;  // Display underflow message if deque is empty
            return;
        }
        if (front == rear) {
            front = rear = -1;  // If only one element is left, reset front and rear to -1
        } else {
            front = (front + 1) % size;  // Move the front pointer circularly
        }
    }

    // Delete an element from the rear of the deque
    void deleteRear() {
        if (isEmpty()) {
            cout << "Underflow" << endl;  // Display underflow message if deque is empty
            return;
        }
        if (front == rear) {
            front = rear = -1;  // If only one element is left, reset front and rear to -1
        } else {
            rear = (rear - 1 + size) % size;  // Move the rear pointer circularly
        }
    }

    // Display the elements of the deque
    void display() {
        if (isEmpty()) {
            cout << "Deque is empty" << endl;  // Print message if deque is empty
            return;
        }
        int i = front;
        cout << "Deque: ";
        while (true) {
            cout << deque[i] << " ";  // Print the current element
            if (i == rear) break;  // Stop if the rear is reached
            i = (i + 1) % size;  // Move to the next element circularly
        }
        cout << endl;
    }
};

int main() {
    const int MAX_SIZE = 10;
    DequeArray deque(MAX_SIZE);  // Create a deque object with a maximum size
    
    int dequeType;
    do {
        cout << "Choose deque type:" << endl;
        cout << "1. Input Restricted" << endl;
        cout << "2. Output Restricted" << endl;
        cout << "Your choice: ";
        cin >> dequeType;  // User input for deque type
    } while (dequeType < 1 || dequeType > 2);  // Keep asking until a valid choice is entered

    while (true) {
        cout << "\nChoose an operation:" << endl;
        if (dequeType == 1) {  // Input Restricted
            cout << "1. Insert at Rear" << endl;
            cout << "2. Delete from Front" << endl;
            cout << "3. Delete from Rear" << endl;
        } else {  // Output Restricted
            cout << "1. Insert at Front" << endl;
            cout << "2. Insert at Rear" << endl;
            cout << "3. Delete from Front" << endl;
        }
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
        cout << "Your choice: ";
        int choice;
        cin >> choice;  // User input for operation choice

        if (choice == 5) break;  // Exit the loop if user chooses 5

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                int value;
                cin >> value;  // User input for value
                if (dequeType == 1)
                    deque.insertRear(value);  // Insert at rear for input restricted deque
                else
                    deque.insertFront(value);  // Insert at front for output restricted deque
                break;
            case 2:
                if (dequeType == 1)
                    deque.deleteFront();  // Delete from front for input restricted deque
                else {
                    cout << "Enter value: ";
                    cin >> value;  // User input for value
                    deque.insertRear(value);  // Insert at rear for output restricted deque
                }
                break;
            case 3:
                if (dequeType == 1)
                    deque.deleteRear();  // Delete from rear for input restricted deque
                else
                    deque.deleteFront();  // Delete from front for output restricted deque
                break;
            case 4:
                deque.display();  // Display the current elements in the deque
                break;
            default:
                cout << "Invalid choice" << endl;  // Handle invalid user input
        }
    }

    return 0;
}
