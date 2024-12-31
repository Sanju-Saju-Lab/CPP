#include <iostream>
using namespace std;

// Node class represents a node in the doubly linked list.
class Node {
public:
    int data;       // Data held by the node
    Node* next;     // Pointer to the next node in the list
    Node* prev;     // Pointer to the previous node in the list

    // Constructor to create a new node
    Node(int data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

// DLL class represents the doubly linked list itself.
class DLL {
private:
    Node* head;     // Pointer to the first node of the list
    Node* tail;     // Pointer to the last node of the list

public:
    // Constructor to initialize the list as empty
    DLL() {
        head = nullptr;
        tail = nullptr;
    }

    // Method to append a new node at the end of the list
    void append(int data) {
        Node* newNode = new Node(data);  // Create a new node
        if (!head) {  // If the list is empty, set the new node as both head and tail
            head = tail = newNode;
            return;
        }
        // If the list is not empty, link the new node to the tail and update the tail pointer
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;  // Update the tail to the new node
    }

    // Method to prepend a new node at the beginning of the list
    void prepend(int data) {
        Node* newNode = new Node(data);  // Create a new node
        if (!head) {  // If the list is empty, set the new node as both head and tail
            head = tail = newNode;
            return;
        }
        // If the list is not empty, link the new node to the head and update the head pointer
        head->prev = newNode;
        newNode->next = head;
        head = newNode;  // Update the head to the new node
    }

    // Method to insert a node at a specific position in the list
    void insertAtPosition(int pos, int data) {
        Node* newNode = new Node(data);  // Create a new node
        if (pos == 1) {  // If inserting at the beginning, use prepend method
            prepend(data);
            return;
        }
        Node* current = head;
        int currentPosition = 1;
        while (current && currentPosition < pos - 1) {  // Traverse to the node before the specified position
            current = current->next;
            currentPosition++;
        }
        if (!current) {  // If position is invalid (greater than the size of the list)
            cout << "Invalid position." << endl;
        } else if (current == tail) {  // If inserting at the end, use append method
            append(data);
        } else {  // Insert the new node between two existing nodes
            newNode->next = current->next;
            current->next->prev = newNode;
            current->next = newNode;
            newNode->prev = current;
        }
    }

    // Method to delete the first node
    void deleteFirst() {
        if (!head) {  // If the list is empty
            cout << "List is empty." << endl;
            return;
        }
        if (head == tail) {  // If the list has only one node
            delete head;
            head = tail = nullptr;
        } else {  // If there are multiple nodes, update the head
            Node* temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
        }
    }

    // Method to delete the last node
    void deleteLast() {
        if (!tail) {  // If the list is empty
            cout << "List is empty." << endl;
            return;
        }
        if (head == tail) {  // If the list has only one node
            delete tail;
            head = tail = nullptr;
        } else {  // If there are multiple nodes, update the tail
            Node* temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        }
    }

    // Method to delete a node at a specific position
    void deleteNode(int pos) {
        if (!head) {  // If the list is empty
            cout << "List is empty." << endl;
            return;
        }
        if (pos == 1) {  // If deleting the first node
            deleteFirst();
            return;
        }
        Node* current = head;
        int currentPosition = 1;
        while (current && currentPosition < pos) {  // Traverse to the specified position
            current = current->next;
            currentPosition++;
        }
        if (!current) {  // If position is invalid
            cout << "Invalid position." << endl;
        } else if (current == tail) {  // If deleting the last node
            deleteLast();
        } else {  // Update the pointers to exclude the current node
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
        }
    }

    // Method to traverse the list in the forward direction and print the nodes
    void traverseForward() {
        if (!head) {  // If the list is empty
            cout << "List is empty." << endl;
            return;
        }
        Node* current = head;
        while (current) {  // Traverse the list from head to tail
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Method to traverse the list in the backward direction and print the nodes
    void traverseBackward() {
        if (!tail) {  // If the list is empty
            cout << "List is empty." << endl;
            return;
        }
        Node* current = tail;
        while (current) {  // Traverse the list from tail to head
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }
};

// Main function to interact with the user
int main() {
    DLL dll;  // Create a new doubly linked list
    int choice = 1, data, position;
    while (choice == 1) {
        cout << "Enter the data: ";
        cin >> data;  // Get data from user
        dll.append(data);  // Append data to the list
        cout << "Do you want to insert more elements? 0(No) or 1(Yes): ";
        cin >> choice;
    }

    dll.traverseForward();  // Print the list after initial entries

    while (true) {
        // Display menu to the user
        cout << "\nDoubly Linked List Menu" << endl;
        cout << "1. Insert at the beginning." << endl;
        cout << "2. Insert at the end." << endl;
        cout << "3. Insert at a specified position." << endl;
        cout << "4. Remove from the beginning." << endl;
        cout << "5. Remove from the end." << endl;
        cout << "6. Remove from a specified position." << endl;
        cout << "7. Traverse Forward" << endl;
        cout << "8. Traverse Backward" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        int menuChoice;
        cin >> menuChoice;

        // Handle user input for various operations
        switch(menuChoice) {
            case 1:
                cout << "Enter the data: ";
                cin >> data;
                dll.prepend(data);
                dll.traverseForward();
                break;
            case 2:
                cout << "Enter the data: ";
                cin >> data;
                dll.append(data);
                dll.traverseForward();
                break;
            case 3:
                cout << "Enter the data: ";
                cin >> data;
                cout << "Enter the position: ";
                cin >> position;
                dll.insertAtPosition(position, data);
                dll.traverseForward();
                break;
            case 4:
                dll.deleteFirst();
                dll.traverseForward();
                break;
            case 5:
                dll.deleteLast();
                dll.traverseForward();
                break;
            case 6:
                cout << "Enter the position: ";
                cin >> position;
                dll.deleteNode(position);
                dll.traverseForward();
                break;
            case 7:
                cout << "Traverse Forward:" << endl;
                dll.traverseForward();
                break;
            case 8:
                cout << "Traverse Backward:" << endl;
                dll.traverseBackward();
                break;
            case 9:
                cout << "Exited" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
