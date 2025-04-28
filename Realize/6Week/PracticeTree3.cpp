#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node {
public:
    char data;
    Node* left;
    Node* right;
    Node* parent;

    Node(char data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
        this->parent = nullptr;
    }
};

class BinaryTree {
public:
    Node* head;

    BinaryTree(vector<char>& arr) {
        vector<Node*> nodes(arr.size());
        for (int i = 0; i < arr.size(); i++) {
            nodes[i] = new Node(arr[i]);
        }

        for (int i = 0; i < arr.size(); i++) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < arr.size()) {
                nodes[i]->left = nodes[left];
                nodes[left]->parent = nodes[i];
            }
            if (right < arr.size()) {
                nodes[i]->right = nodes[right];
                nodes[right]->parent = nodes[i];
            }
        }
        head = nodes[0];
    }

    Node* searchNode(char data) {
        queue<Node*> q;
        q.push(head);
        while (!q.empty()) {
            Node* cur = q.front();
            q.pop();
            if (cur->data == data) {
                return cur;
            }
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
        return nullptr;
    }

    int checkSize(char data) {
        Node* node = searchNode(data);
        if (!node) return 0;

        queue<Node*> q;
        q.push(node);
        int size = 0;

        while (!q.empty()) {
            Node* cur = q.front();
            q.pop();
            if (cur->left) {
                q.push(cur->left);
                size++;
            }
            if (cur->right) {
                q.push(cur->right);
                size++;
            }
        }
        return size + 1;
    }
};

int main() {
    vector<char> arr(10);
    for (int i = 0; i < 10; i++) {
        arr[i] = 'A' + i;
    }

    BinaryTree bt(arr);

    cout << "Root: " << bt.head->data << endl;

    Node* B = bt.searchNode('B');
    if (B->left) cout << "B -> left child: " << B->left->data << endl;
    if (B->right) cout << "B -> right child: " << B->right->data << endl;

    Node* F = bt.searchNode('F');
    cout << "F -> parent: " << F->parent->data << endl;

    cout << "Leaf node: ";
    for (char c = 'A'; c <= 'J'; c++) {
        Node* cur = bt.searchNode(c);
        if (cur && !cur->left && !cur->right) {
            cout << cur->data << " ";
        }
    }
    cout << endl;

    Node* E = bt.searchNode('E');
    Node* cur = E;
    int cnt = 0;
    while (cur->parent) {
        cur = cur->parent;
        cnt++;
    }
    cout << "E depth: " << cnt << endl;

    cout << "Level2 Node: ";
    for (char c = 'A'; c <= 'J'; c++) {
        Node* target = bt.searchNode(c);
        cur = target;
        cnt = 0;
        while (cur && cur->parent) {
            cur = cur->parent;
            cnt++;
        }
        if (cnt == 2) {
            cout << target->data << " ";
        }
    }
    cout << endl;

    int maxDepth = 0;
    for (char c = 'A'; c <= 'J'; c++) {
        Node* target = bt.searchNode(c);
        cur = target;
        cnt = 0;
        while (cur && cur->parent) {
            cur = cur->parent;
            cnt++;
        }
        maxDepth = max(maxDepth, cnt);
    }
    cout << "Height: " << maxDepth << endl;

    int size = bt.checkSize('B');
    cout << "B size = " << size << endl;

    return 0;
}
