#include <iostream>
using namespace std;

class MyHashTable {
protected:
    int* table;
    int size;
    int elemCnt;

public:
    MyHashTable(int size) {
        this->size = size;
        this->table = new int[size]();
        this->elemCnt = 0;
    }

    virtual ~MyHashTable() {
        delete[] table;
    }

    int getHash(int key) {
        return key % this->size;
    }

    virtual void setValue(int key, int data) = 0;

    void printHashTable() {
        cout << "== Hash Table ==" << endl;
        for (int i = 0; i < this->size; i++) {
            cout << i << ": " << (table[i] != 0 ? table[i] : -1) << endl;  // 빈 공간은 -1로 출력
        }
    }
};

class MyHashTable2 : public MyHashTable {
public:
    MyHashTable2(int size) : MyHashTable(size) {}

    void setValue(int key, int data) override {
        int idx = this->getHash(key);

        if (this->elemCnt == this->size) {
            cout << "Hash table is full!" << endl;
            return;
        }
        else if (this->table[idx] == 0) {
            this->table[idx] = data;
        }
        else {
            int newIdx = idx;
            while (true) {
                newIdx = (newIdx + 1) % this->size;
                if (this->table[newIdx] == 0) {
                    break;
                }
            }
            this->table[newIdx] = data;
        }

        this->elemCnt++;
    }
};

int main() {
    // Test code
    MyHashTable2 ht(5);
    ht.setValue(1, 1);
    ht.setValue(3, 3);
    ht.printHashTable();

    ht.setValue(1, 10);
    ht.printHashTable();

    ht.setValue(1, 20);
    ht.setValue(1, 30);
    ht.setValue(1, 40);
    ht.printHashTable();

    return 0;
}
