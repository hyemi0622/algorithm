// 비선형자료구조 - 힙
// Vector 로 최소 힙 구현
#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
private:
    vector<int> heap;

public:
    MinHeap() {
        heap.push_back(0); // 더미 값
    }

    void insert(int data) {
        heap.push_back(data);
        int cur = heap.size() - 1;
        while (cur > 1 && heap[cur / 2] > heap[cur]) {
            swap(heap[cur / 2], heap[cur]);
            cur /= 2;
        }
    }

    int deleteMin() {
        if (heap.size() == 1) {
            cout << "Heap is empty!" << endl;
            return -1;
        }

        int target = heap[1];
        heap[1] = heap[heap.size() - 1];
        heap.pop_back();

        int cur = 1;
        while (true) {
            int leftIdx = cur * 2;
            int rightIdx = cur * 2 + 1;
            int targetIdx = -1;

            if (rightIdx < heap.size()) {
                targetIdx = heap[leftIdx] < heap[rightIdx] ? leftIdx : rightIdx;
            } else if (leftIdx < heap.size()) {
                targetIdx = leftIdx;
            } else {
                break;
            }

            if (heap[cur] < heap[targetIdx]) {
                break;
            } else {
                swap(heap[cur], heap[targetIdx]);
                cur = targetIdx;
            }
        }
        return target;
    }

    void printTree() {
        for (int i = 1; i < heap.size(); i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MinHeap minHeap;
    cout << "== 데이터 삽입 ==" << endl;
    minHeap.insert(30);
    minHeap.insert(40);
    minHeap.insert(10);
    minHeap.printTree();
    minHeap.insert(50);
    minHeap.insert(60);
    minHeap.insert(70);
    minHeap.printTree();
    minHeap.insert(20);
    minHeap.printTree();
    minHeap.insert(30);
    minHeap.printTree();

    cout << endl << "== 데이터 삭제 ==" << endl;
    cout << "삭제: " << minHeap.deleteMin() << endl;
    minHeap.printTree();
    cout << "삭제: " << minHeap.deleteMin() << endl;
    minHeap.printTree();
    cout << "삭제: " << minHeap.deleteMin() << endl;
    minHeap.printTree();

    return 0;
}
