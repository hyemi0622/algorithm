#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int solution(vector<int> scoville, int K) {
	priority_queue<int, vector<int>, greater<int>> q;
	int s1, s2, count=0;
	for (int i = 0; i < scoville.size(); i++)
		q.push(scoville[i]);
	if (q.empty())
		return count;
	while(q.top() < K)
	{
		s1 = q.top();
		q.pop();
		if (q.empty())
			return -1;
		s2 = q.top();
		q.pop();
		q.push(s1 + s2 * 2);
		count++;
	}
	return count;
}
