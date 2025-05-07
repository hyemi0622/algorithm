// Practice1
// 주어진 이진 탐색 트리에서 N 번째로 작은 수 구하기

// 입력 트리: 3, 1, 4, null, 2
// N: 1
// 결과: 1

// 입력 트리: 5, 3, 6, 2, 4, null, null, 1
// N: 3
// 결과: 3


#include <iostream>
#include <vector>
#include <queue>
#include <optional>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    Node* head;

    BinarySearchTree() : head(nullptr) {}

    void addNode(int key) {
        head = addNode(head, key);
    }

    Node* addNode(Node* cur, int key) {
        if (!cur) return new Node(key);
        if (key < cur->key)
            cur->left = addNode(cur->left, key);
        else
            cur->right = addNode(cur->right, key);
        return cur;
    }
};

void solution(vector<optional<int>> data, int n) {
    //여기에 구현. 필요시 다른 함수 더 추가 가능
}

int main() {
    solution({3, 1, 4, nullopt, 2}, 1); // 출력: 1
    solution({5, 3, 6, 2, 4, nullopt, nullopt, 1}, 3); // 출력: 3
    return 0;
}


// Practice2
// 주어진 BST 에서 노드 간의 차이값 중 최소 값을 구하세요.

// 입력 트리: 4, 2, 6, 1, 3
// 출력: 1

// 입력 트리: 5, 1, 48, null, null, 12, 51
// 출력: 3
#include <iostream>
#include <vector>
#include <queue>
#include <optional>
#include <climits>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    Node* head;

    BinarySearchTree() : head(nullptr) {}

    void addNode(int key) {
        head = addNode(head, key);
    }

    Node* addNode(Node* cur, int key) {
        if (!cur) return new Node(key);
        if (key < cur->key)
            cur->left = addNode(cur->left, key);
        else
            cur->right = addNode(cur->right, key);
        return cur;
    }
};


void solution(vector<optional<int>> data) {
     //코드 작성. 함수 더 추가 가능
}

int main() {
    // Test code
    solution({4, 2, 6, 1, 3});                         // 출력: 최소 차이: 1
    solution({5, 1, 48, nullopt, nullopt, 12, 51});    // 출력: 최소 차이: 3
}


