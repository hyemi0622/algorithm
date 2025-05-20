def solution(phone_book):
    phone_book.sort()
    for i in range(len(phone_book) - 1):
        if phone_book[i + 1].startswith(phone_book[i]):
      # if phone_book[i + 1][:len(phone_book[i])] == phone_book[i]:
            return False
    return True

#######################################################################################

def solution(phone_book):
    phone_set = set(phone_book)

    for number in phone_book:
        for i in range(1, len(number)):
            prefix = number[:i]
            if prefix in phone_set:
                return False
    return True

#######################################################################################

class htable:
    def __init__(self, size=10007):
        self.size = size
        self.table = [[] for _ in range(size)]

    def _hash(self, key):
        hash_val = 0
        for ch in key:
            hash_val = (hash_val * 31 + ord(ch)) % self.size
        return hash_val

    def insert(self, key):
        idx = self._hash(key)
        if key not in self.table[idx]:
            self.table[idx].append(key)

    def contains(self, key):
        idx = self._hash(key)
        return key in self.table[idx]


def solution(phone_book):
    ht = htable()
    for number in phone_book:
        ht.insert(number)
    for number in phone_book:
        for i in range(1, len(number)):
            prefix = number[:i]
            if ht.contains(prefix):
                return False
    return True
