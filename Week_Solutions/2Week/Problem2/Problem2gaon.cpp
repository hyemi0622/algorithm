// 정가온
#include<string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    stack<char> c;
    for (int i=0; i<s.size(); i++) {
        if (s[i]=='(') {
            c.push(s[i]);
        }
        else if (s[i]==')'){
            if (c.empty())
                return false;
            c.pop();
        }
    }
    
    if (c.empty()) {
        return true;
    }
    else {
        return false;
    }
}
