class MyHashTable:
    def __init__(self, size):
        self.size = size
        self.table = [None] * size  # None으로 초기화된 테이블
        self.elemCnt = 0

    def get_hash(self, key):
        return key % self.size

    def print_hash_table(self):
        print("== Hash Table ==")
        for i in range(self.size):
            # 빈 공간은 -1로 출력
            print(f"{i}: {self.table[i] if self.table[i] is not None else -1}")

    def set_value(self, key, data):
        raise NotImplementedError("This method should be overridden in a subclass.")


class MyHashTable2(MyHashTable):
    def __init__(self, size):
        super().__init__(size)

    def set_value(self, key, data):
        idx = self.get_hash(key)

        if self.elemCnt == self.size:
            print("Hash table is full!")
            return
        elif self.table[idx] is None:
            self.table[idx] = data
        else:
            new_idx = idx
            while True:
                new_idx = (new_idx + 1) % self.size
                if self.table[new_idx] is None:
                    break
            self.table[new_idx] = data

        self.elemCnt += 1


# Test code
ht = MyHashTable2(5)
ht.set_value(1, 1)
ht.set_value(3, 3)
ht.print_hash_table()

ht.set_value(1, 10)
ht.print_hash_table()

ht.set_value(1, 20)
ht.set_value(1, 30)
ht.set_value(1, 40)
ht.print_hash_table()
