class MinHeap:
    def __init__(self):
        self.heap = [0]  # 더미 값

    def insert(self, data):
        self.heap.append(data)
        cur = len(self.heap) - 1
        while cur > 1 and self.heap[cur // 2] > self.heap[cur]:
            self.heap[cur // 2], self.heap[cur] = self.heap[cur], self.heap[cur // 2]
            cur //= 2

    def delete(self):
        if len(self.heap) == 1:
            print("Heap is empty!")
            return None
        target = self.heap[1]
        self.heap[1] = self.heap[-1]
        self.heap.pop()

        cur = 1
        while True:
            left_idx = cur * 2
            right_idx = cur * 2 + 1
            target_idx = -1

            if right_idx < len(self.heap):
                target_idx = left_idx if self.heap[left_idx] < self.heap[right_idx] else right_idx
            elif left_idx < len(self.heap):
                target_idx = left_idx
            else:
                break

            if self.heap[cur] < self.heap[target_idx]:
                break
            else:
                self.heap[cur], self.heap[target_idx] = self.heap[target_idx], self.heap[cur]
                cur = target_idx
        return target

    def print_tree(self):
        print(" ".join(map(str, self.heap[1:])))

# Test
if __name__ == "__main__":
    min_heap = MinHeap()
    print("== 데이터 삽입 ==")
    min_heap.insert(30)
    min_heap.insert(40)
    min_heap.insert(10)
    min_heap.print_tree()
    min_heap.insert(50)
    min_heap.insert(60)
    min_heap.insert(70)
    min_heap.print_tree()
    min_heap.insert(20)
    min_heap.print_tree()
    min_heap.insert(30)
    min_heap.print_tree()

    print("\n== 데이터 삭제 ==")
    print("삭제:", min_heap.delete())
    min_heap.print_tree()
    print("삭제:", min_heap.delete())
    min_heap.print_tree()
    print("삭제:", min_heap.delete())
    min_heap.print_tree()
