class MyHashTable:
    def __init__(self, size):
        self.size = size
        self.table = [None] * size
        self.elemCnt = 0

    # 해시 함수
    def get_hash(self, key):
        return key % self.size

    # 값 설정
    def set_value(self, key, data):
        idx = self.get_hash(key)
        self.table[idx] = data
        self.elemCnt += 1

    # 값 가져오기
    def get_value(self, key):
        idx = self.get_hash(key)
        return self.table[idx]

    # 값 삭제
    def remove_value(self, key):
        idx = self.get_hash(key)
        self.table[idx] = None
        self.elemCnt -= 1

    # 해시 테이블 출력
    def print_hash_table(self):
        print("== Hash Table ==")
        for i in range(self.size):
            print(f"{i}: {self.table[i] if self.table[i] is not None else 'null'}")


# 테스트 코드
if __name__ == "__main__":
    ht = MyHashTable(7)
    ht.set_value(1, 1)
    ht.set_value(2, 2)
    ht.set_value(3, 3)
    ht.set_value(4, 4)
    ht.set_value(5, 5)
    ht.print_hash_table()

    ht.set_value(8, 6)  # 충돌이 발생할 수 있음
    ht.print_hash_table()
