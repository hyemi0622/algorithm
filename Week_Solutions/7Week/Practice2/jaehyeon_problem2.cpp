//송재현

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> d, int budget) {
    sort(d.begin(),d.end());
    
    int count = 0;
    for(int i=0;i<d.size();i++)
    {
        if(budget >= d[i]){
            budget -= d[i];
            count++;
        }else
            break;
    }
    
    return count;
}
