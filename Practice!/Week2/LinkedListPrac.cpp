// Practice1
// 단방향 연결 리스트에서 중복 데이터를 찾아 삭제하세요.

// 입출력 예시)
// 입력 연결 리스트: 1, 3, 3, 1, 4, 2, 4, 2
// 결과 연결 리스트: 1, 3, 4, 2

#include <iostream>
#include <unordered_set>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        this->head = nullptr;
    }

    void addData(int data) {
        if (this->head == nullptr) {
            this->head = new Node(data);
        } else {
            Node* cur = this->head;
            while (cur->next != nullptr) {
                cur = cur->next;
            }
            cur->next = new Node(data);
        }
    }

    bool findData(int data) {
        Node* cur = this->head;
        while (cur != nullptr) {
            if (cur->data == data) {
                return true;
            }
            cur = cur->next;
        }
        return false;
    }

    void showData() {
        Node* cur = this->head;
        while (cur != nullptr) {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << endl;
    }
};

LinkedList removeDup(LinkedList listBefore) {
    //여기에 코드 작성
    return null;
}

int main() {
    LinkedList linkedList;
    linkedList.addData(1);
    linkedList.addData(3);
    linkedList.addData(3);
    linkedList.addData(1);
    linkedList.addData(4);
    linkedList.addData(2);
    linkedList.addData(4);
    linkedList.addData(2);

    cout << "Before removing duplicates: ";
    linkedList.showData();

    LinkedList result = removeDup(linkedList);

    cout << "After removing duplicates: ";
    result.showData();

    return 0;
}


