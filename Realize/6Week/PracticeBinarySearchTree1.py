from collections import deque

class Node:
    def __init__(self, key, left=None, right=None):
        self.key = key
        self.left = left
        self.right = right

class BinarySearchTree:
    def __init__(self, key):
        self.head = Node(key)

    def add_node(self, key):
        if not self.head:
            self.head = Node(key)
            return
        cur = self.head
        while True:
            pre = cur
            if key < cur.key:
                cur = cur.left
                if not cur:
                    pre.left = Node(key)
                    break
            else:
                cur = cur.right
                if not cur:
                    pre.right = Node(key)
                    break

    def remove_node(self, key):
        parent = None
        cur = self.head

        while cur and cur.key != key:
            parent = cur
            if key < cur.key:
                cur = cur.left
            else:
                cur = cur.right

        if not cur:
            print("Key not found")
            return

        # No children
        if not cur.left and not cur.right:
            if not parent:
                self.head = None
            elif parent.left == cur:
                parent.left = None
            else:
                parent.right = None

        # One child
        elif not cur.left or not cur.right:
            child = cur.left if cur.left else cur.right
            if not parent:
                self.head = child
            elif parent.left == cur:
                parent.left = child
            else:
                parent.right = child

        # Two children
        else:
            pred = cur
            succ = cur.left
            while succ.right:
                pred = succ
                succ = succ.right

            if pred != cur:
                pred.right = succ.left
            else:
                pred.left = succ.left

            succ.left = cur.left
            succ.right = cur.right

            if not parent:
                self.head = succ
            elif parent.left == cur:
                parent.left = succ
            else:
                parent.right = succ

    def level_order(self, node):
        if not node:
            return
        queue = deque([node])
        while queue:
            cur = queue.popleft()
            print(cur.key, end=' ')
            if cur.left:
                queue.append(cur.left)
            if cur.right:
                queue.append(cur.right)
        print()

if __name__ == "__main__":
    bst = BinarySearchTree(20)
    bst.add_node(10)
    bst.add_node(30)
    bst.add_node(1)
    bst.add_node(15)
    bst.add_node(25)
    bst.add_node(13)
    bst.add_node(35)
    bst.add_node(27)
    bst.add_node(40)
    bst.level_order(bst.head)

    bst.remove_node(40)
    bst.level_order(bst.head)
    bst.remove_node(25)
    bst.level_order(bst.head)
    bst.remove_node(20)
    bst.level_order(bst.head)
