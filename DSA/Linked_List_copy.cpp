#include <iostream>
using namespace std;

// Define the Node structure
struct Node {
    int data;
    Node* next;
};

// Function to insert a node at the end (based on Slide 12)
void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }
    else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to delete a node with a specific value (based on Slide 13)
void deleteNode(Node*& head, int valueToDelete) {
    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL && temp->data != valueToDelete) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Value not found" << endl;
        return;
    }
    else if (prev == NULL) {
        head = temp->next; // Deleting first node
        delete temp;
    }
    else {
        prev->next = temp->next;
        delete temp;
    }
}

// Function to traverse and print the linked list (based on Slide 10)
void traverseLinkedList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to search for an element
void searchElement(Node* head, int valueToFind) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == valueToFind) {
            cout << "Value " << valueToFind << " found in the list." << endl;
            return;
        } else {
            temp = temp->next;
        }
    }
    cout << "Value " << valueToFind << " not found in the list." << endl;
}

// Main function to test the implementation
int main() {
    // Create the initial linked list
    Node* node1 = new Node;
    node1->data = 10;
    node1->next = NULL;

    Node* node2 = new Node;
    node2->data = 20;
    node2->next = NULL;
    node1->next = node2;

    Node* node3 = new Node;
    node3->data = 30;
    node3->next = NULL;
    node2->next = node3;
    Node* head = node1;
    cout << "Initial Linked List: ";
    traverseLinkedList(head); // Output: 10 20 30

    // Insert new nodes at the end
    insertAtEnd(head, 40);
    insertAtEnd(head, 50);
    cout << "After inserting 40 and 50: ";
    traverseLinkedList(head); // Output: 10 20 30 40 50

    // Search for a value
    searchElement(head, 30); // Output: Value 30 found in the list.
    searchElement(head, 60); // Output: Value 60 not found in the list.

    // Delete a node with value 20
    deleteNode(head, 20);
    cout << "After deleting 20: ";
    traverseLinkedList(head); // Output: 10 30 40 50

    // Clean up memory (delete all nodes)
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}