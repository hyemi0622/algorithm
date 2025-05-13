def solution(d, budget):
    d.sort()  # 금액이 작은 부서부터 우선 지원
    total = 0
    count = 0

    for cost in d:
        if total + cost > budget:
            break
        total += cost
        count += 1

    return count
##############################################################################################
def solution(d, budget):
    answer = 0
    d.insert(0, 0)
    l = len(d)
    buy = [[0]*l for _ in range(l)]
    buy[0] = d
    for i in range(1, l):
        buy[i][0] = d[i]
    for i in range(1, l):
        print(d[i], buy)
        for j in range(1, l):
            if buy[i][j -1] + buy[i -1][j] <budget:
                buy[i][j] = buy[i][j -1] + buy[i -1][j]
                answer += 1
            else:
                buy[i][j] = max(buy[i][j -1], buy[i -1][j])

        print(buy)
    return answer
