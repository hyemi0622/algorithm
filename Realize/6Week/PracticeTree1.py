class BinaryTree:
    def __init__(self, data):
        self.arr = data.copy()

    def pre_order(self, idx):
        if idx >= len(self.arr):
            return
        print(self.arr[idx], end=' ')
        self.pre_order(2 * idx + 1)
        self.pre_order(2 * idx + 2)

    def in_order(self, idx):
        if idx >= len(self.arr):
            return
        self.in_order(2 * idx + 1)
        print(self.arr[idx], end=' ')
        self.in_order(2 * idx + 2)

    def post_order(self, idx):
        if idx >= len(self.arr):
            return
        self.post_order(2 * idx + 1)
        self.post_order(2 * idx + 2)
        print(self.arr[idx], end=' ')

    def level_order(self):
        for c in self.arr:
            print(c, end=' ')

if __name__ == "__main__":
    arr = [chr(ord('A') + i) for i in range(10)]
    bt = BinaryTree(arr)

    print("== Preorder ==")
    bt.pre_order(0)
    print()

    print("== Inorder ==")
    bt.in_order(0)
    print()

    print("== Postorder ==")
    bt.post_order(0)
    print()

    print("== Levelorder ==")
    bt.level_order()
    print()
