class MyHashTable {
    constructor(size) {
        this.table = new Array(size).fill(-1);
        this.size = size;
        this.elemCnt = 0;
    }

    getHash(key) {
        return key % this.size;
    }

    setValue(key, data) {
        throw new Error("setValue must be implemented by subclass");
    }

    getValue(key) {
        const idx = this.getHash(key);
        return this.table[idx];
    }

    removeValue(key) {
        const idx = this.getHash(key);
        this.table[idx] = -1; // 빈 슬롯을 -1로 표시
        this.elemCnt--;
    }

    printHashTable() {
        console.log("== Hash Table ==");
        for (let i = 0; i < this.size; i++) {
            console.log(`${i}: ${this.table[i] === -1 ? 'null' : this.table[i]}`);
        }
    }
}

class MyHashTable4 extends MyHashTable {
    constructor(size) {
        super(size);
        this.c = this.getHashC(size);
    }

    getHashC(size) {
        let c = 0;

        if (size <= 2) {
            return size;
        }

        for (let i = size - 1; i > 2; i--) {
            let isPrime = true;
            for (let j = 2; j < i; j++) {
                if (i % j === 0) {
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

    getHash2(key) {
        return 1 + key % this.c;
    }

    setValue(key, data) {
        let idx = this.getHash(key);

        if (this.elemCnt === this.size) {
            console.log("Hash table is full!");
            return;
        } else if (this.table[idx] === -1) {
            this.table[idx] = data;
        } else {
            let newIdx = idx;
            let cnt = 1;
            while (true) {
                newIdx = (newIdx + this.getHash2(newIdx) * cnt) % this.size;
                if (this.table[newIdx] === -1) {
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
const ht = new MyHashTable4(11);
ht.setValue(1, 10);
ht.setValue(2, 20);
ht.setValue(3, 30);
ht.printHashTable();

ht.setValue(1, 100);
ht.setValue(1, 200);
ht.setValue(1, 300);
ht.printHashTable();
