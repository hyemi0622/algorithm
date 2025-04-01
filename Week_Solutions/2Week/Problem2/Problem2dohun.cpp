#include <string>
#include <stack>
#include <iostream>

using namespace std;

bool solution(string s)
{
    stack<char> s1;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            s1.push(s[i]);
        }
        else if (s[i] == ')')
        {
            if (s1.empty())
            {
                return false;
            }
            s1.pop();
        }


        return s1.empty();
    }
}
