class Node:
    def __init__(self):
        self.child = {}
        self.is_terminal = False

class Trie:
    def __init__(self):
        self.root = Node()

    def insert(self, word: str):
        cur = self.root
        for i, c in enumerate(word):
            if c not in cur.child:
                cur.child[c] = Node()
            cur = cur.child[c]
            if i == len(word) - 1:
                cur.is_terminal = True

    def search(self, word: str) -> bool:
        cur = self.root
        for i, c in enumerate(word):
            if c not in cur.child:
                return False
            cur = cur.child[c]
            if i == len(word) - 1 and not cur.is_terminal:
                return False
        return True

    def delete(self, word: str):
        deleted = self._delete(self.root, word, 0)
        if deleted:
            print(f"{word} 삭제 완료")
        else:
            print(f"{word} 단어가 없습니다.")

    def _delete(self, node: Node, word: str, idx: int) -> bool:
        c = word[idx]
        if c not in node.child:
            return False

        cur = node.child[c]
        idx += 1

        if idx == len(word):
            if not cur.is_terminal:
                return False
            cur.is_terminal = False
            if not cur.child:
                del node.child[c]
        else:
            if not self._delete(cur, word, idx):
                return False
            if not cur.is_terminal and not cur.child:
                del node.child[c]
        return True


# Test code
if __name__ == "__main__":
    trie = Trie()
    trie.insert("apple")
    trie.insert("april")
    trie.insert("app")
    trie.insert("ace")
    trie.insert("bear")
    trie.insert("best")

    print(trie.search("apple"))   # True
    print(trie.search("april"))   # True
    print(trie.search("app"))     # True
    print(trie.search("ace"))     # True
    print(trie.search("bear"))    # True
    print(trie.search("best"))    # True
    print(trie.search("abc"))     # False

    print()
    trie.delete("apple")
    print(trie.search("apple"))   # False
    print(trie.search("april"))   # True
    print(trie.search("appl"))    # False
    trie.delete("apple")          # Already deleted
