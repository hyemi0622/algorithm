#include <iostream>
#include <unordered_map>
#include<vector>
#include<string>
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

    void insert(const vector<string> strs) {
        
        for (string str : strs) {
            Node* cur = root;
            for (int i = 0; i < str.length(); i++) {
                char c = str[i];
                if (cur->child.find(c) == cur->child.end()) {
                    cur->child[c] = new Node();
                }
                cur = cur->child[c];

                if (i == str.length() - 1) {
                    cur->isTerminal = true;
                }
            }
        }
    }

    bool search(const vector<string> strs){
        
        for (string str : strs) {
            int cnt = 0;
            Node* cur = root;
            for (int i = 0; i < str.length(); i++) {
                char c = str[i];
                cur = cur->child[c];

                if (cur->isTerminal && cnt < str.length() - 1) {
                    return false;
                }
                cnt++;
            }
        }
        return true;
    }

};

bool solution(vector<string> phone_book) {
    Trie t;
    t.insert(phone_book);
    bool result = t.search(phone_book);
    return result;
}
