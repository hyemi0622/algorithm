//송재현

#include<string>
#include<stack>
#include <iostream>

using namespace std;

bool solution(string s)
{
    stack<char> a;
    bool answer = true;
    for(char c : s){
        if(c == '(')
            a.push(c);
        else if (c ==')'){
            if(a.empty())
                return false;
            a.pop();
        }
        else return false;
    }
    return a.empty();
}
