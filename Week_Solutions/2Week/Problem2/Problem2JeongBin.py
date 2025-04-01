def solution(arr):
    stack = []  
    for num in arr:
        if not stack or stack[-1] != num:  # 스택이 비어있거나 최근 값과 다르면 추가
            stack.append(num)
    return stack  


print(solution([1, 1, 3, 3, 0, 1, 1]))  
