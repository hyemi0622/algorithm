import math

class MyHashTable:
    def __init__(self, size):
        self.size = size
        self.table = [None] * size
        self.elemCnt = 0

    def get_hash(self, key):
        return key % self.size

    def print_hash_table(self):
        print("== Hash Table ==")
        for i in range(self.size):
            if self.table[i] is None:
                print(f"{i}: empty")
            else:
                print(f"{i}: {self.table[i]}")

    def set_value(self, key, data):
        raise NotImplementedError("This method should be overridden in a subclass.")

class MyHashTable3(MyHashTable):
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
            cnt = 0
            while True:
                new_idx = (new_idx + int(math.pow(2, cnt))) % self.size
                if self.table[new_idx] is None:
                    break
                cnt += 1
            self.table[new_idx] = data

        self.elemCnt += 1

# Test code
ht = MyHashTable3(11)
ht.set_value(1, 10)
ht.set_value(2, 20)
ht.set_value(4, 40)
ht.print_hash_table()

ht.set_value(1, 100)
ht.print_hash_table()

ht.set_value(1, 200)
ht.set_value(1, 300)
ht.set_value(1, 400)
ht.print_hash_table()
