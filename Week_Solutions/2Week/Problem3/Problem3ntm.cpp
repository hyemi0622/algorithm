//남태민
#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    stack<int> sta;
    string str = to_string(n);
    for (char c : str) {
        sta.push(c - '0');
    }
    for (int i = 0; i < str.length(); i++) {
        answer.push_back(sta.top());
        sta.pop();
    }
return answer;
}
