//이여빈

function solution(s){
    let count = 0;
    s.split('').forEach(v=>{
        if(count < 0) return false;
        if(v === '(' ) count += 1
        else if( v === ')' ) count -= 1
    })
    return count === 0 ? true : false;
}
