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


// Practice2
// Palindrome 연결 리스트
// 추가 자료구조 없이 연결 리스트만으로 풀어보기 Practice1에서 만든 단일연결리스트 사용(내장 LinkedList말고)
// Palindrome: 앞으로 읽어도 뒤로 읽어도 같은 문자열

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

bool checkPalindrome(LinkedList& list) {
    //여기에 코드 작
    return true;
}

int main() {
    LinkedList linkedList1;
    linkedList1.addData(1);
    linkedList1.addData(3);
    linkedList1.addData(5);
    linkedList1.addData(3);
    linkedList1.addData(1);
    cout << checkPalindrome(linkedList1) << endl; // true

    LinkedList linkedList2;
    linkedList2.addData(3);
    linkedList2.addData(5);
    linkedList2.addData(5);
    linkedList2.addData(3);
    cout << checkPalindrome(linkedList2) << endl; // true

    LinkedList linkedList3;
    linkedList3.addData(1);
    linkedList3.addData(3);
    linkedList3.addData(5);
    linkedList3.addData(1);
    cout << checkPalindrome(linkedList3) << endl; // false

    return 0;
}




// Practice3
// 연결 리스트 부분 뒤집기
// 주어진 연결 리스트에서 시작 위치부터 끝 위치 사이의 노드들을 뒤집으시오.

// 입력 예시)
// 입력 연결 리스트: 1, 2, 3, 4, 5
// 시작 위치: 2
// 끝 위치: 4
// (처음 위치는 1부터라고 가정)
// 결과 연결 리스트: 1, 4, 3, 2, 5
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


    LinkedList reverseList(int left, int right) {
        //여기에 코드 작성
        return *this;
    }
};

int main() {
    LinkedList linkedList;
    linkedList.addData(1);
    linkedList.addData(2);
    linkedList.addData(3);
    linkedList.addData(4);
    linkedList.addData(5);
    linkedList.showData();

    linkedList.reverseList(2, 4);
    linkedList.showData();

    LinkedList linkedList2;
    linkedList2.addData(1);
    linkedList2.addData(2);
    linkedList2.addData(3);
    linkedList2.addData(4);
    linkedList2.addData(5);
    linkedList2.addData(6);
    linkedList2.addData(7);
    linkedList2.showData();

    linkedList2.reverseList(3, 5);
    linkedList2.showData();

    return 0;
}

