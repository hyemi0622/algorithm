class MyDeque2:
    def __init__(self, size):
        self.size = size + 1
        self.arr = [0] * self.size
        self.front = 0
        self.rear = 0

    def is_empty(self):
        return self.rear == self.front

    def is_full(self):
        return (self.rear + 1) % self.size == self.front

    def add_first(self, data):
        if self.is_full():
            print("Deque is full!")
            return
        self.front = (self.front - 1 + self.size) % self.size
        self.arr[self.front] = data

    def add_last(self, data):
        if self.is_full():
            print("Deque is full!")
            return
        self.arr[self.rear] = data
        self.rear = (self.rear + 1) % self.size

    def remove_first(self):
        if self.is_empty():
            print("Deque is empty!")
            return -1
        data = self.arr[self.front]
        self.front = (self.front + 1) % self.size
        return data

    def remove_last(self):
        if self.is_empty():
            print("Deque is empty!")
            return -1
        self.rear = (self.rear - 1 + self.size) % self.size
        return self.arr[self.rear]

    def print_deque(self):
        if self.is_empty():
            print("Deque is empty!")
            return
        i = self.front
        while i != self.rear:
            print(self.arr[i], end=' ')
            i = (i + 1) % self.size
        print()

if __name__ == "__main__":
    my_deque = MyDeque2(5)
    
    my_deque.add_first(1)
    my_deque.add_first(2)
    my_deque.add_first(3)
    my_deque.print_deque()  # 3 2 1

    my_deque.add_last(10)
    my_deque.add_last(20)
    my_deque.add_last(30)  # Deque is full!
    my_deque.print_deque()  # 3 2 1 10 20

    print(my_deque.remove_first())  # 3
    my_deque.print_deque()  # 2 1 10 20

    print(my_deque.remove_last())  # 20
    my_deque.print_deque()  # 2 1 10

    print(my_deque.remove_last())  # 10
    print(my_deque.remove_last())  # 1
    print(my_deque.remove_last())  # 2
    print(my_deque.remove_last())  # Deque is empty!
