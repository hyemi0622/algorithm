//송재현
//스택 사용 x
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    string num = to_string(n);
    for(char temp : num)
        answer.push_back(temp - '0');
    
    reverse(answer.begin(),answer.end());
    return answer;
}

//스택 사용 o
#include <vector>
#include <stack>
#include <cmath>
using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    stack<int> s;
    
    //자리수 구하기 
    long long temp = n;
    int digits = 0; 
    while(temp>0){
       temp /= 10;
        digits++;
    }
  
    //높은 자리수부터 스택에 넣기
    for(int i = digits-1;i>=0;i--){
        int max = pow(10,i);
        s.push(n/max);
        n %= max;
    }
    
    while(!s.empty()){
    answer.push_back(s.top());
    s.pop();
    }
    
    return answer;
}
