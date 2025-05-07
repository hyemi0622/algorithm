# Practice1
# 인접 리스트를 이용한 그래프 구현
class Node:
    def __init__(self, id, next=None):
        self.id = id
        self.next = next

class MyGraphList:
    def __init__(self, size):
        self.vertices = [None] * size
        self.adjList = [None] * size
        self.elemCnt = 0
        self.size = size

    def is_full(self):
        return self.elemCnt == self.size

    def add_vertex(self, data):
        if self.is_full():
            print("Graph is Full!!")
            return
        self.vertices[self.elemCnt] = data
        self.elemCnt += 1

    def add_edge(self, x, y):
        self.adjList[x] = Node(y, self.adjList[x])
        self.adjList[y] = Node(x, self.adjList[y])

    def add_directed_edge(self, x, y):
        self.adjList[x] = Node(y, self.adjList[x])

    def print_adjacent_list(self):
        for i in range(self.elemCnt):
            print(f"{self.vertices[i]}: ", end="")
            cur = self.adjList[i]
            while cur:
                print(self.vertices[cur.id], end=" ")
                cur = cur.next
            print()

# Test code
graph = MyGraphList(4)
graph.add_vertex('A')
graph.add_vertex('B')
graph.add_vertex('C')
graph.add_vertex('D')

graph.add_edge(0, 1)
graph.add_edge(0, 2)
graph.add_edge(1, 2)
graph.add_edge(1, 3)
graph.add_edge(2, 3)
graph.print_adjacent_list()
