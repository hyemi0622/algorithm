//이여빈

function solution(numbers, direction) {
    
    if(direction === "left"){
        const temp = numbers.shift()
        numbers.push(temp)
    }else if(direction === "right"){
        const temp = numbers.pop()
        numbers.unshift(temp)
    }
    
    return numbers;
}
