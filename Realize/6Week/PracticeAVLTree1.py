class Node:
    def __init__(self, key):
        self.key = key
        self.height = 0
        self.left = None
        self.right = None

class AVLTree:
    def __init__(self):
        self.head = None

    def height(self, node):
        if node is None:
            return -1
        return node.height

    def right_rotate(self, node):  # LL case
        lnode = node.left
        node.left = lnode.right
        lnode.right = node

        node.height = max(self.height(node.left), self.height(node.right)) + 1
        lnode.height = max(self.height(lnode.left), self.height(lnode.right)) + 1
        return lnode

    def left_rotate(self, node):  # RR case
        rnode = node.right
        node.right = rnode.left
        rnode.left = node

        node.height = max(self.height(node.left), self.height(node.right)) + 1
        rnode.height = max(self.height(rnode.left), self.height(rnode.right)) + 1
        return rnode

    def lr_rotate(self, node):
        node.left = self.left_rotate(node.left)
        return self.right_rotate(node)

    def rl_rotate(self, node):
        node.right = self.right_rotate(node.right)
        return self.left_rotate(node)

    def get_balance(self, node):
        if node is None:
            return 0
        return self.height(node.left) - self.height(node.right)

    def insert(self, key):
        self.head = self._insert(self.head, key)

    def _insert(self, node, key):
        if node is None:
            return Node(key)

        if key < node.key:
            node.left = self._insert(node.left, key)
        else:
            node.right = self._insert(node.right, key)

        node.height = max(self.height(node.left), self.height(node.right)) + 1
        balance = self.get_balance(node)

        # LL
        if balance > 1 and key < node.left.key:
            return self.right_rotate(node)

        # RR
        if balance < -1 and key > node.right.key:
            return self.left_rotate(node)

        # LR
        if balance > 1 and key > node.left.key:
            return self.lr_rotate(node)

        # RL
        if balance < -1 and key < node.right.key:
            return self.rl_rotate(node)

        return node

    def level_order(self, node):
        if node is None:
            return

        queue = [node]
        while queue:
            cur = queue.pop(0)

            print(cur.key, end=" ")
            if cur.left is not None:
                queue.append(cur.left)
            if cur.right is not None:
                queue.append(cur.right)

        print()

# Test Code
avl = AVLTree()

avl.insert(30)
avl.insert(20)
avl.insert(10)     # LL
avl.level_order(avl.head)

avl.insert(40)
avl.insert(50)     # RR
avl.level_order(avl.head)

avl.insert(5)
avl.insert(7)      # LR
avl.level_order(avl.head)

avl.insert(60)
avl.insert(55)     # RL
avl.level_order(avl.head)
