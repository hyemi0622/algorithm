def solution(emergency):
    l = len(emergency)
    answer = [0]*l
    for i in range(1, l+1):
        idx = emergency.index(max(emergency))
        answer[idx] = i
        emergency[idx] = 0
    return answer
