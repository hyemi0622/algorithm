// Practice2
// 인접 행렬 그래프의 DFS, BFS
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class MyGraphMatrix2 {
    vector<char> vertices;
    vector<vector<int>> adjMat;
    int elemCnt;
    int size;

public:
    MyGraphMatrix2(int size) : size(size), elemCnt(0) {
        vertices.resize(size);
        adjMat.resize(size, vector<int>(size, 0));
    }

    void addVertex(char data) {
        if (elemCnt >= size) {
            cout << "Graph is Full!!" << endl;
            return;
        }
        vertices[elemCnt++] = data;
    }

    void addEdge(int x, int y) {
        adjMat[x][y] = 1;
        adjMat[y][x] = 1;
    }

    void printAdjacentMatrix() {
        cout << "  ";
        for (int i = 0; i < elemCnt; i++) {
            cout << vertices[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < elemCnt; i++) {
            cout << vertices[i] << " ";
            for (int j = 0; j < elemCnt; j++) {
                cout << adjMat[i][j] << " ";
            }
            cout << endl;
        }
    }

    void dfs(int id) {
        vector<bool> visited(elemCnt, false);
        stack<int> stk;
        stk.push(id);
        visited[id] = true;

        while (!stk.empty()) {
            int cur = stk.top();
            stk.pop();
            cout << vertices[cur] << " ";

            for (int i = elemCnt - 1; i >= 0; i--) {
                if (adjMat[cur][i] == 1 && !visited[i]) {
                    stk.push(i);
                    visited[i] = true;
                }
            }
        }
        cout << endl;
    }

    void bfs(int id) {
        vector<bool> visited(elemCnt, false);
        queue<int> q;
        q.push(id);
        visited[id] = true;

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            cout << vertices[cur] << " ";

            for (int i = elemCnt - 1; i >= 0; i--) {
                if (adjMat[cur][i] == 1 && !visited[i]) {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
        cout << endl;
    }
};

int main() {
    MyGraphMatrix2 graph(7);
    graph.addVertex('A');
    graph.addVertex('B');
    graph.addVertex('C');
    graph.addVertex('D');
    graph.addVertex('E');
    graph.addVertex('F');
    graph.addVertex('G');

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(0, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 5);
    graph.addEdge(3, 4);
    graph.addEdge(3, 5);
    graph.addEdge(4, 6);
    graph.addEdge(5, 6);

    graph.printAdjacentMatrix();
    cout << endl;
    graph.dfs(0);
    graph.bfs(0);
}
