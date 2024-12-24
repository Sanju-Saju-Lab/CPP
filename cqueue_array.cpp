#include <iostream>
using namespace std;

class CQueueArray {
    static const int MAX_SIZE = 10;
    int queue[MAX_SIZE];
    int front, rear;

public:
    CQueueArray() {
        front = rear = -1;
    }

    // Enqueue operation
    void enqueue(int value) {
        if ((rear + 1) % MAX_SIZE == front) {
            cout << "Queue is full!" << endl;
        } else {
            if (front == -1) {
                front = 0;
            }
            rear = (rear + 1) % MAX_SIZE;
            queue[rear] = value;
            cout << value << " enqueued." << endl;
        }
    }

    // Dequeue operation
    void dequeue() {
        if (front == -1) {
            cout << "Queue is empty!" << endl;
        } else {
            cout << queue[front] << " dequeued." << endl;
            if (front == rear) {
                front = rear = -1;
            } else {
                front = (front + 1) % MAX_SIZE;
            }
        }
    }

    // Peek operation
    void peek() {
        if (front == -1) {
            cout << "Queue is empty!" << endl;
        } else {
            cout << "Front element is: " << queue[front] << endl;
        }
    }

    // Display the queue
    void display() {
        if (front == -1) {
            cout << "Queue is empty!" << endl;
        } else {
            int i = front;
            cout << "Queue elements: ";
            while (i != rear) {
                cout << queue[i] << " ";
                i = (i + 1) % MAX_SIZE;
            }
            cout << queue[rear] << endl;
        }
    }
};

int main() {
    CQueueArray cqueue;
    int choice, value;

    do {
        cout << "\nChoose an Operation:" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display Queue" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                cqueue.enqueue(value);
                break;
            case 2:
                cqueue.dequeue();
                break;
            case 3:
                cqueue.peek();
                break;
            case 4:
                cqueue.display();
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
