// 비선형 자료구조 - 우선순위 큐
// 연결 리스트를 이용한 우선순위 큐
#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

void enqueue(list<int>& lst, int data) {
    auto it = lst.begin();
    while (it != lst.end() && *it <= data) {
        ++it;
    }
    lst.insert(it, data);
}

int dequeue(list<int>& lst) {
    if (lst.empty()) return -1; // 빈 경우 예외 처리
    int data = lst.front();
    lst.pop_front();
    return data;
}

int main() {
    // 연결 리스트를 이용한 우선순위 큐
    cout << "== 연결리스트 방식의 우선순위 큐 ==" << endl;
    list<int> pqList;
    enqueue(pqList, 5);
    enqueue(pqList, 7);
    enqueue(pqList, 3);
    enqueue(pqList, 1);
    enqueue(pqList, 9);

    for (int val : pqList) {
        cout << val << " ";
    }
    cout << endl;

    cout << dequeue(pqList) << endl;
    cout << dequeue(pqList) << endl;

    for (int val : pqList) {
        cout << val << " ";
    }
    cout << endl << endl;

    // C++ 기본 priority_queue 사용
    cout << "== C++ 기본 우선순위 큐 ==" << endl;

    // 기본: 최대 힙 (내림차순)
    priority_queue<int> pq;
    pq.push(5);
    pq.push(7);
    pq.push(3);
    pq.push(1);
    pq.push(9);

    // 큐 복사해서 출력
    priority_queue<int> pqCopy = pq;
    while (!pqCopy.empty()) {
        cout << pqCopy.top() << " ";
        pqCopy.pop();
    }
    cout << endl;

    // 최소 힙 (오름차순)
    priority_queue<int, vector<int>, greater<int>> pq2;
    pq2.push(5);
    pq2.push(7);
    pq2.push(3);
    pq2.push(1);
    pq2.push(9);

    while (!pq2.empty()) {
        cout << pq2.top() << " ";
        pq2.pop();
    }
    cout << endl;

    return 0;
}
