#include<string>
#include <iostream>
#include<stack>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> a;
    for(char c:s){
        if(c=='(')
            a.push(c);
        else if(c==')'){
            if(a.empty())
                return false;
            a.pop();
        }
    }
    if(a.empty())
        return answer;
    return false;
}
