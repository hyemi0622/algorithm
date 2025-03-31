#include <iostream>
#include <string>
using namespace std;

class MyHashTable {
private:
    int* table;
    int elemCnt;
    int size;

public:
    MyHashTable(int size) {
        this->size = size;
        this->table = new int[size];
        this->elemCnt = 0;

        // 배열을 null로 초기화
        for (int i = 0; i < size; i++) {
            this->table[i] = -1;  // -1을 null 대신 사용
        }
    }

    ~MyHashTable() {
        delete[] table;
    }

    // 해시 함수
    int getHash(int key) {
        return key % this->size;
    }

    // 값 설정
    void setValue(int key, int data) {
        int idx = getHash(key);
        this->table[idx] = data;
        this->elemCnt++;
    }

    // 값 가져오기
    int getValue(int key) {
        int idx = getHash(key);
        return this->table[idx];
    }

    // 값 삭제
    void removeValue(int key) {
        int idx = getHash(key);
        this->table[idx] = -1;  // -1로 삭제 표시
        this->elemCnt--;
    }

    // 해시 테이블 출력
    void printHashTable() {
        cout << "== Hash Table ==" << endl;
        for (int i = 0; i < this->size; i++) {
            cout << i << ": " << (this->table[i] == -1 ? "null" : to_string(this->table[i])) << endl;
        }
    }
};

int main() {
    MyHashTable ht(7);
    ht.setValue(1, 1);
    ht.setValue(2, 2);
    ht.setValue(3, 3);
    ht.setValue(4, 4);
    ht.setValue(5, 5);
    ht.printHashTable();

    ht.setValue(8, 6); // 충돌이 발생할 수 있음
    ht.printHashTable();

    return 0;
}
