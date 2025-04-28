from collections import deque

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class BinaryTree:
    def __init__(self, arr):
        self.length = len(arr)
        nodes = [Node(data) for data in arr]

        for i in range(self.length):
            left = 2 * i + 1
            right = 2 * i + 2
            if left < self.length:
                nodes[i].left = nodes[left]
            if right < self.length:
                nodes[i].right = nodes[right]

        self.head = nodes[0]

    def pre_order(self, node):
        if not node:
            return
        print(node.data, end=' ')
        self.pre_order(node.left)
        self.pre_order(node.right)

    def in_order(self, node):
        if not node:
            return
        self.in_order(node.left)
        print(node.data, end=' ')
        self.in_order(node.right)

    def post_order(self, node):
        if not node:
            return
        self.post_order(node.left)
        self.post_order(node.right)
        print(node.data, end=' ')

    def level_order(self, node):
        if not node:
            return
        queue = deque()
        queue.append(node)

        while queue:
            cur = queue.popleft()
            print(cur.data, end=' ')
            if cur.left:
                queue.append(cur.left)
            if cur.right:
                queue.append(cur.right)

if __name__ == "__main__":
    arr = [chr(ord('A') + i) for i in range(10)]
    bt = BinaryTree(arr)

    print("== Preorder ==")
    bt.pre_order(bt.head)
    print()

    print("== Inorder ==")
    bt.in_order(bt.head)
    print()

    print("== Postorder ==")
    bt.post_order(bt.head)
    print()

    print("== Levelorder ==")
    bt.level_order(bt.head)
    print()
