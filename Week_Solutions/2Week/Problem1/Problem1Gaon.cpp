// 정가온
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    stack<int> s;
    
    s.push(arr[0]);
    
    for (int i=1; i<arr.size(); i++) {
        if(s.top()!=arr[i]) 
            s.push(arr[i]);
    }
    
    vector<int> answer(s.size());
    for (int i = s.size() - 1; i >= 0; i--) {
        answer[i] = s.top(); 
        s.pop();
    }
    
    return answer;
}
