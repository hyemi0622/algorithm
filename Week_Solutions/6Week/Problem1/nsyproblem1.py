def solution(s):
    letters = ''
    for letter in s:
        if s.count(letter) == 1:
            letters += letter
    answer = ''.join(sorted(letters))
    return answer

####################################################################
class letters:
    def __init__(self):
        self.count = 1
        self.dict = {}

    def incheck(self, letter):
        return letter in self.dict.keys
    
    def division(self, letter):
        if not self.incheck(letter):
            self.dict[letter] = 1
        else:
            self.dict[letter] += 1

def solution(s):
    solve = letters()
    answer = ''
    for i in s:
        solve.division(i)
    for i in solve.dict.keys():
        if solve.dict[i] == 1:
            answer + i

    answer = ''.join(sorted(answer))
    return answer
