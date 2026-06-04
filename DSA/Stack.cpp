#include <iostream>

using namespace std;

class Stack {
private:
    static const int MAX_SIZE = 5;
    int arr[MAX_SIZE];
    int top;

public:
    Stack() {
        top = 0;
    }

    bool isFull() {
        return top == MAX_SIZE;
    }

    bool isEmpty() {
        return top == 0;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack overflowed!!!" << endl;
            return;
        }
        else {
           arr[top++] = value;
           cout << value << " pushed to stack" << endl;
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        else {
            cout << arr[top - 1] << " popped from stack" << endl;
            top--;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack elements: " << endl;
        for (int i = top - 1; i >= 0; i--) {
            cout << arr[i] << endl;
        }
        cout << endl;
    }

    void clear() {
        top = 0;
        cout << "Stack cleared" << endl;
    }

    void topElement() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Top element: " << arr[top - 1] << endl;
    }
};

int main() {
    Stack stack;
    int choice, value;

    while (true) {
        cout << "\nWhat you want to do?" << endl;
        cout << "1. Push element in the stack" << endl;
        cout << "2. Pop element from the stack" << endl;
        cout << "3. Display the stack" << endl;
        cout << "4. Clear the stack" << endl; 
        cout << "5. View top element" << endl;  
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (stack.isFull()) {
                   cout << "Stack overflowed!!!" << endl;
                   break;
                } else {
                   cout << "Enter value to push: ";
                   cin >> value;
                   stack.push(value);
                   break; 
                }
            case 2:
                if (stack.isEmpty()) {
                   cout << "Stack is empty" << endl;
                   break;
                } else {
                   stack.pop();
                   break; 
                }
            case 3:
                if (stack.isEmpty()) {
                   cout << "Stack is empty" << endl;
                   break;
                }
                stack.display();
                break;
            case 4:
                stack.clear();
                break;
            case 5:
                stack.topElement();
                break;
            case 6:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}