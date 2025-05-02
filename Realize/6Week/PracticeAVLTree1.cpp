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
    Node* head;

    AVLTree() {
        head = nullptr;
    }

    int height(Node* node) {
        if (node == nullptr) {
            return -1;
        }
        return node->height;
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

    int getBalance(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        return height(node->left) - height(node->right);
    }

    void insert(int key) {
        head = insert(head, key);
    }

    Node* insert(Node* node, int key) {
        if (node == nullptr) {
            return new Node(key);
        }
        if (key < node->key) {
            node->left = insert(node->left, key);
        } else {
            node->right = insert(node->right, key);
        }

        node->height = max(height(node->left), height(node->right)) + 1;
        int balance = getBalance(node);

        // LL
        if (balance > 1 && key < node->left->key) {
            return rightRotate(node);
        }

        // RR
        if (balance < -1 && key > node->right->key) {
            return leftRotate(node);
        }

        // LR
        if (balance > 1 && key > node->left->key) {
            return lrRotate(node);
        }

        // RL
        if (balance < -1 && key < node->right->key) {
            return rlRotate(node);
        }

        return node;
    }

    void levelOrder(Node* node) {
        if (node == nullptr) return;

        queue<Node*> q;
        q.push(node);
        while (!q.empty()) {
            Node* cur = q.front();
            q.pop();

            cout << cur->key << " ";
            if (cur->left != nullptr) {
                q.push(cur->left);
            }
            if (cur->right != nullptr) {
                q.push(cur->right);
            }
        }
        cout << endl;
    }
};

int main() {
    AVLTree avl;

    avl.insert(30);
    avl.insert(20);
    avl.insert(10);     // LL
    avl.levelOrder(avl.head);

    avl.insert(40);
    avl.insert(50);     // RR
    avl.levelOrder(avl.head);

    avl.insert(5);
    avl.insert(7);      // LR
    avl.levelOrder(avl.head);

    avl.insert(60);
    avl.insert(55);     // RL
    avl.levelOrder(avl.head);

    return 0;
}
