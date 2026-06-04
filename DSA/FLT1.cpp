#include <iostream>
using namespace std;

class Stack {
private:
    static const int size = 5;
    int arr[size];
    int top;

public:
    Stack() {
        top = 0;
    }

    bool isFull() {
        return top == size;
    }

    bool isEmpty() {
        return top == 0;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack overflowed." << endl;
            return;
        }
        else {
           arr[top++] = value;
           cout << value << " pushed to stack" << endl;
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        else {
            cout << arr[top - 1] << " popped from stack." << endl;
            top--;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack elements: " << endl;
        for (int i = top - 1; i >= 0; i--) {
            cout << arr[i] << endl;
        }
        cout << endl;
    }
};

int main() {
    Stack stack;
    int option, value;

    while (true) {
        cout << "\nWhat you want to do?" << endl;
        cout << "1. Push element in the stack" << endl;
        cout << "2. Pop element from the stack" << endl;
        cout << "3. Display the stack" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your option: ";
        cin >> option;

        switch (option) {
            case 1:
                if (stack.isFull()) {
                   cout << "Stack overflowed." << endl;
                   break;
                } else {
                   cout << "Enter value to push: ";
                   cin >> value;
                   stack.push(value);
                   break; 
                }
            case 2:
                if (stack.isEmpty()) {
                   cout << "Stack is empty." << endl;
                   break;
                } else {
                   stack.pop();
                   break; 
                }
            case 3:
                if (stack.isEmpty()) {
                   cout << "Stack is empty." << endl;
                   break;
                } else {
                   stack.display();
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