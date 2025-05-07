class MyGraphMatrix:
    def __init__(self, size):
        self.vertices = [None] * size
        self.adj_mat = [[0] * size for _ in range(size)]
        self.elem_cnt = 0
        self.size = size

    def is_full(self):
        return self.elem_cnt == self.size

    def add_vertex(self, data):
        if self.is_full():
            print("Graph is Full!!")
            return
        self.vertices[self.elem_cnt] = data
        self.elem_cnt += 1

    def add_edge(self, x, y):
        self.adj_mat[x][y] = 1
        self.adj_mat[y][x] = 1

    def add_directed_edge(self, x, y):
        self.adj_mat[x][y] = 1

    def delete_edge(self, x, y):
        self.adj_mat[x][y] = 0
        self.adj_mat[y][x] = 0

    def delete_directed_edge(self, x, y):
        self.adj_mat[x][y] = 0

    def print_adjacent_matrix(self):
        print("  ", end="")
        for i in range(self.elem_cnt):
            print(self.vertices[i], end=" ")
        print()

        for i in range(self.elem_cnt):
            print(self.vertices[i], end=" ")
            for j in range(self.elem_cnt):
                print(self.adj_mat[i][j], end=" ")
            print()

# Test
graph = MyGraphMatrix(4)
graph.add_vertex('A')
graph.add_vertex('B')
graph.add_vertex('C')
graph.add_vertex('D')

graph.add_edge(0, 1)
graph.add_edge(0, 2)
graph.add_edge(1, 2)
graph.add_edge(1, 3)
graph.add_edge(2, 3)
graph.print_adjacent_matrix()
