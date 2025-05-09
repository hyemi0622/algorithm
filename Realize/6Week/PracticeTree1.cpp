#include <iostream>
#include <vector>
using namespace std;

class BinaryTree {
public:
    vector<char> arr;

    BinaryTree(vector<char> data) {
        arr = data;
    }

    void preOrder(int idx) {
        if (idx >= arr.size()) return;
        cout << arr[idx] << " ";
        preOrder(2 * idx + 1);
        preOrder(2 * idx + 2);
    }

    void inOrder(int idx) {
        if (idx >= arr.size()) return;
        inOrder(2 * idx + 1);
        cout << arr[idx] << " ";
        inOrder(2 * idx + 2);
    }

    void postOrder(int idx) {
        if (idx >= arr.size()) return;
        postOrder(2 * idx + 1);
        postOrder(2 * idx + 2);
        cout << arr[idx] << " ";
    }

    void levelOrder() {
        for (char c : arr) {
            cout << c << " ";
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
    bt.preOrder(0);
    cout << endl;

    cout << "== Inorder ==" << endl;
    bt.inOrder(0);
    cout << endl;

    cout << "== Postorder ==" << endl;
    bt.postOrder(0);
    cout << endl;

    cout << "== Levelorder ==" << endl;
    bt.levelOrder();
    cout << endl;

    return 0;
}
