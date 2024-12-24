#include <iostream>
using namespace std;

const int MAX_SIZE = 10; // Define maximum size of the queue

class QueueArray {
private:
    int queue[MAX_SIZE]; // Array to store queue elements
    int front;
    int rear;
    int size;

public:
    // Constructor
    QueueArray() {
        front = 0;
        rear = -1;
        size = 0;
    }

    // Enqueue operation
    void enqueue(int element) {
        if (isFull()) {
            cout << "Queue is full. Cannot add element: " << element << endl;
            return;
        }
        rear = (rear + 1) % MAX_SIZE;
        queue[rear] = element;
        size++;
        cout << "Enqueued: " << element << endl;
    }

    // Dequeue operation
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot remove element." << endl;
            return -1;
        }
        int element = queue[front];
        front = (front + 1) % MAX_SIZE;
        size--;
        return element;
    }

    // Peek operation
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        return queue[front];
    }

    // Check if the queue is empty
    bool isEmpty() {
        return size == 0;
    }

    // Check if the queue is full
    bool isFull() {
        return size == MAX_SIZE;
    }

    // Display the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = 0; i < size; i++) {
            cout << queue[(front + i) % MAX_SIZE] << " ";
        }
        cout << endl;
    }
};

int main() {
    QueueArray queue;

    while (true) {
        cout << "\nChoose an operation:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            int element;
            cout << "Enter element to enqueue: ";
            cin >> element;
            queue.enqueue(element);
            break;
        }
        case 2: {
            int dequeuedElement = queue.dequeue();
            if (dequeuedElement != -1) {
                cout << "Dequeued: " << dequeuedElement << endl;
            }
            break;
        }
        case 3: {
            int peekElement = queue.peek();
            if (peekElement != -1) {
                cout << "Front element: " << peekElement << endl;
            }
            break;
        }
        case 4:
            queue.display();
            break;
        case 5:
            cout << "Exiting program. Goodbye!" << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}
