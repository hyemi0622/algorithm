# Q3##################################
def solution(l, r):
    answer = []
    blist = [5*int(bin(i)[2:]) for i in range(64)]
    for i in blist:
        if (l <= i) and (i <= r):
            answer += [i]
    if len(answer) == 0:
        answer = [-1]
    return answer
# Q3-1################################
def solution(l, r):
    answer = [5 * int(bin(i)[2:]) for i in range(64) if l <= 5 * int(bin(i)[2:]) <= r]
    return answer if answer else [-1]
# Q3-2################################
def solution(l, r):
    answer = []
    def f(c):
        cn = int(c)
        if cn > r:
            return
        if cn >= l:
            answer.append(cn)
        f(c + "0")
        f(c + "5")
    f("5")
    return sorted(answer) if answer else [-1]
# Q3-3################################
from collections import deque
def solution(l, r):
    answer = []
    q = deque(["5"])
    while q:
        c = q.popleft()
        cn = int(c)
        if cn > r:
            continue
        if cn >= l:
            answer.append(cn)
        q.append(c+"0")
        q.append(c+"5")
    return sorted(answer) if answer else [-1]
