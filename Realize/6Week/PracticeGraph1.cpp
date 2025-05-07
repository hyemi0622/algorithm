#include <iostream>
#include <vector>

using namespace std;

class MyGraphMatrix {
private:
    vector<char> vertices;
    vector<vector<int>> adjMat;
    int elemCnt;
    int size;

public:
    MyGraphMatrix(int size) : size(size), elemCnt(0) {
        vertices.resize(size);
        adjMat.resize(size, vector<int>(size, 0));
    }

    bool isFull() const {
        return elemCnt == size;
    }

    void addVertex(char data) {
        if (isFull()) {
            cout << "Graph is Full!!" << endl;
            return;
        }
        vertices[elemCnt++] = data;
    }

    void addEdge(int x, int y) {
        adjMat[x][y] = 1;
        adjMat[y][x] = 1;
    }

    void addDirectedEdge(int x, int y) {
        adjMat[x][y] = 1;
    }

    void deleteEdge(int x, int y) {
        adjMat[x][y] = 0;
        adjMat[y][x] = 0;
    }

    void deleteDirectedEdge(int x, int y) {
        adjMat[x][y] = 0;
    }

    void printAdjacentMatrix() const {
        cout << "  ";
        for (int i = 0; i < elemCnt; ++i) {
            cout << vertices[i] << " ";
        }
        cout << endl;

        for (int i = 0; i < elemCnt; ++i) {
            cout << vertices[i] << " ";
            for (int j = 0; j < elemCnt; ++j) {
                cout << adjMat[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    MyGraphMatrix graph(4);
    graph.addVertex('A');
    graph.addVertex('B');
    graph.addVertex('C');
    graph.addVertex('D');

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);
    graph.printAdjacentMatrix();

    return 0;
}
