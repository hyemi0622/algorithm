class MyHashTable {
  constructor(size) {
    this.size = size;
    this.table = new Array(size).fill(null);
    this.elemCnt = 0;
  }

  getHash(key) {
    return key % this.size;
  }

  printHashTable() {
    console.log("== Hash Table ==");
    for (let i = 0; i < this.size; i++) {
      console.log(`${i}: ${this.table[i] === null ? "empty" : this.table[i]}`);
    }
  }

  setValue(key, data) {
    throw new Error("This method should be overridden in a subclass.");
  }
}

class MyHashTable3 extends MyHashTable {
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
      let cnt = 0;
      while (true) {
        newIdx = (newIdx + Math.pow(2, cnt)) % this.size;
        if (this.table[newIdx] === null) {
          break;
        }
        cnt++;
      }
      this.table[newIdx] = data;
    }

    this.elemCnt++;
  }
}

// Test code
const ht = new MyHashTable3(11);
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
