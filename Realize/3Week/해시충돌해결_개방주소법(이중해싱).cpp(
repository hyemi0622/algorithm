#include <iostream>
#include <cmath>

class MyHashTable {
protected:
    int* table;
    int size;
    int elemCnt;

public:
    MyHashTable(int size) {
        this->size = size;
        this->table = new int[size]; // 동적 배열 할당
        this->elemCnt = 0;

        // 배열을 -1로 초기화하여 빈 슬롯을 나타냄
        for (int i = 0; i < size; ++i) {
            table[i] = -1;
        }
    }

    virtual ~MyHashTable() {
        delete[] table;
    }

    int getHash(int key) {
        return key % size;
    }

    virtual void setValue(int key, int data) = 0;

    int getValue(int key) {
        int idx = getHash(key);
        return table[idx];
    }

    void removeValue(int key) {
        int idx = getHash(key);
        table[idx] = -1; // 빈 슬롯을 -1로 표시
        elemCnt--;
    }

    void printHashTable() {
        std::cout << "== Hash Table ==\n";
        for (int i = 0; i < size; ++i) {
            if (table[i] == -1) {
                std::cout << i << ": null\n";
            } else {
                std::cout << i << ": " << table[i] << "\n";
            }
        }
    }
};

class MyHashTable4 : public MyHashTable {
    int c;

public:
    MyHashTable4(int size) : MyHashTable(size) {
        this->c = getHashC(size);
    }

    int getHashC(int size) {
        int c = 0;
        if (size <= 2) {
            return size;
        }

        for (int i = size - 1; i > 2; i--) {
            bool isPrime = true;
            for (int j = 2; j < i; j++) {
                if (i % j == 0) {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime) {
                c = i;
                break;
            }
        }
        return c;
    }

    int getHash2(int key) {
        return 1 + key % this->c;
    }

    void setValue(int key, int data) override {
        int idx = getHash(key);

        if (elemCnt == size) {
            std::cout << "Hash table is full!\n";
            return;
        } else if (table[idx] == -1) {
            table[idx] = data;
        } else {
            int newIdx = idx;
            int cnt = 1;
            while (true) {
                newIdx = (newIdx + getHash2(newIdx) * cnt) % size;
                if (table[newIdx] == -1) {
                    break;
                }
                cnt++;
            }
            table[newIdx] = data;
        }

        elemCnt++;
    }
};

int main() {
    MyHashTable4 ht(11);
    ht.setValue(1, 10);
    ht.setValue(2, 20);
    ht.setValue(3, 30);
    ht.printHashTable();

    ht.setValue(1, 100);
    ht.setValue(1, 200);
    ht.setValue(1, 300);
    ht.printHashTable();

    return 0;
}
