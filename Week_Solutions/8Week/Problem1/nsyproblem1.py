import heapq

def solution(scoville, K):
    heapq.heapify(scoville)
    answer = 0

    while len(scoville) >= 2 and scoville[0] < K:
        a = heapq.heappop(scoville)
        b = heapq.heappop(scoville)
        c = a + (b * 2)
        heapq.heappush(scoville, c)
        answer += 1
    return answer if scoville[0] >= K else -1
