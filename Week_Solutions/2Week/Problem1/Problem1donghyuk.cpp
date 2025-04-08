#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    stack<int> s;
    stack<int> temp;
    for (int num : arr) {
        if (s.empty() || s.top() != num) {
            s.push(num);
        }
    }
    while (!s.empty()) {
        temp.push(s.top());
        s.pop();
    }
    while(!temp.empty()){
        answer.push_back(temp.top());
        temp.pop();
    }
    return answer;
}
