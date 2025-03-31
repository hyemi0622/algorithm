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
            }
            else {
                std::cout << i << ": " << table[i] << "\n";
            }
        }
    }
};

class MyHashTable3 : public MyHashTable {
public:
    MyHashTable3(int size) : MyHashTable(size) {}

    void setValue(int key, int data) override {
        int idx = getHash(key);

        // 테이블이 꽉 찼을 때
        if (elemCnt == size) {
            std::cout << "Hash table is full!" << std::endl;
            return;
        }
        // 해당 인덱스가 비어 있으면 바로 저장
        else if (table[idx] == -1) {
            table[idx] = data;
        }
        // 충돌이 발생하면 제곱 탐사법을 사용하여 해결
        else {
            int newIdx = idx;
            int cnt = 0;
            while (true) {
                newIdx = (newIdx + static_cast<int>(pow(2, cnt))) % size;
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
    // Test code
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
