#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node(int key) {
        this->key = key;
        left = right = nullptr;
    }
};

class BinarySearchTree {
public:
    Node* head;

    BinarySearchTree(int key) {
        head = new Node(key);
    }

    void addNode(int key) {
        if (!head) {
            head = new Node(key);
            return;
        }
        Node* cur = head;
        while (true) {
            Node* pre = cur;
            if (key < cur->key) {
                cur = cur->left;
                if (!cur) {
                    pre->left = new Node(key);
                    break;
                }
            } else {
                cur = cur->right;
                if (!cur) {
                    pre->right = new Node(key);
                    break;
                }
            }
        }
    }

    void removeNode(int key) {
        Node* parent = nullptr;
        Node* cur = head;

        // 찾기
        while (cur && cur->key != key) {
            parent = cur;
            if (key < cur->key)
                cur = cur->left;
            else
                cur = cur->right;
        }

        if (!cur) {
            cout << "Key not found" << endl;
            return;
        }

        // 자식이 없는 경우
        if (!cur->left && !cur->right) {
            if (!parent) {
                head = nullptr;
            } else {
                if (parent->left == cur) parent->left = nullptr;
                else parent->right = nullptr;
            }
            delete cur;
        }
        // 자식 하나
        else if (!cur->left || !cur->right) {
            Node* child = cur->left ? cur->left : cur->right;
            if (!parent)
                head = child;
            else {
                if (parent->left == cur) parent->left = child;
                else parent->right = child;
            }
            delete cur;
        }
        // 자식 둘
        else {
            Node* pred = cur;
            Node* succ = cur->left;
            while (succ->right) {
                pred = succ;
                succ = succ->right;
            }

            if (pred != cur)
                pred->right = succ->left;
            else
                pred->left = succ->left;

            succ->left = cur->left;
            succ->right = cur->right;

            if (!parent)
                head = succ;
            else {
                if (parent->left == cur) parent->left = succ;
                else parent->right = succ;
            }

            delete cur;
        }
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
    BinarySearchTree bst(20);
    bst.addNode(10);
    bst.addNode(30);
    bst.addNode(1);
    bst.addNode(15);
    bst.addNode(25);
    bst.addNode(13);
    bst.addNode(35);
    bst.addNode(27);
    bst.addNode(40);
    bst.levelOrder(bst.head);

    bst.removeNode(40);
    bst.levelOrder(bst.head);
    bst.removeNode(25);
    bst.levelOrder(bst.head);
    bst.removeNode(20);
    bst.levelOrder(bst.head);

    return 0;
}
