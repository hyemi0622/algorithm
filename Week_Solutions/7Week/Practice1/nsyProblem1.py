def solution(absolutes, signs):
    n = len(absolutes)
    answer = 0
    for i in range(n):
        answer += 2*(signs[i]-0.5)*absolutes[i]
    return answer
