#include <iostream>
using namespace std;

class NodeBi {
public:
    int data;
    NodeBi* next;
    NodeBi* prev;

    NodeBi(int data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class CircularLinkedList {
public:
    NodeBi* head;
    NodeBi* tail;

    CircularLinkedList(NodeBi* node) {
        this->head = node;
        this->tail = node;
        node->next = this->head;
        node->prev = this->head;
    }

    bool is_empty() {
        return this->head == nullptr;
    }

    void add_data(int data, int before_data = -1) {
        if (this->head == nullptr) {
            NodeBi* new_node = new NodeBi(data);
            this->head = new_node;
            this->tail = new_node;
            new_node->next = new_node;
            new_node->prev = new_node;
        } else if (before_data == -1) {
            NodeBi* new_node = new NodeBi(data);
            new_node->next = this->head;
            new_node->prev = this->tail;
            this->tail->next = new_node;
            this->head->prev = new_node;
            this->tail = new_node;
        } else {
            NodeBi* cur = this->head;
            do {
                if (cur->data == before_data) {
                    NodeBi* new_node = new NodeBi(data);
                    new_node->next = cur;
                    new_node->prev = cur->prev;
                    cur->prev->next = new_node;
                    cur->prev = new_node;
                    if (cur == this->head) {
                        this->head = new_node;
                    }
                    return;
                }
                cur = cur->next;
            } while (cur != this->head);
        }
    }

    void remove_data(int data) {
        if (this->is_empty()) {
            cout << "List is empty" << endl;
            return;
        }

        NodeBi* cur = this->head;
        do {
            if (cur->data == data) {
                if (cur == this->head && cur == this->tail) {
                    delete cur;
                    this->head = nullptr;
                    this->tail = nullptr;
                } else if (cur == this->head) {
                    this->head = cur->next;
                    this->head->prev = this->tail;
                    this->tail->next = this->head;
                    delete cur;
                } else if (cur == this->tail) {
                    this->tail = cur->prev;
                    this->tail->next = this->head;
                    this->head->prev = this->tail;
                    delete cur;
                } else {
                    cur->prev->next = cur->next;
                    cur->next->prev = cur->prev;
                    delete cur;
                }
                return;
            }
            cur = cur->next;
        } while (cur != this->head);
    }

    void show_data() {
        if (this->is_empty()) {
            cout << "List is empty!" << endl;
            return;
        }
        NodeBi* cur = this->head;
        do {
            cout << cur->data << " ";
            cur = cur->next;
        } while (cur != this->head);
        cout << endl;
    }
};

int main() {
    CircularLinkedList myList(new NodeBi(1));
    myList.add_data(2);
    myList.add_data(3);
    myList.add_data(4);
    myList.add_data(5);
    myList.show_data(); // 1 2 3 4 5

    myList.add_data(100, 1);
    myList.add_data(200, 2);
    myList.add_data(300, 3);
    myList.add_data(400, 4);
    myList.add_data(500, 5);
    myList.show_data(); // 100 1 200 2 300 3 400 4 500 5

    myList.remove_data(300);
    myList.remove_data(100);
    myList.remove_data(500);
    myList.remove_data(200);
    myList.remove_data(400);
    myList.show_data(); // 1 2 3 4 5

    myList.remove_data(3);
    myList.remove_data(1);
    myList.remove_data(5);
    myList.remove_data(2);
    myList.remove_data(4);
    myList.show_data(); // List is empty!
    
    return 0;
}
