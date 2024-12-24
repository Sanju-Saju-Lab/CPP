#include <iostream>
using namespace std;

class Stack {
private:
    static const int MAX_SIZE = 10; // Maximum capacity of the stack
    int stack[MAX_SIZE];  // Array to store stack elements
    int top;              // Index of the top element

public:
    // Constructor to initialize the stack
    Stack() {
        top = -1;  // Initialize the stack as empty
    }

    // Push operation
    void push(int item) {
        if (isFull()) {
            cout << "Stack Overflow! Can't push " << item << endl;
        } else {
            stack[++top] = item;
            cout << "Pushed: " << item << endl;
        }
    }

    // Pop operation
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Can't pop." << endl;
            return -1;
        } else {
            return stack[top--];
        }
    }

    // Peek operation
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        } else {
            return stack[top];
        }
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Check if the stack is full
    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    // Display the stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
        } else {
            cout << "Stack (top to bottom): ";
            for (int i = 0; i <= top; i++) {
                cout << stack[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Stack stack;  // Create a stack with the fixed size

    while (true) {
        cout << "\nChoose an operation:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                int value;
                cout << "Enter the value to push: ";
                cin >> value;
                stack.push(value);
                break;
            }
            case 2: {
                int poppedValue = stack.pop();
                if (poppedValue != -1) {
                    cout << "Popped: " << poppedValue << endl;
                }
                break;
            }
            case 3: {
                int topValue = stack.peek();
                if (topValue != -1) {
                    cout << "Top element: " << topValue << endl;
                }
                break;
            }
            case 4:
                stack.display();
                break;
            case 5:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
