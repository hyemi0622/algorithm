//이여빈

function solution(l, r) {
    let arr = Array.from({length:r-l+1}, (v,i)=>i+l)
    arr = arr.filter(v=> v.toString().replace(/[0,5]/g, '') === '')
    return arr.length === 0 ? [-1] : arr;
}
