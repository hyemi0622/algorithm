// Practice3
// 인접 리스트 그래프의 DFS, BFS
#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

// Node class for adjacency list
class Node {
public:
    int id;
    Node* next;
    Node(int id, Node* next = nullptr) : id(id), next(next) {}
};

// MyGraphList base class
class MyGraphList {
public:
    vector<char> vertices;
    vector<Node*> adjList;
    int elemCnt;

    MyGraphList(int size) {
        adjList.resize(size, nullptr);
        elemCnt = 0;
    }

    void addVertex(char data) {
        vertices.push_back(data);
        elemCnt++;
    }

    void addEdge(int x, int y) {
        adjList[x] = new Node(y, adjList[x]);
        adjList[y] = new Node(x, adjList[y]);  // Undirected edge
    }

    void printAdjacentList() {
        for (int i = 0; i < elemCnt; i++) {
            cout << vertices[i] << ": ";
            Node* cur = adjList[i];
            while (cur != nullptr) {
                cout << vertices[cur->id] << " ";
                cur = cur->next;
            }
            cout << endl;
        }
    }
};

// MyGraphList2 class that extends MyGraphList and adds DFS and BFS
class MyGraphList2 : public MyGraphList {
public:
    MyGraphList2(int size) : MyGraphList(size) {}

    // Depth First Search (DFS)
    void dfs(int id) {
        vector<bool> visited(elemCnt, false);
        stack<int> stack;

        stack.push(id);
        visited[id] = true;

        while (!stack.empty()) {
            int curID = stack.top();
            stack.pop();
            cout << vertices[curID] << " ";

            Node* cur = adjList[curID];
            while (cur != nullptr) {
                if (!visited[cur->id]) {
                    stack.push(cur->id);
                    visited[cur->id] = true;
                }
                cur = cur->next;
            }
        }
        cout << endl;
    }

    // Breadth First Search (BFS)
    void bfs(int id) {
        vector<bool> visited(elemCnt, false);
        queue<int> q;

        q.push(id);
        visited[id] = true;

        while (!q.empty()) {
            int curID = q.front();
            q.pop();
            cout << vertices[curID] << " ";

            Node* cur = adjList[curID];
            while (cur != nullptr) {
                if (!visited[cur->id]) {
                    q.push(cur->id);
                    visited[cur->id] = true;
                }
                cur = cur->next;
            }
        }
        cout << endl;
    }
};

int main() {
    // Test code
    MyGraphList2 graph(7);
    graph.addVertex('A');  // 0
    graph.addVertex('B');  // 1
    graph.addVertex('C');  // 2
    graph.addVertex('D');  // 3
    graph.addVertex('E');  // 4
    graph.addVertex('F');  // 5
    graph.addVertex('G');  // 6

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(0, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 5);
    graph.addEdge(3, 4);
    graph.addEdge(3, 5);
    graph.addEdge(4, 6);
    graph.addEdge(5, 6);

    graph.printAdjacentList();

    cout << "DFS: ";
    graph.dfs(0);

    cout << "BFS: ";
    graph.bfs(0);

    return 0;
}
