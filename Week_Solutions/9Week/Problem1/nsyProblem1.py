def insertion(arr):
    for i in range(1, len(arr)):
        for j in range(i, 0, -1):
            if arr[j] > arr[j -1]:
                arr[j], arr[j -1] = arr[j -1], arr[j]
    return arr

def solution(n):
    n = list(str(n))
    answer = insertion(n)
    return int("".join(answer))
