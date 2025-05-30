//삭제 연산 추가
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
        return -1 if node is None else node.height

    def get_balance(self, node):
        return 0 if node is None else self.height(node.left) - self.height(node.right)

    def right_rotate(self, node):
        lnode = node.left
        node.left = lnode.right
        lnode.right = node

        node.height = max(self.height(node.left), self.height(node.right)) + 1
        lnode.height = max(self.height(lnode.left), self.height(lnode.right)) + 1
        return lnode

    def left_rotate(self, node):
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

        if balance > 1 and key < node.left.key:
            return self.right_rotate(node)
        if balance < -1 and key > node.right.key:
            return self.left_rotate(node)
        if balance > 1 and key > node.left.key:
            return self.lr_rotate(node)
        if balance < -1 and key < node.right.key:
            return self.rl_rotate(node)

        return node

    def delete(self, key):
        self.head = self._delete(self.head, key)

    def _delete(self, node, key):
        if node is None:
            return None

        if key < node.key:
            node.left = self._delete(node.left, key)
        elif key > node.key:
            node.right = self._delete(node.right, key)
        else:
            if node.left is None:
                return node.right
            elif node.right is None:
                return node.left
            else:
                pred = node
                succ = node.left
                while succ.right:
                    pred = succ
                    succ = succ.right
                pred.right = succ.left
                node.key = succ.key

        node.height = max(self.height(node.left), self.height(node.right)) + 1
        balance = self.get_balance(node)

        if balance > 1 and self.get_balance(node.left) >= 0:
            return self.right_rotate(node)
        if balance < -1 and self.get_balance(node.right) <= 0:
            return self.left_rotate(node)
        if balance > 1 and self.get_balance(node.left) < 0:
            return self.lr_rotate(node)
        if balance < -1 and self.get_balance(node.right) > 0:
            return self.rl_rotate(node)

        return node

    def level_order(self, node):
        if node is None:
            return

        queue = [node]
        while queue:
            cur = queue.pop(0)
            print(cur.key, end=" ")
            if cur.left:
                queue.append(cur.left)
            if cur.right:
                queue.append(cur.right)
        print()

# 테스트
avl = AVLTree()

avl.insert(30)
avl
