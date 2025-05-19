#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    unordered_map<char, Node*> child;
    bool isTerminal;

    Node() {
        isTerminal = false;
    }
};

class Trie {
public:
    Node* root;

    Trie() {
        root = new Node();
    }

    void insert(const string& str) {
        Node* cur = root;
        for (int i = 0; i < str.length(); i++) {
            char c = str[i];
            if (cur->child.find(c) == cur->child.end()) {
                cur->child[c] = new Node();
            }
            cur = cur->child[c];

            if (i == str.length() - 1) {
                cur->isTerminal = true;
                return;
            }
        }
    }

    bool search(const string& str) {
        Node* cur = root;
        for (int i = 0; i < str.length(); i++) {
            char c = str[i];
            if (cur->child.find(c) == cur->child.end()) {
                return false;
            }
            cur = cur->child[c];

            if (i == str.length() - 1 && !cur->isTerminal) {
                return false;
            }
        }
        return true;
    }

    bool deleteHelper(Node* node, const string& str, int idx) {
        char c = str[idx];
        if (node->child.find(c) == node->child.end()) {
            return false;
        }

        Node* cur = node->child[c];
        idx++;

        if (idx == str.length()) {
            if (!cur->isTerminal) return false;
            cur->isTerminal = false;
            if (cur->child.empty()) {
                delete cur;
                node->child.erase(c);
            }
        }
        else {
            if (!deleteHelper(cur, str, idx)) return false;
            if (!cur->isTerminal && cur->child.empty()) {
                delete cur;
                node->child.erase(c);
            }
        }
        return true;
    }

    void deleteWord(const string& str) {
        bool result = deleteHelper(root, str, 0);
        if (result) {
            cout << str << " 삭제 완료" << endl;
        }
        else {
            cout << str << " 단어가 없습니다." << endl;
        }
    }
};

int main() {
    Trie trie;
    trie.insert("apple");
    trie.insert("april");
    trie.insert("app");
    trie.insert("ace");
    trie.insert("bear");
    trie.insert("best");

    cout << boolalpha;
    cout << trie.search("apple") << endl;  // true
    cout << trie.search("april") << endl;  // true
    cout << trie.search("app") << endl;    // true
    cout << trie.search("ace") << endl;    // true
    cout << trie.search("bear") << endl;   // true
    cout << trie.search("best") << endl;   // true
    cout << trie.search("abc") << endl;    // false

    cout << endl;
    trie.deleteWord("apple");
    cout << trie.search("apple") << endl;  // false
    cout << trie.search("april") << endl;  // true
    cout << trie.search("appl") << endl;   // false
    trie.deleteWord("apple");              // already deleted
}
