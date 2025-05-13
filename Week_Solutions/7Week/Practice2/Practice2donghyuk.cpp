#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> d, int budget) {
    priority_queue<int,vector<int>,greater<int>> d1;
    for (int i = 0; i < d.size(); i++ )
        d1.push(d[i]);
    int sum = 0;
    int answer = 0;
    for (int i = 0; i < d.size(); i++) {
        sum += d1.top();
        d1.pop();
        if (budget < sum)
            return answer;
        answer++;
    }
}
