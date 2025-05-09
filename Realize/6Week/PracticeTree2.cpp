#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node {
public:
    char data;
    Node* left;
    Node* right;

    Node(char data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BinaryTree {
public:
    Node* head;
    int length;

    BinaryTree(vector<char>& arr) {
        length = arr.size();
        vector<Node*> nodes(length);
        for (int i = 0; i < length; i++) {
            nodes[i] = new Node(arr[i]);
        }
        for (int i = 0; i < length; i++) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            if (left < length) nodes[i]->left = nodes[left];
            if (right < length) nodes[i]->right = nodes[right];
        }
        head = nodes[0];
    }

    void preOrder(Node* node) {
        if (!node) return;
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }

    void inOrder(Node* node) {
        if (!node) return;
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }

    void postOrder(Node* node) {
        if (!node) return;
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }

    void levelOrder(Node* node) {
        if (!node) return;
        queue<Node*> q;
        q.push(node);

        while (!q.empty()) {
            Node* cur = q.front();
            q.pop();
            cout << cur->data << " ";
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
    }
};

int main() {
    vector<char> arr(10);
    for (int i = 0; i < 10; i++) {
        arr[i] = 'A' + i;
    }

    BinaryTree bt(arr);

    cout << "== Preorder ==" << endl;
    bt.preOrder(bt.head);
    cout << endl;

    cout << "== Inorder ==" << endl;
    bt.inOrder(bt.head);
    cout << endl;

    cout << "== Postorder ==" << endl;
    bt.postOrder(bt.head);
    cout << endl;

    cout << "== Levelorder ==" << endl;
    bt.levelOrder(bt.head);
    cout << endl;

    return 0;
}
