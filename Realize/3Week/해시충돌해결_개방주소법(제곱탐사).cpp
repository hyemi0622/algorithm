#include <iostream>
#include <cmath>
using namespace std;

class MyHashTable {
protected:
    int* table;
    int size;
    int elemCnt;

public:
    MyHashTable(int size) {
        this->size = size;
        this->table = new int[size];
        for (int i = 0; i < size; i++) {
            table[i] = -1;  // -1로 초기화 (빈 슬롯을 나타냄)
        }
        this->elemCnt = 0;
    }

    ~MyHashTable() {
        delete[] table;
    }

    int getHash(int key) {
        return key % this->size;
    }

    virtual void setValue(int key, int data) {
        throw "This method should be overridden in a subclass.";
    }

    void printHashTable() {
        cout << "== Hash Table ==" << endl;
        for (int i = 0; i < this->size; i++) {
            if (table[i] == -1)
                cout << i << ": " << "empty" << endl;
            else
                cout << i << ": " << table[i] << endl;
        }
    }
};

class MyHashTable3 : public MyHashTable {
public:
    MyHashTable3(int size) : MyHashTable(size) {}

    void setValue(int key, int data) override {
        int idx = this->getHash(key);

        if (this->elemCnt == this->size) {
            cout << "Hash table is full!" << endl;
            return;
        } else if (this->table[idx] == -1) {
            this->table[idx] = data;
        } else {
            int newIdx = idx;
            int cnt = 0;
            while (true) {
                newIdx = (newIdx + pow(2, cnt)) / this->size;
                if (this->table[newIdx] == -1) {
                    break;
                }
                cnt++;
            }
            this->table[newIdx] = data;
        }

        elemCnt++;
    }
};

int main() {
    MyHashTable3 ht(11);
    ht.setValue(1, 10);
    ht.setValue(2, 20);
    ht.setValue(4, 40);
    ht.printHashTable();

    ht.setValue(1, 100);
    ht.printHashTable();

    ht.setValue(1, 200);
    ht.setValue(1, 300);
    ht.setValue(1, 400);
    ht.printHashTable();

    return 0;
}
