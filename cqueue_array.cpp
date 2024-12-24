#include <iostream>
using namespace std;

class CQueueArray {
    static const int MAX_SIZE = 10;  // Maximum size of the queue
    int queue[MAX_SIZE];  // Array to store the queue elements
    int front, rear;  // Front and rear pointers for the queue

public:
    // Constructor to initialize front and rear to -1 (empty queue)
    CQueueArray() {
        front = rear = -1;
    }

    // Enqueue operation: Add an element to the queue
    void enqueue(int value) {
        // Check if the queue is full
        if ((rear + 1) % MAX_SIZE == front) {
            cout << "Queue is full!" << endl;  // Cannot enqueue if full
        } else {
            // If the queue is empty, set front to 0
            if (front == -1) {
                front = 0;
            }
            // Move rear to the next position (circularly)
            rear = (rear + 1) % MAX_SIZE;
            queue[rear] = value;  // Store the value in the queue
            cout << value << " enqueued." << endl;  // Confirm the enqueue
        }
    }

    // Dequeue operation: Remove an element from the queue
    void dequeue() {
        // Check if the queue is empty
        if (front == -1) {
            cout << "Queue is empty!" << endl;  // Cannot dequeue if empty
        } else {
            cout << queue[front] << " dequeued." << endl;  // Print the dequeued element
            // If the queue becomes empty after this dequeue, reset front and rear to -1
            if (front == rear) {
                front = rear = -1;
            } else {
                // Move front to the next position (circularly)
                front = (front + 1) % MAX_SIZE;
            }
        }
    }

    // Peek operation: View the element at the front of the queue
    void peek() {
        // Check if the queue is empty
        if (front == -1) {
            cout << "Queue is empty!" << endl;  // Cannot peek if empty
        } else {
            cout << "Front element is: " << queue[front] << endl;  // Display the front element
        }
    }

    // Display operation: Show all elements in the queue
    void display() {
        // Check if the queue is empty
        if (front == -1) {
            cout << "Queue is empty!" << endl;  // Nothing to display if empty
        } else {
            int i = front;
            cout << "Queue elements: ";
            // Traverse through the queue and print all elements
            while (i != rear) {
                cout << queue[i] << " ";
                i = (i + 1) % MAX_SIZE;  // Move to the next element (circularly)
            }
            cout << queue[rear] << endl;  // Print the last element
        }
    }
};

int main() {
    CQueueArray cqueue;  // Create an object of CQueueArray class
    int choice, value;

    do {
        // Menu options for the user to select an operation
        cout << "\nChoose an Operation:" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display Queue" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // Perform the selected operation
        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                cqueue.enqueue(value);  // Call the enqueue function
                break;
            case 2:
                cqueue.dequeue();  // Call the dequeue function
                break;
            case 3:
                cqueue.peek();  // Call the peek function
                break;
            case 4:
                cqueue.display();  // Call the display function
                break;
            case 5:
                cout << "Exiting..." << endl;  // Exit the program
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;  // Handle invalid input
        }
    } while (choice != 5);  // Continue until user chooses to exit

    return 0;  // End of program
}
