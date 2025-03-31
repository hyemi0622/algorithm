class MyHashTable:
    def __init__(self, size):
        self.table = [-1] * size
        self.size = size
        self.elemCnt = 0

    def get_hash(self, key):
        return key % self.size

    def set_value(self, key, data):
        raise NotImplementedError

    def get_value(self, key):
        idx = self.get_hash(key)
        return self.table[idx]

    def remove_value(self, key):
        idx = self.get_hash(key)
        self.table[idx] = -1  # 빈 슬롯을 -1로 표시
        self.elemCnt -= 1

    def print_hash_table(self):
        print("== Hash Table ==")
        for i, value in enumerate(self.table):
            print(f"{i}: {'null' if value == -1 else value}")


class MyHashTable4(MyHashTable):
    def __init__(self, size):
        super().__init__(size)
        self.c = self.get_hash_c(size)

    def get_hash_c(self, size):
        c = 0
        if size <= 2:
            return size

        for i in range(size - 1, 2, -1):
            if all(i % j != 0 for j in range(2, i)):
                c = i
                break
        return c

    def get_hash2(self, key):
        return 1 + key % self.c

    def set_value(self, key, data):
        idx = self.get_hash(key)

        if self.elemCnt == self.size:
            print("Hash table is full!")
            return
        elif self.table[idx] == -1:
            self.table[idx] = data
        else:
            new_idx = idx
            cnt = 1
            while True:
                new_idx = (new_idx + self.get_hash2(new_idx) * cnt) % self.size
                if self.table[new_idx] == -1:
                    break
                cnt += 1
            self.table[new_idx] = data

        self.elemCnt += 1


# Test code
ht = MyHashTable4(11)
ht.set_value(1, 10)
ht.set_value(2, 20)
ht.set_value(3, 30)
ht.print_hash_table()

ht.set_value(1, 100)
ht.set_value(1, 200)
ht.set_value(1, 300)
ht.print_hash_table()
