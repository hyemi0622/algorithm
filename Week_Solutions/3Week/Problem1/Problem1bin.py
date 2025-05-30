

def solution(num, k):
    a =0
    # 공을 (k-1)번 던진다
    for _ in range(k - 1):
        # 오른쪽으로 한 명 건너뛰므로 +2, 배열 범위를            넘을 수 있으므로 % 연산으로 원형 순환
        a = (a + 2) % len(num)

    return num[a]


print(solution([1, 2, 3, 4, 5, 6], 5))
#(공 던짐 순서: 1 → 3 → 5 → 1 → 3)
print(solution([1, 2, 3], 3))
#(공 던짐 순서: 1 → 3 → 2)
print(solution([1, 2, 3, 4], 2))
#(공 던짐 순서: 1 → 3)
