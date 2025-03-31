class NodeBi:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None

class CircularLinkedList:
    def __init__(self, node):
        self.head = node
        self.tail = node
        node.next = self.head
        node.prev = self.head

    def is_empty(self):
        return self.head is None

    def add_data(self, data, before_data=None):
        if self.head is None:
            new_node = NodeBi(data)
            self.head = new_node
            self.tail = new_node
            new_node.next = new_node
            new_node.prev = new_node
        elif before_data is None:
            new_node = NodeBi(data)
            new_node.next = self.head
            new_node.prev = self.tail
            self.tail.next = new_node
            self.head.prev = new_node
            self.tail = new_node
        else:
            cur = self.head
            while True:
                if cur.data == before_data:
                    new_node = NodeBi(data)
                    new_node.next = cur
                    new_node.prev = cur.prev
                    cur.prev.next = new_node
                    cur.prev = new_node
                    if cur == self.head:
                        self.head = new_node
                    return
                cur = cur.next
                if cur == self.head:
                    break

    def remove_data(self, data):
        if self.is_empty():
            print("List is empty")
            return

        cur = self.head
        while True:
            if cur.data == data:
                if cur == self.head and cur == self.tail:
                    self.head = None
                    self.tail = None
                elif cur == self.head:
                    self.head = cur.next
                    self.head.prev = self.tail
                    self.tail.next = self.head
                elif cur == self.tail:
                    self.tail = cur.prev
                    self.tail.next = self.head
                    self.head.prev = self.tail
                else:
                    cur.prev.next = cur.next
                    cur.next.prev = cur.prev
                return
            cur = cur.next
            if cur == self.head:
                break

    def show_data(self):
        if self.is_empty():
            print("List is empty!")
            return
        cur = self.head
        while True:
            print(cur.data, end=" ")
            cur = cur.next
            if cur == self.head:
                break
        print()

if __name__ == "__main__":
    myList = CircularLinkedList(NodeBi(1))
    myList.add_data(2)
    myList.add_data(3)
    myList.add_data(4)
    myList.add_data(5)
    myList.show_data()  # 1 2 3 4 5

    myList.add_data(100, 1)
    myList.add_data(200, 2)
    myList.add_data(300, 3)
    myList.add_data(400, 4)
    myList.add_data(500, 5)
    myList.show_data()  # 100 1 200 2 300 3 400 4 500 5

    myList.remove_data(300)
    myList.remove_data(100)
    myList.remove_data(500)
    myList.remove_data(200)
    myList.remove_data(400)
    myList.show_data()  # 1 2 3 4 5

    myList.remove_data(3)
    myList.remove_data(1)
    myList.remove_data(5)
    myList.remove_data(2)
    myList.remove_data(4)
    myList.show_data()  # List is empty!
