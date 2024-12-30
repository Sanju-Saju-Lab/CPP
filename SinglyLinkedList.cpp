#include <iostream>
using namespace std;

// Node class represents an individual element in the linked list
class Node {
public:
    int data;    // Data stored in the node
    Node* next;  // Pointer to the next node in the list

    // Constructor to create a new node with given data
    Node(int data) {
        this->data = data;  // Initialize data
        this->next = nullptr;  // Initialize next pointer to null (end of list)
    }
};

// SinglyLinkedList class manages the entire list of nodes
class SinglyLinkedList {
public:
    Node* head;  // Pointer to the first node in the list

    // Constructor to initialize the linked list with an empty list
    SinglyLinkedList() {
        head = nullptr;  // Initially, the list is empty
    }

    // Insert a new node at the beginning of the list
    void insertAtFirst(int data) {
        Node* newNode = new Node(data);  // Create a new node
        newNode->next = head;  // Point the new node to the current head
        head = newNode;  // Update the head to the new node
    }

    // Insert a new node at the end of the list
    void insertAtLast(int data) {
        Node* newNode = new Node(data);  // Create a new node
        if (head == nullptr) {  // If the list is empty, make the new node the head
            head = newNode;
        } else {
            Node* current = head;
            while (current->next) {  // Traverse to the last node
                current = current->next;
            }
            current->next = newNode;  // Insert the new node at the end
        }
    }

    // Insert a new node at a specific position in the list
    void insertAtPosition(int data, int pos) {
        if (pos < 0) {  // Position validation
            cout << "Position cannot be negative." << endl;
            return;
        }

        if (pos == 0) {  // If position is 0, insert at the beginning
            insertAtFirst(data);
            return;
        }

        Node* newNode = new Node(data);  // Create a new node
        Node* current = head;
        for (int i = 0; i < pos - 1; i++) {  // Traverse to the node before the specified position
            if (current == nullptr) {  // If the position is out of bounds
                cout << "Position exceeds the list" << endl;
                return;
            }
            current = current->next;
        }

        if (current == nullptr) {  // If the position is still invalid
            cout << "Position exceeds the list" << endl;
            return;
        }

        newNode->next = current->next;  // Point the new node's next to the current node's next
        current->next = newNode;  // Link the current node to the new node
    }

    // Remove the first node from the list
    void removeAtFirst() {
        if (head == nullptr) {  // If the list is empty, nothing to remove
            cout << "List is empty..." << endl;
            return;
        }
        cout << head->data << " removed from the list" << endl;
        head = head->next;  // Update the head to the second node
    }

    // Remove the last node from the list
    void removeAtLast() {
        if (head == nullptr) {  // If the list is empty, nothing to remove
            cout << "List is empty..." << endl;
            return;
        }
        if (head->next == nullptr) {  // If there's only one node, remove it
            removeAtFirst();
            return;
        }

        Node* current = head;
        while (current->next && current->next->next) {  // Traverse to the second-to-last node
            current = current->next;
        }
        cout << current->next->data << " removed from the list" << endl;
        current->next = nullptr;  // Remove the last node by setting the next pointer to null
    }

    // Remove a node at a specific position in the list
    void removeAtPosition(int pos) {
        if (pos < 0) {  // Position validation
            cout << "Position cannot be negative." << endl;
            return;
        }

        if (pos == 0) {  // If position is 0, remove the first node
            removeAtFirst();
            return;
        }

        Node* current = head;
        for (int i = 0; i < pos - 1; i++) {  // Traverse to the node before the specified position
            if (current == nullptr) {  // If the position is out of bounds
                cout << "Position exceeds list" << endl;
                return;
            }
            current = current->next;
        }

        if (current == nullptr || current->next == nullptr) {  // If position is invalid
            cout << "Position exceeds list" << endl;
            return;
        }

        cout << current->next->data << " removed from the list" << endl;
        current->next = current->next->next;  // Remove the node at the specified position
    }

    // Display the entire list
    void display() {
        Node* current = head;
        while (current != nullptr) {  // Traverse the list and print each node's data
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "null" << endl;  // Indicate the end of the list
    }
};

int main() {
    SinglyLinkedList list;  // Create an empty linked list
    int choice = 1, data, pos;

    // Initial insertion of elements into the list
    cout << "Enter elements to the list: " << endl;
    while (choice == 1) {
        cout << "Enter data: ";
        cin >> data;
        list.insertAtLast(data);  // Insert the data at the end of the list
        cout << "Do you want to insert more elements to the list 0(No) or 1(Yes): ";
        cin >> choice;
    }

    cout << "List after initial insertion: " << endl;
    list.display();  // Display the list after the initial insertion

    // Menu for linked list operations
    while (true) {
        cout << "\nLinked list operations: " << endl;
        cout << "1. Insert at the beginning." << endl;
        cout << "2. Insert at the end." << endl;
        cout << "3. Insert at a specified position." << endl;
        cout << "4. Remove from the beginning." << endl;
        cout << "5. Remove from the end." << endl;
        cout << "6. Remove from a specified position." << endl;
        cout << "7. Traverse." << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the data: ";
                cin >> data;
                list.insertAtFirst(data);  // Insert at the beginning
                break;
            case 2:
                cout << "Enter the data: ";
                cin >> data;
                list.insertAtLast(data);  // Insert at the end
                break;
            case 3:
                cout << "Enter the data: ";
                cin >> data;
                cout << "Enter the position: ";
                cin >> pos;
                list.insertAtPosition(data, pos);  // Insert at a specified position
                break;
            case 4:
                list.removeAtFirst();  // Remove from the beginning
                break;
            case 5:
                list.removeAtLast();  // Remove from the end
                break;
            case 6:
                cout << "Enter the position: ";
                cin >> pos;
                list.removeAtPosition(pos);  // Remove from a specified position
                break;
            case 7:
                list.display();  // Traverse and display the list
                break;
            case 8:
                exit(0);  // Exit the program
        }
    }

    return 0;
}
