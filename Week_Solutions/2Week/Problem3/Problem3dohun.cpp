#include <string>
#include<list>
#include <vector>
#include<iostream>

using namespace std;

vector<int> solution(long long n) {
    list <int> a1;
    while (n > 0)
    {
        a1.push_back(n % 10);
        n /= 10;
    }
    
    vector<int> a2;
    for (auto i : a1)
    {
        a2.push_back(i);
    }

    return a2;
    
}
