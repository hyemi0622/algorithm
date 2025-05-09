//삭제 연산 추가
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

class Node {
public:
    int key;
    int height;
    Node* left;
    Node* right;

    Node(int key) {
        this->key = key;
        this->height = 0;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class AVLTree {
public:
    Node* head = nullptr;

    int height(Node* node) {
        return node ? node->height : -1;
    }

    int getBalance(Node* node) {
        return node ? height(node->left) - height(node->right) : 0;
    }

    Node* rightRotate(Node* node) {
        Node* lnode = node->left;
        node->left = lnode->right;
        lnode->right = node;

        node->height = max(height(node->left), height(node->right)) + 1;
        lnode->height = max(height(lnode->left), height(lnode->right)) + 1;
        return lnode;
    }

    Node* leftRotate(Node* node) {
        Node* rnode = node->right;
        node->right = rnode->left;
        rnode->left = node;

        node->height = max(height(node->left), height(node->right)) + 1;
        rnode->height = max(height(rnode->left), height(rnode->right)) + 1;
        return rnode;
    }

    Node* lrRotate(Node* node) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    Node* rlRotate(Node* node) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    Node* insert(Node* node, int key) {
        if (!node) return new Node(key);

        if (key < node->key)
            node->left = insert(node->left, key);
        else
            node->right = insert(node->right, key);

        node->height = max(height(node->left), height(node->right)) + 1;

        int balance = getBalance(node);

        if (balance > 1 && key < node->left->key) return rightRotate(node);
        if (balance < -1 && key > node->right->key) return leftRotate(node);
        if (balance > 1 && key > node->left->key) return lrRotate(node);
        if (balance < -1 && key < node->right->key) return rlRotate(node);

        return node;
    }

    void insert(int key) {
        head = insert(head, key);
    }

    Node* deleteNode(Node* node, int key) {
        if (!node) return nullptr;

        if (key < node->key)
            node->left = deleteNode(node->left, key);
        else if (key > node->key)
            node->right = deleteNode(node->right, key);
        else {
            if (!node->left)
                return node->right;
            else if (!node->right)
                return node->left;
            else {
                Node* pred = node;
                Node* succ = node->left;
                while (succ->right) {
                    pred = succ;
                    succ = succ->right;
                }
                pred->right = succ->left;
                node->key = succ->key;
            }
        }

        node->height = max(height(node->left), height(node->right)) + 1;
        int balance = getBalance(node);

        if (balance > 1 && getBalance(node->left) >= 0) return rightRotate(node);
        if (balance < -1 && getBalance(node->right) <= 0) return leftRotate(node);
        if (balance > 1 && getBalance(node->left) < 0) return lrRotate(node);
        if (balance < -1 && getBalance(node->right) > 0) return rlRotate(node);

        return node;
    }

    void deleteKey(int key) {
        head = deleteNode(head, key);
    }

    void levelOrder(Node* node) {
        if (!node) return;
        queue<Node*> q;
        q.push(node);
        while (!q.empty()) {
            Node* cur = q.front(); q.pop();
            cout << cur->key << " ";
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
        cout << endl;
    }
};

int main() {
    AVLTree avl;

    avl.insert(30);
    avl.insert(20);
    avl.insert(40);
    avl.insert(10);
    avl.levelOrder(avl.head);

    avl.deleteKey(40); // LL
    avl.levelOrder(avl.head);

    avl.insert(40);
    avl.deleteKey(10); // RR
    avl.levelOrder(avl.head);

    avl.insert(25);
    avl.deleteKey(40); // LR
    avl.levelOrder(avl.head);

    avl.insert(27);
    avl.deleteKey(20); // RL
    avl.levelOrder(avl.head);

    return 0;
}
