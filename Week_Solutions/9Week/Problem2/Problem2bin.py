def solution(array, commands):
    result = []
    
    for command in commands:
        i, j, k = command
        sliced = array[i-1:j] 
        
        S = len(sliced)
        for a in range(1, S):
            for b in range(0, S - a):
                if sliced[b] > sliced[b + 1]:
                    sliced[b], sliced[b + 1] = sliced[b + 1], sliced[b]
        
        result.append(sliced[k-1])
    
    return result
