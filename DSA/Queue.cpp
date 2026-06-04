#include <iostream>
using namespace std;

class Queue {
private:
    static const int size = 5;
    int arr[size], front, rear;

public:
    Queue() {
        front = rear = -1;
    }

    bool isEmpty() {
        return (front = rear == -1);
    }

    bool isFull() {
        return (rear == size - 1);
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue overflowed!!!" << endl;
            return;
        }
        else if (isEmpty()) {
            front = rear = 0;
            arr[rear] = value;
        } else {
            arr[++rear] = value;
        }
        cout << value << " enqueued to queue" << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << arr[front] << " dequeued from queue" << endl;
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
    }

    void frontElement() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Front element: " << arr[front] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    int option, value;

    while (true) {
        cout << "\nWhat you want to do?" << endl;
        cout << "1. Enqueue element in the queue" << endl;
        cout << "2. Dequeue element in the queue" << endl;
        cout << "3. Display the front element" << endl;
        cout << "4. Display the queue" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your option: ";
        cin >> option;

        switch (option) {
            case 1:
                if (q.isFull()) {
                    cout << "Queue is full." << endl;
                } else {
                    cout << "Enter value to enqueue: ";
                    cin >> value;
                    q.enqueue(value);
                }
                break;
            case 2:
                if (q.isEmpty()) {
                    cout << "Queue is empty." << endl;
                } else {
                    q.dequeue();
                }
                break;
            case 3:
                if (q.isEmpty()) {
                    cout << "Queue is empty." << endl;
                } else {
                    q.frontElement();
                }
                break;
            case 4:
                if (q.isEmpty()) {
                    cout << "Queue is empty." << endl;
                } else {
                    q.display();
                }
                break;
            case 5:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid option!" << endl;
        }
    }
}