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
        return (front == -1 && rear == -1);
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
            front++;
            rear++;
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
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
        cout << arr[front] << " dequeued from queue" << endl;
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
        cout << "3. Display the queue" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your option: ";
        cin >> option;

        switch (option) {
            case 1:if (q.isFull()) {
                   cout << "Queue is full." << endl;
                   break;
                } else {
                   cout << "Enter value to enqueue: ";
                   cin >> value;
                   q.enqueue(value);
                   break;
                }
            case 2:
                if (q.isEmpty()) {
                   cout << "Queue is empty." << endl;
                   break;
                } else {
                   q.dequeue();
                   break;
                }
            case 3:
            if (q.isEmpty()) {
                   cout << "Queue is empty." << endl;
                   break;
                } else {
                   q.display();
                   break;
                }
            case 4:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid option!" << endl;
        }
    }
}