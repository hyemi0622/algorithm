# Practice3
# 인접 리스트 그래프의 DFS, BFS
class Node:
    def __init__(self, id, next_node=None):
        self.id = id
        self.next = next_node

class MyGraphList:
    def __init__(self, size):
        self.vertices = []
        self.adjList = [None] * size
        self.elemCnt = 0

    def addVertex(self, data):
        self.vertices.append(data)
        self.elemCnt += 1

    def addEdge(self, x, y):
        self.adjList[x] = Node(y, self.adjList[x])
        self.adjList[y] = Node(x, self.adjList[y])  # Undirected edge

    def printAdjacentList(self):
        for i in range(self.elemCnt):
            print(f"{self.vertices[i]}:", end=" ")
            cur = self.adjList[i]
            while cur:
                print(self.vertices[cur.id], end=" ")
                cur = cur.next
            print()

class MyGraphList2(MyGraphList):
    def __init__(self, size):
        super().__init__(size)

    def dfs(self, id):
        visited = [False] * self.elemCnt
        stack = [id]
        visited[id] = True

        while stack:
            curID = stack.pop()
            print(self.vertices[curID], end=" ")

            cur = self.adjList[curID]
            while cur:
                if not visited[cur.id]:
                    stack.append(cur.id)
                    visited[cur.id] = True
                cur = cur.next
        print()

    def bfs(self, id):
        visited = [False] * self.elemCnt
        queue = [id]
        visited[id] = True

        while queue:
            curID = queue.pop(0)
            print(self.vertices[curID], end=" ")

            cur = self.adjList[curID]
            while cur:
                if not visited[cur.id]:
                    queue.append(cur.id)
                    visited[cur.id] = True
                cur = cur.next
        print()

if __name__ == "__main__":
    graph = MyGraphList2(7)
    graph.addVertex('A')  # 0
    graph.addVertex('B')  # 1
    graph.addVertex('C')  # 2
    graph.addVertex('D')  # 3
    graph.addVertex('E')  # 4
    graph.addVertex('F')  # 5
    graph.addVertex('G')  # 6

    graph.addEdge(0, 1)
    graph.addEdge(0, 2)
    graph.addEdge(0, 3)
    graph.addEdge(1, 4)
    graph.addEdge(2, 5)
    graph.addEdge(3, 4)
    graph.addEdge(3, 5)
    graph.addEdge(4, 6)
    graph.addEdge(5, 6)

    graph.printAdjacentList()

    print("DFS:", end=" ")
    graph.dfs(0)

    print("BFS:", end=" ")
    graph.bfs(0)
