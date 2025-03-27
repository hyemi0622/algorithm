class MyStack:
    def __init__(self, size):
        self.arr = []
        self.capacity = size
    
    def is_empty(self):
        return len(self.arr) == 0
    
    def is_full(self):
        return len(self.arr) == self.capacity
    
    def push(self, data):
        if self.is_full():
            print("Stack is full!")
            return
        self.arr.append(data)
    
    def pop(self):
        if self.is_empty():
            print("Stack is empty!")
            return None
        return self.arr.pop()
    
    def peek(self):
        if self.is_empty():
            print("Stack is empty!")
            return None
        return self.arr[-1]
    
    def print_stack(self):
        print(" ".join(map(str, self.arr)))

# Test code
if __name__ == "__main__":
    my_stack = MyStack(5)
    print(my_stack.is_empty())  # True
    my_stack.push(1)
    my_stack.push(2)
    my_stack.push(3)
    my_stack.push(4)
    my_stack.push(5)
    my_stack.push(6)  # Stack is full!
    my_stack.print_stack()  # 1 2 3 4 5

    print(my_stack.peek())  # 5
    my_stack.print_stack()  # 1 2 3 4 5

    print(my_stack.pop())  # 5
    print(my_stack.pop())  # 4
    my_stack.print_stack()  # 1 2 3

    print(my_stack.pop())  # 3
    print(my_stack.pop())  # 2
    print(my_stack.pop())  # 1
    my_stack.print_stack()  # (empty output)
