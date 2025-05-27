"""switch=0.5 오름차순 / switch=-0.5 내림차순
4*0.5{=2} > 2*0.5{=1} True
4*(-0.5){=-2} > 2*(-0.5){=-1} False"""
def bubble(arr, switch=True):
    switch -= 0.5
# i: 0 -> -2 / j: i -> -1 / i, j 비교
    for i in range(len(arr) -1):
        for j in range(len(arr) -i -1):
            if arr[j]*switch > arr[j + 1]*switch:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
    return arr

def insertion(arr, switch=True):
    switch -= 0.5
# i: 1 -> -1 / j: i -> 1 / j, i 비교
    for i in range(1, len(arr)):
        for j in range(i, 0, -1):
            if arr[j]*switch < arr[j-1]*switch:
                arr[j], arr[j -1] = arr[j -1], arr[j]
            else:
                break
    return arr

def selection(arr, switch=True):
    switch -= 0.5
# i: 0 -> -2 / j: i + 1 -> -1 / i, j 비교 
    for i in range(len(arr) -1):
        midx = i
        for j in range(i + 1, len(arr)):
            if arr[j]*switch < arr[midx]*switch:
                midx = j
        arr[i], arr[midx] = arr[midx], arr[i]
    return arr
