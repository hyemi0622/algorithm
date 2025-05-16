import heapq

def enqueue(lst, data):
    idx = 0
    while idx < len(lst) and lst[idx] <= data:
        idx += 1
    lst.insert(idx, data)

def dequeue(lst):
    if not lst:
        return None
    return lst.pop(0)

# 연결 리스트 방식의 우선순위 큐
print("== 연결리스트 방식의 우선순위 큐 ==")
pq_list = []
enqueue(pq_list, 5)
enqueue(pq_list, 7)
enqueue(pq_list, 3)
enqueue(pq_list, 1)
enqueue(pq_list, 9)
print(pq_list)

print(dequeue(pq_list))
print(dequeue(pq_list))
print(pq_list)
print()

# 파이썬 기본 heapq 사용
print("== 파이썬 기본 우선순위 큐 ==")
pq = []
heapq.heappush(pq, 5)
heapq.heappush(pq, 7)
heapq.heappush(pq, 3)
heapq.heappush(pq, 1)
heapq.heappush(pq, 9)
print(pq)

# 최대 힙 흉내내기: -부호 사용
pq2 = []
heapq.heappush(pq2, -5)
heapq.heappush(pq2, -7)
heapq.heappush(pq2, -3)
heapq.heappush(pq2, -1)
heapq.heappush(pq2, -9)
print([-x for x in pq2])  # 출력 시 부호 복구
