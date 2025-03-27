class Node:
    def __init__(self, data, next=None):
        self.data = data
        self.next = next

class LinkedList:
    def __init__(self, node=None):
        self.head = node

    # 연결 리스트가 비어있는지 확인
    def is_empty(self):
        return self.head is None

    # 연결 리스트의 맨 뒤에 데이터 추가
    def add_data(self, data):
        if self.head is None:
            self.head = Node(data)
        else:
            cur = self.head
            while cur.next:
                cur = cur.next
            cur.next = Node(data)

    # 연결 리스트의 맨 뒤의 데이터 삭제
    def remove_data(self):
        if self.is_empty():
            print("List is empty")
            return

        cur = self.head
        prev = None
        
        while cur.next:
            prev = cur
            cur = cur.next
        
        if prev is None:
            self.head = None
        else:
            prev.next = None

    # 연결 리스트에서 데이터 찾기
    def find_data(self, data):
        if self.is_empty():
            print("List is empty")
            return

        cur = self.head
        while cur:
            if cur.data == data:
                print("Data exist!")
                return
            cur = cur.next
        print("Data not found!")

    # 연결 리스트의 모든 데이터 출력
    def show_data(self):
        if self.is_empty():
            print("List is empty!")
            return

        cur = self.head
        while cur:
            print(cur.data, end=" ")
            cur = cur.next
        print()

# Test Code
my_list = LinkedList(Node(1))
my_list.show_data()  # 1

my_list.add_data(2)
my_list.add_data(3)
my_list.add_data(4)
my_list.add_data(5)
my_list.show_data()  # 1 2 3 4 5

my_list.find_data(3)  # Data exist!
my_list.find_data(100)  # Data not found!

my_list.remove_data()
my_list.remove_data()
my_list.remove_data()
my_list.show_data()  # 1 2

my_list.remove_data()
my_list.remove_data()
my_list.remove_data()  # List is empty
