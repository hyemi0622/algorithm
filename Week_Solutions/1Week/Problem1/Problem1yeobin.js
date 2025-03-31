#이여빈

function solution(arr, n) {
    if(arr.length%2){
        arr = arr.map((v,i) => i%2?v:v+n)
    }else{
        arr = arr.map((v,i) => i%2?v+n:v)
    }
    return arr;
}
