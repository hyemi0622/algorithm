import heapq
# 문자열 사전식 오름차순
class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    # 사전식 오름차순 (문자열 비교)
    def __lt__(self, other):
        return self.name < other.name

def solution(names, ages):
    pq = []
    for name, age in zip(names, ages):
        heapq.heappush(pq, Person(name, age))

    while pq:
        p = heapq.heappop(pq)
        print(f"{p.name} {p.age}")

names = ["A", "B", "C", "D", "E"]
ages = [30, 20, 45, 62, 35]

solution(names, ages)
