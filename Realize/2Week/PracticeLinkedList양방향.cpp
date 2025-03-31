#include <iostream>
using namespace std;

class NodeBi {
public:
    int data;
    NodeBi* next;
    NodeBi* prev;

    NodeBi(int data, NodeBi* next = nullptr, NodeBi* prev = nullptr) {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
};

class DoublyLinkedList {
public:
    NodeBi* head;
    NodeBi* tail;

    DoublyLinkedList(NodeBi* node) {
        this->head = node;
        this->tail = node;
    }

    bool isEmpty() {
        return this->head == nullptr;
    }

    void addData(int data, int beforeData = -1) {
        if (this->head == nullptr) {
            this->head = new NodeBi(data);
            this->tail = this->head;
        }
        else if (beforeData == -1) {
            this->tail->next = new NodeBi(data, nullptr, this->tail);
            this->tail = this->tail->next;
        }
        else {
            NodeBi* cur = this->head;
            while (cur != nullptr) {
                if (cur->data == beforeData) {
                    NodeBi* newNode = new NodeBi(data, cur, cur->prev);
                    if (cur->prev) {
                        cur->prev->next = newNode;
                    }
                    else {
                        this->head = newNode;
                    }
                    cur->prev = newNode;
                    return;
                }
                cur = cur->next;
            }
        }
    }

    void removeData(int data) {
        if (this->isEmpty()) {
            cout << "List is empty" << endl;
            return;
        }

        NodeBi* cur = this->head;
        while (cur != nullptr) {
            if (cur->data == data) {
                if (cur == this->head && cur == this->tail) {
                    this->head = nullptr;
                    this->tail = nullptr;
                }
                else if (cur == this->head) {
                    this->head = cur->next;
                    this->head->prev = nullptr;
                }
                else if (cur == this->tail) {
                    this->tail = this->tail->prev;
                    this->tail->next = nullptr;
                }
                else {
                    cur->prev->next = cur->next;
                    cur->next->prev = cur->prev;
                }
                delete cur;
                return;
            }
            cur = cur->next;
        }
    }

    void showData() {
        if (this->isEmpty()) {
            cout << "List is empty!" << endl;
            return;
        }

        NodeBi* cur = this->head;
        while (cur != nullptr) {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << endl;
    }

    void showDataFromTail() {
        if (this->isEmpty()) {
            cout << "List is empty" << endl;
            return;
        }

        NodeBi* cur = this->tail;
        while (cur != nullptr) {
            cout << cur->data << " ";
            cur = cur->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList myList(new NodeBi(1));
    myList.showData();          // 1

    myList.addData(2);
    myList.addData(3);
    myList.addData(4);
    myList.addData(5);
    myList.showData();          // 1 2 3 4 5
    myList.showDataFromTail();  // 5 4 3 2 1

    myList.addData(100, 1);
    myList.addData(200, 2);
    myList.addData(300, 3);
    myList.addData(400, 4);
    myList.addData(500, 5);
    myList.showData();          // 100 1 200 2 300 3 400 4 500 5
    myList.showDataFromTail();  // 5 500 4 400 3 300 2 200 1 100

    myList.removeData(300);
    myList.removeData(100);
    myList.removeData(500);
    myList.removeData(200);
    myList.removeData(400);
    myList.showData();          // 1 2 3 4 5
    myList.showDataFromTail();  // 5 4 3 2 1

    myList.removeData(3);
    myList.removeData(1);
    myList.removeData(5);
    myList.removeData(2);
    myList.removeData(4);
    myList.showData();          // List is empty!
    myList.showDataFromTail();  // List is empty!

    return 0;
}
