// 앞의 BST 삽입, 삭제 코드를 재귀 형태로 구현
#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    Node* head;

    BinarySearchTree(int key) {
        head = new Node(key);
    }

    Node* addNodeRecursive(Node* cur, int key) {
        if (!cur) return new Node(key);
        if (key < cur->key) {
            cur->left = addNodeRecursive(cur->left, key);
        } else {
            cur->right = addNodeRecursive(cur->right, key);
        }
        return cur;
    }

    Node* removeNodeRecursive(Node* cur, int key) {
        if (!cur) return nullptr;

        if (key < cur->key) {
            cur->left = removeNodeRecursive(cur->left, key);
        } else if (key > cur->key) {
            cur->right = removeNodeRecursive(cur->right, key);
        } else {
            if (!cur->left) return cur->right;
            if (!cur->right) return cur->left;

            Node* predecessor = cur;
            Node* successor = cur->left;
            while (successor->right) {
                predecessor = successor;
                successor = successor->right;
            }

            cur->key = successor->key;
            if (predecessor == cur) {
                predecessor->left = successor->left;
            } else {
                predecessor->right = successor->left;
            }
        }
        return cur;
    }

    void levelOrder(Node* node) {
        if (!node) return;
        queue<Node*> q;
        q.push(node);
        while (!q.empty()) {
            Node* cur = q.front();
            q.pop();
            cout << cur->key << " ";
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
        cout << endl;
    }
};

int main() {
    BinarySearchTree bst(20);
    bst.head = bst.addNodeRecursive(bst.head, 10);
    bst.head = bst.addNodeRecursive(bst.head, 30);
    bst.head = bst.addNodeRecursive(bst.head, 1);
    bst.head = bst.addNodeRecursive(bst.head, 15);
    bst.head = bst.addNodeRecursive(bst.head, 25);
    bst.head = bst.addNodeRecursive(bst.head, 13);
    bst.head = bst.addNodeRecursive(bst.head, 35);
    bst.head = bst.addNodeRecursive(bst.head, 27);
    bst.head = bst.addNodeRecursive(bst.head, 40);
    bst.levelOrder(bst.head);

    bst.head = bst.removeNodeRecursive(bst.head, 40);
    bst.levelOrder(bst.head);
    bst.head = bst.removeNodeRecursive(bst.head, 25);
    bst.levelOrder(bst.head);
    bst.head = bst.removeNodeRecursive(bst.head, 20);
    bst.levelOrder(bst.head);

    return 0;
}
