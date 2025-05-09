from collections import deque

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
        self.parent = None

class BinaryTree:
    def __init__(self, arr):
        nodes = [Node(data) for data in arr]

        for i in range(len(arr)):
            left = 2 * i + 1
            right = 2 * i + 2
            if left < len(arr):
                nodes[i].left = nodes[left]
                nodes[left].parent = nodes[i]
            if right < len(arr):
                nodes[i].right = nodes[right]
                nodes[right].parent = nodes[i]

        self.head = nodes[0]

    def search_node(self, data):
        queue = deque([self.head])
        while queue:
            cur = queue.popleft()
            if cur.data == data:
                return cur
            if cur.left:
                queue.append(cur.left)
            if cur.right:
                queue.append(cur.right)
        return None

    def check_size(self, data):
        node = self.search_node(data)
        if not node:
            return 0

        queue = deque([node])
        size = 0

        while queue:
            cur = queue.popleft()
            if cur.left:
                queue.append(cur.left)
                size += 1
            if cur.right:
                queue.append(cur.right)
                size += 1
        return size + 1

if __name__ == "__main__":
    arr = [chr(ord('A') + i) for i in range(10)]
    bt = BinaryTree(arr)

    print(f"Root: {bt.head.data}")

    B = bt.search_node('B')
    if B.left:
        print(f"B -> left child: {B.left.data}")
    if B.right:
        print(f"B -> right child: {B.right.data}")

    F = bt.search_node('F')
    print(f"F -> parent: {F.parent.data}")

    print("Leaf node: ", end="")
    for c in arr:
        cur = bt.search_node(c)
        if cur.left is None and cur.right is None:
            print(cur.data, end=" ")
    print()

    E = bt.search_node('E')
    cur = E
    cnt = 0
    while cur.parent:
        cur = cur.parent
        cnt += 1
    print(f"E depth: {cnt}")

    print("Level2 Node: ", end="")
    for c in arr:
        target = bt.search_node(c)
        cur = target
        cnt = 0
        while cur.parent:
            cur = cur.parent
            cnt += 1
        if cnt == 2:
            print(target.data, end=" ")
    print()

    max_depth = 0
    for c in arr:
        target = bt.search_node(c)
        cur = target
        cnt = 0
        while cur.parent:
            cur = cur.parent
            cnt += 1
        max_depth = max(max_depth, cnt)
    print(f"Height: {max_depth}")

    size = bt.check_size('B')
    print(f"B size = {size}")
