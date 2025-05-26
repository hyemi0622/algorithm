def bubble_sort(arr):
    for i in range(1, len(arr) - 1):
        for j in range(len(arr) - i):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]

    for i in range(len(arr) - 1, 0, -1):
        for j in range(i):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]

def insertion_sort(arr):
    for i in range(1, len(arr)):
        for j in range(i, 0, -1):
            if arr[j] < arr[j - 1]:
                arr[j], arr[j - 1] = arr[j - 1], arr[j]
            else:
                break

def selection_sort(arr):
    for i in range(len(arr) - 1):
        min_idx = i
        for j in range(i + 1, len(arr)):
            if arr[j] < arr[min_idx]:
                min_idx = j
        arr[i], arr[min_idx] = arr[min_idx], arr[i]

    for i in range(len(arr) - 1, 0, -1):
        max_idx = i
        for j in range(i - 1, -1, -1):
            if arr[j] > arr[max_idx]:
                max_idx = j
        arr[i], arr[max_idx] = arr[max_idx], arr[i]

# Test code
arr = [3, 5, 2, 7, 1, 4]

temp = arr[:]
bubble_sort(temp)
print("버블 정렬:", temp)

temp = arr[:]
insertion_sort(temp)
print("삽입 정렬:", temp)

temp = arr[:]
selection_sort(temp)
print("선택 정렬:", temp)
