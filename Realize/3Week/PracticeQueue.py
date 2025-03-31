class MyQueue2:
    def __init__(self, size):
        self.size = size + 1
        self.arr = [0] * self.size
        self.front = 0
        self.rear = 0

    def is_empty(self):
        return self.rear == self.front

    def is_full(self):
        return (self.rear + 1) % self.size == self.front

    def enqueue(self, data):
        if self.is_full():
            print("Queue is full!")
            return
        self.rear = (self.rear + 1) % self.size
        self.arr[self.rear] = data

    def dequeue(self):
        if self.is_empty():
            print("Queue is empty!")
            return None
        self.front = (self.front + 1) % self.size
        return self.arr[self.front]

    def print_queue(self):
        start = (self.front + 1) % self.size
        end = (self.rear + 1) % self.size
        i = start
        while i != end:
            print(self.arr[i], end=" ")
            i = (i + 1) % self.size
        print()

if __name__ == "__main__":
    myQueue = MyQueue2(5)
    myQueue.enqueue(1)
    myQueue.enqueue(2)
    myQueue.enqueue(3)
    myQueue.enqueue(4)
    myQueue.enqueue(5)
    myQueue.enqueue(6)  # Queue is full!

    myQueue.print_queue()  # 1 2 3 4 5

    print(myQueue.dequeue())  # 1
    myQueue.print_queue()  # 2 3 4 5
    
    print(myQueue.dequeue())  # 2
    myQueue.print_queue()  # 3 4 5

    myQueue.enqueue(6)
    myQueue.enqueue(7)
    myQueue.print_queue()  # 3 4 5 6 7

    print(myQueue.dequeue())  # 3
    print(myQueue.dequeue())  # 4
    print(myQueue.dequeue())  # 5
    myQueue.print_queue()  # 6 7
    print(myQueue.dequeue())  # 6
    print(myQueue.dequeue())  # 7
    myQueue.dequeue()  # Queue is empty!
