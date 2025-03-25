def solution(arr, n):
    if len(arr) % 2== 1:
         return [arr[i] + n if i % 2 == 0 else arr[i] for i in range(len(arr))]
    else:
        return [arr[i]+ n if i % 2 ==1 else arr[i] for i in range(len(arr))]

print(solution([49, 12, 100, 276, 33], 27))
print(solution([444, 555, 666, 777], 100))