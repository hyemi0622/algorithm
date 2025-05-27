def selection(arr):
    for i in range(len(arr) - 1):
        midx = i
        for j in range(i + 1, len(arr)):
            if arr[j] < arr[midx]:
                midx = j
        arr[i], arr[midx] = arr[midx], arr[i]
    return arr

def solution(array, commands):
    answer = []
    for command in commands:
        i, j, k = command
        cache = array[i -1 : j]
        cache = selection(cache)
        answer.append(cache[k -1])
    return answer
