#include<string>
#include <iostream>
#include <vector>

using namespace std;

bool solution(string s)
{
    vector<char> ch;
    for (char c : s) {
        if (c == '(')
            ch.push_back(c);
        else {
            if (ch.empty()) return false;
            ch.pop_back();
        }
    }
    return (ch.empty());
}
