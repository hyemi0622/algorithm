'''
def solution(arr):
    st = -1
    end = -1

    for i in range(len(arr)):
        if arr[i] == 2:
            if st == -1:
                st = i
            
            end = i
                

    if st == -1:
        return [-1]  # 2가 없는
    elif end == -1:
        return [2]  # 2가 하나만 
    else:
        return arr[start:end+1]  # 2부터 2까지 자르기
    
print(solution([1, 2, 1, 4, 5, 2, 9]))  
'''

import heapq

def solution(arr):
    heap = []

    # 배열에서 2의 인덱스를 모두 힙에 넣기
    for i in range(len(arr)):
        if arr[i] == 2:
            heapq.heappush(heap, i)
    
    if len(heap)==0:
        return [-1]  # 2가 하나도 없는 경우

    if len(heap) == 1:
        return [2]  # 2가 하나만 있는 경우

    start = heap[0]
    end = heap[-1]
    return arr[start:end+1]
