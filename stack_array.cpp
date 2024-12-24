#include <iostream>
using namespace std;

class Stack {
private:
    static const int MAX_SIZE = 10;  // Maximum size of the stack
    int stack[MAX_SIZE];  // Array to hold stack elements
    int top;  // Index of the top element in the stack

public:
    // Constructor to initialize the stack
    Stack() {
        top = -1;  // Set top to -1 to indicate the stack is empty
    }

    // Function to add an element to the stack
    void push(int item) {
        if (isFull()) {  // Check if the stack is full
            cout << "Stack Overflow! Can't push " << item << endl;
        } else {
            stack[++top] = item;  // Add item to the stack and increment the top index
            cout << "Pushed: " << item << endl;
        }
    }

    // Function to remove and return the top element from the stack
    int pop() {
        if (isEmpty()) {  // Check if the stack is empty
            cout << "Stack Underflow! Can't pop." << endl;
            return -1;  // Return -1 if the stack is empty
        } else {
            return stack[top--];  // Return the top element and decrement the top index
        }
    }

    // Function to return the top element without removing it
    int peek() {
        if (isEmpty()) {  // Check if the stack is empty
            cout << "Stack is empty!" << endl;
            return -1;  // Return -1 if the stack is empty
        } else {
            return stack[top];  // Return the top element of the stack
        }
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == -1;  // If top is -1, the stack is empty
    }

    // Function to check if the stack is full
    bool isFull() {
        return top == MAX_SIZE - 1;  // If top is at MAX_SIZE - 1, the stack is full
    }

    // Function to display all elements in the stack
    void display() {
        if (isEmpty()) {  // Check if the stack is empty
            cout << "Stack is empty!" << endl;
        } else {
            cout << "Stack (top to bottom): ";
            for (int i = 0; i <= top; i++) {  // Loop through the stack and print each element
                cout << stack[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Stack stack;  // Create an instance of the Stack class

    while (true) {  // Infinite loop to keep the program running until user exits
        // Display menu options to the user
        cout << "\nChoose an operation:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;  // Take input from the user

        switch (choice) {  // Perform the selected operation
            case 1: {  // Push operation
                int value;
                cout << "Enter the value to push: ";
                cin >> value;  // Take the value to push into the stack
                stack.push(value);  // Push the value onto the stack
                break;
            }
            case 2: {  // Pop operation
                int poppedValue = stack.pop();  // Pop the top element from the stack
                if (poppedValue != -1) {  // If the stack wasn't empty
                    cout << "Popped: " << poppedValue << endl;
                }
                break;
            }
            case 3: {  // Peek operation
                int topValue = stack.peek();  // Get the top element without removing it
                if (topValue != -1) {  // If the stack wasn't empty
                    cout << "Top element: " << topValue << endl;
                }
                break;
            }
            case 4:  // Display the stack
                stack.display();
                break;
            case 5:  // Exit the program
                cout << "Exiting program." << endl;
                return 0;
            default:  // Handle invalid input
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
