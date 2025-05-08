def solution(before, after):
    answer = 1
    for letter in before:
        if before.count(letter) == after.count(letter):
            continue
        else:
            answer = 0
    return answer

######################################################################
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

def solution(before, after):
    bb = letters()
    ff = letters()
    for i in before:
        bb.division(i)
    for i in after:
        ff.division(i)
    return bb == ff
