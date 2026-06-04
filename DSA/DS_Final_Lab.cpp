#include <iostream>
#include <string>

using namespace std;

class CircularQueue {
private:
    static const int size = 10;
    string arr[size];
    int front, rear;

public:
    CircularQueue() {
        front = rear = -1;
    }

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return ((rear + 1) % size == front);
    }

    void enqueue(string name) {
        if (isFull()) {
            cout << "Queue is full. Cannot add customer " << name << "." << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }
        arr[rear] = name;
        cout << "Customer " << name << " added to the queue." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. No customer to serve." << endl;
            return;
        }
        cout << "Customer " << arr[front] << " has been served and left the counter." << endl;
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
    }

    void frontElement() {
        if (isEmpty()) {
            cout << "Queue is empty. No customer at the front." << endl;
            return;
        }
        cout << "Front customer: " << arr[front] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty. No customers in line." << endl;
            return;
        }
        cout << "Customers in queue: ";
        int i = front;
        while (true) {
        cout << arr[i] << " ";
        if (i == rear) break;
        i = (i + 1) % size;
    }
        cout << endl;
    }
};

int main() {
    CircularQueue customerQ;
    int option;
    string name;

    while (true) {
        cout << "\nPayment Counter Menu:\n";
        cout << "1. Add a new customer to the queue\n";
        cout << "2. Serve the next customer (payment done)\n";
        cout << "3. Display the front customer\n";
        cout << "4. Display all customers in queue\n";
        cout << "5. Exit\n";
        cout << "Enter your option: ";
        cin >> option;

        switch (option) {
            case 1:
                cout << "Enter customer name: ";
                cin >> name;
                customerQ.enqueue(name);
                break;
            case 2:
                customerQ.dequeue();
                break;
            case 3:
                customerQ.frontElement();
                break;
            case 4:
                customerQ.display();
                break;
            case 5:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid option! Please try again." << endl;
        }
    }
}