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



# Practice2
# Palindrome 연결 리스트
# 추가 자료구조 없이 연결 리스트만으로 풀어보기 Practice1에서 만든 단일연결리스트 사용(내장 LinkedList말고)
# Palindrome: 앞으로 읽어도 뒤로 읽어도 같은 문자열
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

    def is_palindrome(self):
        //여기에 코드 작성
        return false

    


# Test code
linked_list1 = LinkedList()
linked_list1.add_data(1)
linked_list1.add_data(3)
linked_list1.add_data(5)
linked_list1.add_data(3)
linked_list1.add_data(1)
print(linked_list1.is_palindrome())  # Output: True

linked_list2 = LinkedList()
linked_list2.add_data(3)
linked_list2.add_data(5)
linked_list2.add_data(5)
linked_list2.add_data(3)
print(linked_list2.is_palindrome())  # Output: True

linked_list3 = LinkedList()
linked_list3.add_data(1)
linked_list3.add_data(3)
linked_list3.add_data(5)
linked_list3.add_data(1)
print(linked_list3.is_palindrome())  # Output: False


print("After removing duplicates:")
result.show_data()




# Practice3
# 연결 리스트 부분 뒤집기
# 주어진 연결 리스트에서 시작 위치부터 끝 위치 사이의 노드들을 뒤집으시오.

# 입력 예시)
# 입력 연결 리스트: 1, 2, 3, 4, 5
# 시작 위치: 2
# 끝 위치: 4
# (처음 위치는 1부터라고 가정)
# 결과 연결 리스트: 1, 4, 3, 2, 5
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


def reverse_list(linked_list, left, right):
    //여기에 코드 작성 
    return linked_list

# Test cases
linked_list1 = LinkedList()
linked_list1.add_data(1)
linked_list1.add_data(2)
linked_list1.add_data(3)
linked_list1.add_data(4)
linked_list1.add_data(5)
linked_list1.show_data()

linked_list1 = reverse_list(linked_list1, 2, 4)
linked_list1.show_data()

linked_list2 = LinkedList()
linked_list2.add_data(1)
linked_list2.add_data(2)
linked_list2.add_data(3)
linked_list2.add_data(4)
linked_list2.add_data(5)
linked_list2.add_data(6)
linked_list2.add_data(7)
linked_list2.show_data()

linked_list2 = reverse_list(linked_list2, 3, 5)
linked_list2.show_data()

