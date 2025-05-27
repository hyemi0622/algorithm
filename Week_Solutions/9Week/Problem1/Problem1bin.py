def solution(n):
	digits = list(str(n))
	S = len(digits)

	for i in range(1, S):
		for j in range(0, S - i ):
			if digits[j] < digits[j +1]:
				digits[j], digits[j+1] = digits[j+1], digits[j]
	return int(''.join(digits))
