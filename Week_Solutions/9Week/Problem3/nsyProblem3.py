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

#################################################################################################
def bubble(arr, n):
    for i in range(len(arr) -1):
        for j in range(len(arr) -1 -i):
            if ord(arr[j][n]) > ord(arr[j + 1][n]):
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
            elif ord(arr[j][n]) == ord(arr[j + 1][n]):
                for k in range(len(arr[j])):
                    if ord(arr[j][k]) > ord(arr[j + 1][k]):
                        arr[j], arr[j + 1] = arr[j + 1], arr[j]
    return arr

def solution(strings, n):
    answer = bubble(strings, n)
    return answer
