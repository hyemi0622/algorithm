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
    def show_data_from_tail(self):
        if self.is_empty():
            return
        cur = self.tail
        while cur:
            print(cur.data, end=" ")
            cur = cur.prev
        print()
def solution(n):
    link = DoubleLinkedList()
    
    answer = []
    return answer
