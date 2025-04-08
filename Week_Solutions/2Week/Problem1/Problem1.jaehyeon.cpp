//송재현 
//스택 사용 
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr) 
{
    stack<int> s;
    for (int num : arr){
        if(s.empty() || s.top() != num)
            s.push(num);
    }
    vector<int> answer;
    while(!s.empty()){
        answer.push_back(s.top());
        s.pop();
    }
    
    reverse(answer.begin(),answer.end());
    return answer;
}

//스택 사용x , 배열만 사용

#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    answer.push_back(arr[0]);
    for(int i=1;i<arr.size();i++){
        if(arr[i]!=arr[i-1])
            answer.push_back(arr[i]);
    }

    return answer;
}
