import heapq

def solution(d, budget):
    heapq.heapify(d)  # 최소 힙
    t = 0
    answer = 0

    while d: #힙이 빌 때까지 반복 
        min_1 = heapq.heappop(d) #가장 작은 힙 꺼내기
        if t + min_1 <= budget:
            t += min_1
            answer += 1
        else:
            break

    return answer

print(solution([1, 3, 2, 5, 4], 9))  
print(solution([2, 2, 3, 3], 10))   
