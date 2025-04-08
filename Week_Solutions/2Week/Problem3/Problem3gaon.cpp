// 정가온
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(long long n) {
    stack<int> s;
    string strN = to_string(n);
    
    for (char c : strN) {
        s.push(c-'0');
    }
    
    vector<int> result;
    while(!s.empty()) {
        result.push_back(s.top());
        s.pop();
    }
    return result;
}
