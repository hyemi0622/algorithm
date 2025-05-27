#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

long long solution(long long n) {
    vector<int> v;
    long long temp=n, result=0;
    int num = 0;
    if (n > 0)
    {   
        num = floor(log10(n));
    }
    for (int i = num; i >=0; i--)
    {
        int a = pow(10, i);
        temp = n % a;
        n = n / a;
        v.push_back(n);
        n = temp;
    }
    for (int i = 1; i < v.size(); i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (v[j] > v[j - 1])
                swap(v[j], v[j - 1]);
        }
    }
    for (int i =0;i<v.size();i++)
    {
        result += v[i] * pow(10, num);
        num--;
    }
    return result;
}
