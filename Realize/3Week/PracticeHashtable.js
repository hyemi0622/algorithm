class MyHashTable {
    constructor(size) {
        this.size = size;
        this.table = new Array(size).fill(null);
        this.elemCnt = 0;
    }

    // 해시 함수
    getHash(key) {
        return key % this.size;
    }

    // 값 설정
    setValue(key, data) {
        const idx = this.getHash(key);
        this.table[idx] = data;
        this.elemCnt++;
    }

    // 값 가져오기
    getValue(key) {
        const idx = this.getHash(key);
        return this.table[idx];
    }

    // 값 삭제
    removeValue(key) {
        const idx = this.getHash(key);
        this.table[idx] = null;
        this.elemCnt--;
    }

    // 해시 테이블 출력
    printHashTable() {
        console.log("== Hash Table ==");
        for (let i = 0; i < this.size; i++) {
            console.log(`${i}: ${this.table[i] !== null ? this.table[i] : 'null'}`);
        }
    }
}

// 테스트 코드
const ht = new MyHashTable(7);
ht.setValue(1, 1);
ht.setValue(2, 2);
ht.setValue(3, 3);
ht.setValue(4, 4);
ht.setValue(5, 5);
ht.printHashTable();

ht.setValue(8, 6); // 충돌이 발생할 수 있음
ht.printHashTable();
