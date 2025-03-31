def solution(l, r):
    list_1 = []
    for num in range(l, r + 1):
        a = set(str(num)) #num을 a에 저장
        if a.issubset({'0', '5'}):  #a에 5 0가 속하면 추가
            list_1.append(num)
    return list_1 if list_1 else [-1] #비어있다면 -1반환

print(solution(5, 555))
print(solution(10, 20))
