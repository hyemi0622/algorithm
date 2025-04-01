class Stack:
    def __init__(self):
        self.arr = []
    def empty(self):
        return len(self.arr) == 0
    def push(self, data):
        self.arr.append(data)
    def pop(self):
        if self.empty():
            return None
        return self.arr.pop()
    def peek(self):
        if self.empty():
            return None
        return self.arr[-1]
    def parentheses(self, data):
        if self.empty() == True:
            self.arr.append(data)
        elif self.peek() != data:
            if data == '(':
                self.arr.append(data)
            else:
                self.arr.pop()
        else:
            self.arr.append(data)
def solution(s):
    stacks = Stack()
    for i in s:
        stacks.parentheses(i)
    return stacks.arr == []
