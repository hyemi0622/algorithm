# 앞의 BST 삽입, 삭제 코드를 재귀 형태로 구현
from collections import deque

class Node:
    def __init__(self, key, left=None, right=None):
        self.key = key
        self.left = left
        self.right = right

class BinarySearchTree:
    def __init__(self, key):
        self.head = Node(key)

    def addNodeRecursive(self, cur, key):
        if not cur:
            return Node(key)
        if key < cur.key:
            cur.left = self.addNodeRecursive(cur.left, key)
        else:
            cur.right = self.addNodeRecursive(cur.right, key)
        return cur

    def removeNodeRecursive(self, cur, key):
        if not cur:
            return None
        if key < cur.key:
            cur.left = self.removeNodeRecursive(cur.left, key)
        elif key > cur.key:
            cur.right = self.removeNodeRecursive(cur.right, key)
        else:
            if not cur.left:
                return cur.right
            elif not cur.right:
                return cur.left
            else:
                predecessor = cur
                successor = cur.left
                while successor.right:
                    predecessor = successor
                    successor = successor.right
                cur.key = successor.key
                if predecessor == cur:
                    predecessor.left = successor.left
                else:
                    predecessor.right = successor.left
        return cur

    def levelOrder(self, node):
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

# Test
bst = BinarySearchTree(20)
bst.head = bst.addNodeRecursive(bst.head, 10)
bst.head = bst.addNodeRecursive(bst.head, 30)
bst.head = bst.addNodeRecursive(bst.head, 1)
bst.head = bst.addNodeRecursive(bst.head, 15)
bst.head = bst.addNodeRecursive(bst.head, 25)
bst.head = bst.addNodeRecursive(bst.head, 13)
bst.head = bst.addNodeRecursive(bst.head, 35)
bst.head = bst.addNodeRecursive(bst.head, 27)
bst.head = bst.addNodeRecursive(bst.head, 40)
bst.levelOrder(bst.head)

bst.head = bst.removeNodeRecursive(bst.head, 40)
bst.levelOrder(bst.head)
bst.head = bst.removeNodeRecursive(bst.head, 25)
bst.levelOrder(bst.head)
bst.head = bst.removeNodeRecursive(bst.head, 20)
bst.levelOrder(bst.head)
