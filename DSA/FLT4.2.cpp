#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertAtEnd(int value) {
    Node* newNode = new Node{value, NULL};
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertAtBeginning(int value) {
    Node* newNode = new Node{value, head};
    head = newNode;
}

void insertAfter(int key, int value) {
    Node* temp = head;
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Node with value " << key << " not found.\n";
    } else {
        Node* newNode = new Node{value, temp->next};
        temp->next = newNode;
    }
}

void display() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    cout << "Linked List: ";
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
}

void searchItem(int key) {
    Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == key) {
            cout << "Item " << key << " found at position " << pos << ".\n";
            return;
        } else { temp = temp->next;
            pos++;
        }
    }
    cout << "Item " << key << " not found in list.\n";
}

void deleteAtBeginning() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    head = temp->next;
    delete temp;
}

void deleteAtEnd() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while (temp->next->next != NULL) temp = temp->next;
    delete temp->next;
    temp->next = NULL;
}

void deleteByValue(int key) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    if (head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL && temp->next->data != key) temp = temp->next;
    if (temp->next == NULL) {
        cout << "Value " << key << " not found.\n";
    } else {
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }
}

int main() {
    int choice, value, key;

    while (true) {
        cout << "1. Insert at End\n";
        cout << "2. Display List\n";
        cout << "3. Search Item\n";
        cout << "4. Insert at Beginning\n";
        cout << "5. Insert After a Node\n";
        cout << "6. Delete at Beginning\n";
        cout << "7. Delete at End\n";
        cout << "8. Delete by Value (Middle)\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            insertAtEnd(value);
            break;
        case 2:
            display();
            break;
        case 3:
            cout << "Enter value to search: ";
            cin >> key;
            searchItem(key);
            break;
        case 4:
            cout << "Enter value: ";
            cin >> value;
            insertAtBeginning(value);
            break;
        case 5:
            cout << "Enter node value after which to insert: ";
            cin >> key;
            cout << "Enter value: ";
            cin >> value;
            insertAfter(key, value);
            break;
        case 6:
            deleteAtBeginning();
            break;
        case 7:
            deleteAtEnd();
            break;
        case 8:
            cout << "Enter value to delete: ";
            cin >> key;
            deleteByValue(key);
            break;
        case 9:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice.\n";
        }
    }
}
