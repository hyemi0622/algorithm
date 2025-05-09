from collections import Counter
def solution(s):
    count = Counter(s)
    unique_chars = [char for char in count if count[char] == 1]
    unique_chars.sort()
    return ''.join(unique_chars)
print(solution("abcabcadc")) 
print(solution("abdc"))       
print(solution("aabbcc"))
