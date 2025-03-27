#include <iostream>
using namespace std;

// 노드
class Node {
public:
    int data;
    Node* next;

    Node() : data(0), next(nullptr) {}
    Node(int data, Node* next = nullptr) : data(data), next(next) {}
};

// 연결 리스트
class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}
    LinkedList(Node* node) : head(node) {}

    // 연결 리스트 비어있는지 확인
    bool isEmpty() {
        return head == nullptr;
    }

    // 연결 리스트의 맨 뒤에 데이터 추가
    void addData(int data) {
        if (head == nullptr) {
            head = new Node(data);
        } else {
            Node* cur = head;
            while (cur->next != nullptr) {
                cur = cur->next;
            }
            cur->next = new Node(data);
        }
    }

    // 연결 리스트의 맨 뒤의 데이터 삭제
    void removeData() {
        if (isEmpty()) {
            cout << "List is empty" << endl;
            return;
        }

        Node* cur = head;
        Node* prev = nullptr;

        // 마지막 노드까지 이동
        while (cur->next != nullptr) {
            prev = cur;
            cur = cur->next;
        }

        if (cur == head) {
            head = nullptr; // 리스트에 하나만 있을 경우
        } else {
            prev->next = nullptr; // 마지막 노드를 제거
        }

        delete cur; // 메모리 해제
    }

    // 연결 리스트에서 데이터 찾기
    void findData(int data) {
        if (isEmpty()) {
            cout << "List is empty" << endl;
            return;
        }

        Node* cur = head;
        while (cur != nullptr) {
            if (cur->data == data) {
                cout << "Data exist!" << endl;
                return;
            }
            cur = cur->next;
        }
        cout << "Data not found!" << endl;
    }

    // 연결 리스트의 모든 데이터 출력
    void showData() {
        if (isEmpty()) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* cur = head;
        while (cur != nullptr) {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << endl;
    }
};

int main() {
    // 테스트 코드
    LinkedList myList(new Node(1));
    myList.showData();  // 1

    myList.addData(2);
    myList.addData(3);
    myList.addData(4);
    myList.addData(5);
    myList.showData();  // 1 2 3 4 5

    myList.findData(3);  // Data exist!
    myList.findData(100); // Data not found!

    myList.removeData();
    myList.removeData();
    myList.removeData();
    myList.showData();  // 1 2

    myList.removeData();
    myList.removeData();
    myList.removeData(); // List is empty

    return 0;
}
