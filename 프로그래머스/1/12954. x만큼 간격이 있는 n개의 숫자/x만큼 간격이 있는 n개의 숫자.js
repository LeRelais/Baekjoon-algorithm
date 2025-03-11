function solution(x, n) {
    var answer = [];
    let tmp = x;
    for(let i = 0; i < n; i++){
        answer[i] = tmp;
        tmp += x;
    }
    return answer;
}