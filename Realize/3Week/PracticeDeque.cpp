#include <iostream>
using namespace std;

class MyDeque2 {
    int* arr;
    int front;
    int rear;
    int size;

public:
    MyDeque2(int size) {
        this->size = size + 1;
        this->arr = new int[this->size];
        this->front = 0;
        this->rear = 0;
    }

    ~MyDeque2() {
        delete[] arr;
    }

    bool isEmpty() {
        return this->rear == this->front;
    }

    bool isFull() {
        return (this->rear + 1) % this->size == this->front;
    }

    void addFirst(int data) {
        if (this->isFull()) {
            cout << "Deque is full!" << endl;
            return;
        }
        this->front = (this->front - 1 + this->size) % this->size;
        this->arr[this->front] = data;
    }

    void addLast(int data) {
        if (this->isFull()) {
            cout << "Deque is full!" << endl;
            return;
        }
        this->arr[this->rear] = data;
        this->rear = (this->rear + 1) % this->size;
    }

    int removeFirst() {
        if (this->isEmpty()) {
            cout << "Deque is empty!" << endl;
            return -1;
        }
        int data = this->arr[this->front];
        this->front = (this->front + 1) % this->size;
        return data;
    }

    int removeLast() {
        if (this->isEmpty()) {
            cout << "Deque is empty!" << endl;
            return -1;
        }
        this->rear = (this->rear - 1 + this->size) % this->size;
        return this->arr[this->rear];
    }

    void printDeque() {
        if (this->isEmpty()) {
            cout << "Deque is empty!" << endl;
            return;
        }
        int i = this->front;
        while (i != this->rear) {
            cout << this->arr[i] << " ";
            i = (i + 1) % this->size;
        }
        cout << endl;
    }
};

int main() {
    MyDeque2 myDeque(5);

    myDeque.addFirst(1);
    myDeque.addFirst(2);
    myDeque.addFirst(3);
    myDeque.printDeque();  // 3 2 1

    myDeque.addLast(10);
    myDeque.addLast(20);
    myDeque.addLast(30);  // Deque is full!
    myDeque.printDeque();  // 3 2 1 10 20

    cout << myDeque.removeFirst() << endl; // 3
    myDeque.printDeque();  // 2 1 10 20

    cout << myDeque.removeLast() << endl; // 20
    myDeque.printDeque();  // 2 1 10

    cout << myDeque.removeLast() << endl; // 10
    cout << myDeque.removeLast() << endl; // 1
    cout << myDeque.removeLast() << endl; // 2
    cout << myDeque.removeLast() << endl; // Deque is empty!

    return 0;
}
