#include <string>
#include <vector>
#include<queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> pro=progresses;
    vector<int> spe = speeds;
    queue<int> q;
    
    vector <int> result;
    for (int i = 0; i < pro.size(); i++) {
        int lastamount = 100 - pro[i];
        q.push( lastamount / spe[i]);
       
    }
    while (!q.empty()) {
        int day = q.front();
        q.pop();
        int count=0;
        count++;
        while (!q.empty() && q.front() <= day) {
            q.pop();
            count++;
        }
        result.push_back(count);
    }
    
    return result;
}
