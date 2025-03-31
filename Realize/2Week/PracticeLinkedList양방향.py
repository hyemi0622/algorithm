class NodeBi:
    def __init__(self, data, next=None, prev=None):
        self.data = data
        self.next = next
        self.prev = prev


class DoublyLinkedList:
    def __init__(self, node):
        self.head = node
        self.tail = node

    def is_empty(self):
        return self.head is None

    def add_data(self, data, before_data=None):
        if self.head is None:
            self.head = NodeBi(data)
            self.tail = self.head
        elif before_data is None:
            self.tail.next = NodeBi(data, None, self.tail)
            self.tail = self.tail.next
        else:
            cur = self.head
            while cur:
                if cur.data == before_data:
                    new_node = NodeBi(data, cur, cur.prev)
                    if cur.prev:
                        cur.prev.next = new_node
                    else:
                        self.head = new_node
                    cur.prev = new_node
                    return
                cur = cur.next

    def remove_data(self, data):
        if self.is_empty():
            print("List is empty")
            return

        cur = self.head
        while cur:
            if cur.data == data:
                if cur == self.head and cur == self.tail:
                    self.head = None
                    self.tail = None
                elif cur == self.head:
                    self.head = cur.next
                    if self.head:
                        self.head.prev = None
                elif cur == self.tail:
                    self.tail = self.tail.prev
                    self.tail.next = None
                else:
                    cur.prev.next = cur.next
                    cur.next.prev = cur.prev
                return
            cur = cur.next

    def show_data(self):
        if self.is_empty():
            print("List is empty!")
            return
        cur = self.head
        while cur:
            print(cur.data, end=" ")
            cur = cur.next
        print()

    def show_data_from_tail(self):
        if self.is_empty():
            print("List is empty")
            return
        cur = self.tail
        while cur:
            print(cur.data, end=" ")
            cur = cur.prev
        print()


if __name__ == "__main__":
    my_list = DoublyLinkedList(NodeBi(1))
    my_list.show_data()  # 1

    my_list.add_data(2)
    my_list.add_data(3)
    my_list.add_data(4)
    my_list.add_data(5)
    my_list.show_data()  # 1 2 3 4 5
    my_list.show_data_from_tail()  # 5 4 3 2 1

    my_list.add_data(100, 1)
    my_list.add_data(200, 2)
    my_list.add_data(300, 3)
    my_list.add_data(400, 4)
    my_list.add_data(500, 5)
    my_list.show_data()  # 100 1 200 2 300 3 400 4 500 5
    my_list.show_data_from_tail()  # 5 500 4 400 3 300 2 200 1 100

    my_list.remove_data(300)
    my_list.remove_data(100)
    my_list.remove_data(500)
    my_list.remove_data(200)
    my_list.remove_data(400)
    my_list.show_data()  # 1 2 3 4 5
    my_list.show_data_from_tail()  # 5 4 3 2 1

    my_list.remove_data(3)
    my_list.remove_data(1)
    my_list.remove_data(5)
    my_list.remove_data(2)
    my_list.remove_data(4)
    my_list.show_data()  # List is empty!
    my_list.show_data_from_tail()  # List is empty!
