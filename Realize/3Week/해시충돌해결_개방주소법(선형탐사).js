class MyHashTable {
  constructor(size) {
    this.size = size;
    this.table = new Array(size).fill(null); // None 대신 null로 초기화된 테이블
    this.elemCnt = 0;
  }

  getHash(key) {
    return key % this.size;
  }

  printHashTable() {
    console.log("== Hash Table ==");
    for (let i = 0; i < this.size; i++) {
      // 빈 공간은 -1로 출력
      console.log(`${i}: ${this.table[i] === null ? -1 : this.table[i]}`);
    }
  }

  setValue(key, data) {
    throw new Error("This method should be overridden in a subclass.");
  }
}

class MyHashTable2 extends MyHashTable {
  constructor(size) {
    super(size);
  }

  setValue(key, data) {
    let idx = this.getHash(key);

    if (this.elemCnt === this.size) {
      console.log("Hash table is full!");
      return;
    } else if (this.table[idx] === null) {
      this.table[idx] = data;
    } else {
      let newIdx = idx;
      while (true) {
        newIdx = (newIdx + 1) % this.size;
        if (this.table[newIdx] === null) {
          break;
        }
      }
      this.table[newIdx] = data;
    }

    this.elemCnt++;
  }
}

// Test code
const ht = new MyHashTable2(5);
ht.setValue(1, 1);
ht.setValue(3, 3);
ht.printHashTable();

ht.setValue(1, 10);
ht.printHashTable();

ht.setValue(1, 20);
ht.setValue(1, 30);
ht.setValue(1, 40);
ht.printHashTable();
