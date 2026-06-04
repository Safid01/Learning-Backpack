#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Linked List class
class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    ~LinkedList() {
        // free all nodes
        Node* cur = head;
        while (cur) {
            Node* nxt = cur->next;
            delete cur;
            cur = nxt;
        }
    }

    // Create new node
    Node* createNode(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;
        return newNode;
    }

    // Insert at beginning
    void insertAtBeginning(int value) {
        Node* newNode = createNode(value);
        newNode->next = head;
        head = newNode;
        cout << value << " inserted at beginning" << endl;
    }

    // Insert at end
    void insertAtEnd(int value) {
        Node* newNode = createNode(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << value << " inserted at end" << endl;
    }

    // Insert after a given node
    void insertAfter(Node* prevNode, int value) {   
        if (prevNode == nullptr) {
            cout << "The given previous node cannot be NULL" << endl;
            return;
        }
        Node* newNode = createNode(value);
        newNode->next = prevNode->next;
        prevNode->next = newNode;
        cout << value << " inserted after " << prevNode->data << endl;
    }

    // Insert after a node with a specific value
    void insertAfterValue(int prevValue, int value) {
        Node* temp = head;
        while (temp != nullptr && temp->data != prevValue) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Node with value " << prevValue << " not found." << endl;
            return;
        }
        insertAfter(temp, value);
    }

    // Delete a node by value
    void deleteNode(int value) {
        Node* temp = head;
        Node* prev = nullptr;

        // Empty list
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        // If head needs to be deleted
        if (head->data == value) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            cout << value << " deleted from list" << endl;
            return;
        }

        // Search for the node to delete
        while (temp != nullptr && temp->data != value) {
            prev = temp;
            temp = temp->next;
        }

        // If not found
        if (temp == nullptr) {
            cout << "Node with value " << value << " not found." << endl;
            return;
        }

        // Unlink and delete
        prev->next = temp->next;
        delete temp;
        cout << value << " deleted from list" << endl;
    }

    // Display the linked list
    void display() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;
        cout << "Linked List: ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

// Main function with examples
int main() {
    LinkedList list;
    int choice, value;

    while (true) {
        cout << "\n--- Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert After a Node\n";
        cout << "4. Delete a Node\n";
        cout << "5. Display List\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        if (!(cin >> choice)) {
            cout << "Invalid input. Exiting." << endl;
            return 1;
        }

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                list.insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                list.insertAtEnd(value);
                break;
            case 3: {
                int prevValue;
                cout << "Enter value after which to insert: ";
                cin >> prevValue;
                cout << "Enter value to insert: ";
                cin >> value;
                list.insertAfterValue(prevValue, value);
                break;
            }
            case 4:
                cout << "Enter value to delete: ";
                cin >> value;
                list.deleteNode(value);
                break;
            case 5:
                list.display();
                break;
            case 6:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
}