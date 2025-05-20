#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    int answer = 0, temp = 0, smallest = 0, smaller = 0;
    while (pq.top() < K && pq.size() > 1)
    {
        smallest = pq.top();
        pq.pop();
        smaller = pq.top();
        pq.pop();
        temp = smallest + smaller * 2;
        pq.push(temp);
        answer++;
    }
    if (pq.top() < K)
        return -1;

    return answer;
}
