def solution(strings, n):
    for i in range(len(strings) -1):
        for j in range(len(strings) -1 -i):
            if strings[j][n] > strings[j + 1][n]:
                strings[j], strings[j + 1] = strings[j + 1], strings[j]
            elif strings[j][n] == strings[j + 1][n]:
                if strings[j] > strings[j + 1]:
                    strings[j], strings[j + 1] = strings[j + 1], strings[j]
    answer = strings
    return answer
