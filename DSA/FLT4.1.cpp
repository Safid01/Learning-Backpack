#include <iostream>
using namespace std;

class CircularQueue {
private:
    static const int size = 5;
    int arr[size], front, rear;

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

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue overflowed!!!" << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }
        arr[rear] = value;
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
            front = (front + 1) % size;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue elements: ";
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
    CircularQueue q;
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
            case 1:
                if (q.isFull()) {
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
