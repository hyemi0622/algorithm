def solution(numbers, direction):
    if direction == "right":
        numbers = [numbers[-1]] + numbers[:-1]
        return numbers
    elif direction == "left":
        numbers = [numbers[1]] + numbers[2:] + [numbers[0]]
        return numbers
print(solution([1,2,3], "right"))
print(solution([4, 455, 6, 4, -1, 45, 6], "left"))
