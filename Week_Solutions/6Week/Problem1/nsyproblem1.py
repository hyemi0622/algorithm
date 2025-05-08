def solution(s):
    letters = ''
    for letter in s:
        if s.count(letter) == 1:
            letters += letter
    answer = ''.join(sorted(letters))
    return answer
