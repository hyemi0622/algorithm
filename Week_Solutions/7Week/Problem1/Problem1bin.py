'''
def solution(absol, signs):
    sum1 = 0
    for i in range(len(absol)):
        if signs[i]:
            sum1 += absol[i]
        else:
            sum1 -= absol[i]
    return sum1

print(solution([4, 7, 12], [True, False, True]))
'''


import heapq

def solution(a, signs):
    heap = []
    for i in range(len(a)):
        value = a[i] if signs[i] else -a[i] 
        heapq.heappush(heap, value)  # 최소 힙에 삽입

    sum1 = 0
    while heap:
        sum1 += heapq.heappop(heap)  # 가장 작은 값부터 꺼내 더함

    return sum1

print(solution([4, 7, 12], [True, False, True]))
