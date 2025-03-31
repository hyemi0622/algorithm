#include <iostream>
using namespace std;

class MyQueue2 {
private:
    int* arr;
    int front;
    int rear;
    int size;

public:
    MyQueue2(int size) {
        this->size = size + 1;
        arr = new int[this->size];
        front = 0;
        rear = 0;
    }

    ~MyQueue2() {
        delete[] arr;
    }

    bool isEmpty() {
        return rear == front;
    }

    bool isFull() {
        return (rear + 1) % size == front;
    }

    void enqueue(int data) {
        if (isFull()) {
            cout << "Queue is full!" << endl;
            return;
        }
        rear = (rear + 1) % size;
        arr[rear] = data;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        front = (front + 1) % size;
        return arr[front];
    }

    void printQueue() {
        int start = (front + 1) % size;
        int end = (rear + 1) % size;
        for (int i = start; i != end; i = (i + 1) % size) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MyQueue2 myQueue(5);
    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);
    myQueue.enqueue(4);
    myQueue.enqueue(5);
    myQueue.enqueue(6); // Queue is full!

    myQueue.printQueue(); // 1 2 3 4 5

    cout << myQueue.dequeue() << endl; // 1
    myQueue.printQueue(); // 2 3 4 5

    cout << myQueue.dequeue() << endl; // 2
    myQueue.printQueue(); // 3 4 5

    myQueue.enqueue(6);
    myQueue.enqueue(7);
    myQueue.printQueue(); // 3 4 5 6 7

    cout << myQueue.dequeue() << endl; // 3
    cout << myQueue.dequeue() << endl; // 4
    cout << myQueue.dequeue() << endl; // 5
    myQueue.printQueue(); // 6 7
    cout << myQueue.dequeue() << endl; // 6
    cout << myQueue.dequeue() << endl; // 7
    myQueue.dequeue(); // Queue is empty!

    return 0;
}
