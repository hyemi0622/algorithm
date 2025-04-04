# Practice1
# 단방향 연결 리스트에서 중복 데이터를 찾아 삭제하세요.

# 입출력 예시)
# 입력 연결 리스트: 1, 3, 3, 1, 4, 2, 4, 2
# 결과 연결 리스트: 1, 3, 4, 2
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def add_data(self, data):
        if not self.head:
            self.head = Node(data)
        else:
            cur = self.head
            while cur.next:
                cur = cur.next
            cur.next = Node(data)

    def find_data(self, data):
        cur = self.head
        while cur:
            if cur.data == data:
                return True
            cur = cur.next
        return False

    def show_data(self):
        cur = self.head
        while cur:
            print(cur.data, end=" ")
            cur = cur.next
        print()


def remove_dup(list_before):
    #여기에 코드 작성
    return null


# Test code
linked_list = LinkedList()
linked_list.add_data(1)
linked_list.add_data(3)
linked_list.add_data(3)
linked_list.add_data(1)
linked_list.add_data(4)
linked_list.add_data(2)
linked_list.add_data(4)
linked_list.add_data(2)

print("Before removing duplicates:")
linked_list.show_data()

result = remove_dup(linked_list)

print("After removing duplicates:")
result.show_data()
