//송재현
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int x : scoville)
        pq.push(x);
    while(!pq.empty() && pq.top() < K){
        if(pq.size()<2)return -1;
        int first = pq.top();pq.pop();
        int second = pq.top();pq.pop();
        int new_food = first + (second * 2);
        pq.push(new_food);
        answer++;
    }
    return answer;
}
