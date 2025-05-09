def solution(b, a):
    return int(sorted(b) == sorted(a))

print(solution("olleh", "hello"))  
print(solution("apple", "papel"))  
print(solution("hello", "world"))
