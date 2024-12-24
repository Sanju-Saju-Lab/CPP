#include <iostream>
using namespace std;

class QueueArray {
private:
    static const int MAX_SIZE = 10;  // Maximum size of the queue
    int queue[MAX_SIZE];  // Array to store the queue elements
    int front = -1;  // Front pointer, set to -1 when the queue is empty
    int rear = -1;   // Rear pointer, set to -1 when the queue is empty

public:
    // Adds an element to the queue
    void enqueue(int element) {
        if (isFull()) {  // Check if the queue is full
            cout << "Queue is full. Cannot add element: " << element << endl;
            return;
        }
        if (front == -1 && rear == -1) {  // If the queue is empty
            front = 0;  // Set the front pointer to 0
            rear = 0;   // Set the rear pointer to 0
        } else {
            rear++;  // Move the rear pointer to the next position
        }
        queue[rear] = element;  // Add the element at the rear position
        cout << "Enqueued: " << element << endl;  // Confirm the addition of the element
    }

    // Removes and returns the front element of the queue
    int dequeue() {
        if (isEmpty()) {  // Check if the queue is empty
            cout << "Queue is empty. Cannot remove element." << endl;
            return -1;  // Return -1 if the queue is empty
        }
        int element = queue[front];  // Get the front element
        front++;  // Move the front pointer to the next position
        if (front > rear) {  // If the queue becomes empty after the dequeue
            front = -1;  // Reset front pointer
            rear = -1;   // Reset rear pointer
        }
        return element;  // Return the dequeued element
    }

    // Returns the front element without removing it
    int peek() {
        if (isEmpty()) {  // Check if the queue is empty
            cout << "Queue is empty. Nothing to peek." << endl;
            return -1;  // Return -1 if the queue is empty
        }
        return queue[front];  // Return the front element
    }

    // Checks if the queue is empty
    bool isEmpty() {
        return front == -1 && rear == -1;  // True if both front and rear are -1
    }

    // Checks if the queue is full
    bool isFull() {
        return rear == MAX_SIZE - 1;  // True if rear is at the last position of the array
    }

    // Displays all elements in the queue
    void display() {
        if (isEmpty()) {  // Check if the queue is empty
            cout << "Queue is empty." << endl;  // Inform the user if the queue is empty
            return;
        }
        cout << "Queue elements: ";  // Start displaying elements
        for (int i = front; i <= rear; i++) {  // Loop through elements from front to rear
            cout << queue[i] << " ";  // Print each element
        }
        cout << endl;  // Print a newline after displaying all elements
    }
};

int main() {
    QueueArray queue;  // Create a QueueArray object
    int choice;
    while (true) {  // Infinite loop for user interaction
        cout << "\nChoose an operation:" << endl;
        cout << "1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\nYour choice: ";
        cin >> choice;  // Get user's choice

        switch (choice) {
            case 1:  // Enqueue operation
                int element;
                cout << "Enter element to enqueue: ";  // Ask user for an element
                cin >> element;  // Get element from the user
                queue.enqueue(element);  // Call enqueue method to add element
                break;
            case 2:  // Dequeue operation
                int dequeuedElement;
                dequeuedElement = queue.dequeue();  // Call dequeue method to remove element
                if (dequeuedElement != -1) {  // If the element is successfully dequeued
                    cout << "Dequeued: " << dequeuedElement << endl;  // Display the dequeued element
                }
                break;
            case 3:  // Peek operation
                int peekedElement;
                peekedElement = queue.peek();  // Call peek method to see front element
                if (peekedElement != -1) {  // If there is an element to peek
                    cout << "Front element: " << peekedElement << endl;  // Display the front element
                }
                break;
            case 4:  // Display operation
                queue.display();  // Call display method to show all elements in the queue
                break;
            case 5:  // Exit operation
                cout << "Exiting program. Goodbye!" << endl;  // Exit the program
                return 0;  // End the program
            default:  // Invalid choice
                cout << "Invalid choice. Please try again." << endl;  // Prompt the user to try again
        }
    }
}
