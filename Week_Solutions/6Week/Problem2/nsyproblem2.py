def solution(before, after):
    answer = 1
    for letter in before:
        if before.count(letter) == after.count(letter):
            continue
        else:
            answer = 0
    return answer
