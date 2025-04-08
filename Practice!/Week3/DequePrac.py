# Practice1
# 데이터 재정렬
# D_0 -> D_1 -> ... -> D_n-1 -> D_n 순으로 되어 있는 데이터를
# D_0 -> D_n -> D_1 -> D_n-1 -> ... 순이 되도록 재정렬 하시오.

# 입력 예시)
# 입력 데이터: 1 -> 2 -> 3 -> 4 -> 5
# 출력 데이터: 1 -> 5 -> 2 -> 4 -> 3
from collections import deque

def reorderData(arr):
    dq = deque(arr) # 배열의 모든 요소를 덱에 추가
    # 여기에 코드 작성
   

# Test code
reorderData([1, 2, 3, 4, 5]) # 출력: "1 -> 5 -> 2 -> 4 -> 3"
reorderData([1, 2, 3, 4, 5, 6, 7]) # 출력: "1 -> 7 -> 2 -> 6 -> 3 -> 5 -> 4"




# Practice2
# Palindrome 찾기
# Palindrome 이면 true, 아니면 false 를 반환하세요.
# Palindrome: 앞으로 읽어도 거꾸로 읽어도 같은 문자열

# 입출력 예시)
# 입력: a
# 결과: true

# 입력: madam
# 결과: true

# 입력: abab
# 결과: false
from collections import deque

def check_palindrome(s):
    # 여기에 코드 작성
    return False  # Placeholder

# Test code
print(check_palindrome("a"))       # True
print(check_palindrome("aba"))     # True
print(check_palindrome("abba"))    # True
print(check_palindrome("abab"))    # False
print(check_palindrome("abcba"))   # True
print(check_palindrome("abccba"))  # True
print(check_palindrome("madam"))   # True



# Practice3
# 데크 변형
# 기본 데크 구조에서 중간에 데이터를 추가하는 기능을 구현하세요.
# 단, 추가적인 자료구조 생성하지 말고 구현

# 입력 예시)
# 초기 데크 상태 (size: 5)
# -> 1, 2, 3, 4
# 중간 입력: 10
# 결과 데크
# -> 1, 2, 10, 3, 4
class MyDeque:
    def __init__(self, size):
        self.arr = [None] * (size + 1)  # Deque with size+1 to handle circular structure
        self.front = 0
        self.rear = 0

    def is_empty(self):
        return self.front == self.rear

    def is_full(self):
        return (self.rear + 1) % len(self.arr) == self.front

    def add_first(self, data):
        if self.is_full():
            print("Deque is full!")
            return
        self.front = (self.front - 1 + len(self.arr)) % len(self.arr)
        self.arr[self.front] = data

    def add_last(self, data):
        if self.is_full():
            print("Deque is full!")
            return
        self.rear = (self.rear + 1) % len(self.arr)
        self.arr[self.rear] = data

    def add_middle(self, data):
        //여기에 코드 작성

    def remove_first(self):
        if self.is_empty():
            print("Deque is empty!")
            return None
        self.front = (self.front + 1) % len(self.arr)
        return self.arr[self.front]

    def remove_last(self):
        if self.is_empty():
            print("Deque is empty!")
            return None
        data = self.arr[self.rear]
        self.rear = (self.rear - 1 + len(self.arr)) % len(self.arr)
        return data

    def print_deque(self):
        start = (self.front + 1) % len(self.arr)
        end = (self.rear + 1) % len(self.arr)

        while start != end:
            print(self.arr[start], end=" ")
            start = (start + 1) % len(self.arr)
        print()

# Test code
myDeque1 = MyDeque(5)
myDeque1.add_last(1)
myDeque1.add_last(2)
myDeque1.add_last(3)
myDeque1.add_last(4)
myDeque1.print_deque()

myDeque1.add_middle(10)
myDeque1.print_deque()

myDeque2 = MyDeque(5)
myDeque2.add_last(10)
myDeque2.add_last(10)
myDeque2.add_last(10)
myDeque2.add_last(10)
myDeque2.add_last(10)
myDeque2.remove_first()
myDeque2.remove_first()
myDeque2.remove_first()
myDeque2.remove_first()
myDeque2.add_last(11)
myDeque2.add_last(12)
myDeque2.add_last(13)
myDeque2.print_deque()

myDeque2.add_middle(100)
myDeque2.print_deque()



# Practice4
# 데크 리사이즈
# 기본 데크 구조에서 데크 공간이 full 일 때 데이터를 추가하는 경우,
# 데크 공간을 2배 씩 늘려주는 코드를 작성하세요.
class MyDeque2:
    def __init__(self, size):
        self.arr = [None] * (size + 1)  # Deque with size+1 to handle circular structure
        self.front = 0
        self.rear = 0

    def is_empty(self):
        return self.front == self.rear

    def is_full(self):
        return (self.rear + 1) % len(self.arr) == self.front

    def increase_size(self):
        #여기에 코드 작성

    def add_first(self, data):
        if self.is_full():
            print("Deque is full!")
            return
        self.arr[self.front] = data
        self.front = (self.front - 1 + len(self.arr)) % len(self.arr)

    def add_last(self, data):
        if self.is_full():
            print("Deque is full!")
            return
        self.rear = (self.rear + 1) % len(self.arr)
        self.arr[self.rear] = data

    def remove_first(self):
        if self.is_empty():
            print("Deque is empty!")
            return None
        self.front = (self.front + 1) % len(self.arr)
        return self.arr[self.front]

    def remove_last(self):
        if self.is_empty():
            print("Deque is empty!")
            return None
        data = self.arr[self.rear]
        self.rear = (self.rear - 1 + len(self.arr)) % len(self.arr)
        return data

    def print_deque(self):
        start = (self.front + 1) % len(self.arr)
        end = (self.rear + 1) % len(self.arr)

        while start != end:
            print(self.arr[start], end=" ")
            start = (start + 1) % len(self.arr)
        print()


# Test code
myDeque = MyDeque2(5)

myDeque.add_last(1)
myDeque.add_last(2)
myDeque.add_last(3)
myDeque.add_last(4)
myDeque.add_last(5)
myDeque.print_deque()

myDeque.add_last(6)
myDeque.add_last(7)
myDeque.add_last(8)
myDeque.add_last(9)
myDeque.add_last(10)
myDeque.print_deque()

myDeque.remove_last()
myDeque.remove_last()
myDeque.add_first(100)
myDeque.add_first(200)
myDeque.print_deque()

myDeque.add_first(300)
myDeque.add_first(400)
myDeque.add_first(500)
myDeque.print_deque()
