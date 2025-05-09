# Practice2
# 인접 행렬 그래프의 DFS, BFS

from collections import deque

class MyGraphMatrix2:
    def __init__(self, size):
        self.vertices = [None] * size
        self.adjMat = [[0] * size for _ in range(size)]
        self.elemCnt = 0

    def add_vertex(self, data):
        if self.elemCnt >= len(self.vertices):
            print("Graph is Full!!")
            return
        self.vertices[self.elemCnt] = data
        self.elemCnt += 1

    def add_edge(self, x, y):
        self.adjMat[x][y] = 1
        self.adjMat[y][x] = 1

    def print_adjacent_matrix(self):
        print("  ", end="")
        for v in self.vertices[:self.elemCnt]:
            print(v, end=" ")
        print()
        for i in range(self.elemCnt):
            print(self.vertices[i], end=" ")
            for j in range(self.elemCnt):
                print(self.adjMat[i][j], end=" ")
            print()

    def dfs(self, id):
        visited = [False] * self.elemCnt
        stack = [id]
        visited[id] = True

        while stack:
            cur = stack.pop()
            print(self.vertices[cur], end=" ")
            for i in reversed(range(self.elemCnt)):
                if self.adjMat[cur][i] == 1 and not visited[i]:
                    stack.append(i)
                    visited[i] = True
        print()

    def bfs(self, id):
        visited = [False] * self.elemCnt
        queue = deque([id])
        visited[id] = True

        while queue:
            cur = queue.popleft()
            print(self.vertices[cur], end=" ")
            for i in reversed(range(self.elemCnt)):
                if self.adjMat[cur][i] == 1 and not visited[i]:
                    queue.append(i)
                    visited[i] = True
        print()

# Test code
graph = MyGraphMatrix2(7)
graph.add_vertex('A')
graph.add_vertex('B')
graph.add_vertex('C')
graph.add_vertex('D')
graph.add_vertex('E')
graph.add_vertex('F')
graph.add_vertex('G')

graph.add_edge(0, 1)
graph.add_edge(0, 2)
graph.add_edge(0, 3)
graph.add_edge(1, 4)
graph.add_edge(2, 5)
graph.add_edge(3, 4)
graph.add_edge(3, 5)
graph.add_edge(4, 6)
graph.add_edge(5, 6)

graph.print_adjacent_matrix()
print()
graph.dfs(0)
graph.bfs(0)
