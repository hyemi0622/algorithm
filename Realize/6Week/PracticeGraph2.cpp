// Practice1
// 인접 리스트를 이용한 그래프 구현

#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int id;
    Node* next;
    Node(int id, Node* next = nullptr) : id(id), next(next) {}
};

class MyGraphList {
    vector<char> vertices;
    vector<Node*> adjList;
    int elemCnt;
    int size;

public:
    MyGraphList(int size) : size(size), elemCnt(0) {
        vertices.resize(size);
        adjList.resize(size, nullptr);
    }

    bool isFull() {
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
        adjList[x] = new Node(y, adjList[x]);
        adjList[y] = new Node(x, adjList[y]);
    }

    void addDirectedEdge(int x, int y) {
        adjList[x] = new Node(y, adjList[x]);
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

int main() {
    MyGraphList graph(4);

    graph.addVertex('A');
    graph.addVertex('B');
    graph.addVertex('C');
    graph.addVertex('D');

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);
    graph.printAdjacentList();
}
