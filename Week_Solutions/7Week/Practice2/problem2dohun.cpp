#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include<algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    int count;
    sort(d.begin(), d.end());
    for (int i = 0; i < d.size(); i++)
    {
        answer += d[i];
        if (answer <= budget) {
            
            count++;
        }
        else {
            break;
        }
    }
    return count;
}
