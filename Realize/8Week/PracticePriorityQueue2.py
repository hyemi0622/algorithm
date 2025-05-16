import heapq
# 나이 순으로 오름차순 또는 내림차순 출력
class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    # 오름차순: age가 적을수록 우선순위 높음
    # def __lt__(self, other):
    #     return self.age < other.age

    # 내림차순: age가 클수록 우선순위 높음
    def __lt__(self, other):
        return self.age > other.age

def solution(names, ages):
    pq = []
    for name, age in zip(names, ages):
        heapq.heappush(pq, Person(name, age))

    print("== 실제 출력 순서 ==")
    while pq:
        p = heapq.heappop(pq)
        print(f"{p.name}{p.age}")

names = ["A", "B", "C", "D", "E"]
ages = [30, 20, 45, 62, 35]

solution(names, ages)
