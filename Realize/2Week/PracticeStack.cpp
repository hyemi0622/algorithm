#include <iostream>
using namespace std;

class MyStack {
private:
    int* arr;
    int top;
    int capacity;

public:
    MyStack(int size) {
        arr = new int[size];
        capacity = size;
        top = -1;
    }

    ~MyStack() {
        delete[] arr;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == capacity - 1;
    }

    void push(int data) {
        if (isFull()) {
            cout << "Stack is full!" << endl;
            return;
        }
        arr[++top] = data;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return arr[top];
    }

    void printStack() {
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    // Test code
    MyStack myStack(5);
    cout << myStack.isEmpty() << endl; //1 (true라서)
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    myStack.push(5);
    myStack.push(6); // Stack is full!
    myStack.printStack(); // 1 2 3 4 5

    cout << myStack.peek() << endl; // 5
    myStack.printStack(); // 1 2 3 4 5

    cout << myStack.pop() << endl;  // 5
    cout << myStack.pop() << endl;  // 4
    myStack.printStack(); // 1 2 3

    cout << myStack.pop() << endl;  // 3
    cout << myStack.pop() << endl;  // 2
    cout << myStack.pop() << endl;  // 1
    myStack.printStack(); // (empty output)

    return 0;
}
