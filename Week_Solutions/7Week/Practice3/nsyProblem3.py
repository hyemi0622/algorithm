def solution(arr):
    if 2 not in arr:
        return [-1]
    
    f = arr.index(2)
    l = len(arr) - arr[::-1].index(2)
    return arr[f:l]
