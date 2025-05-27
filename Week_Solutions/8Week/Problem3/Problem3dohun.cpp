#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> emergency) {
    vector<int> answer=emergency;
    priority_queue<int> pq;
    int num = 1;
    for (auto a : emergency) {
        pq.push(a);
    }
    while (!pq.empty()) {
        int a = pq.top();
        pq.pop();

        for (int i = 0; i < emergency.size(); i++) {
            if (emergency[i] == a) {
                answer[i] = num++; 
            }
        }
    }
    return answer;
}
