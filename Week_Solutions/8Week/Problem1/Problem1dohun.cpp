#include <string>
#include <vector>
#include<queue>
#include<functional>

using namespace std;

int solution(vector<int> scoville, int K) 
{
    int answer = 0;
    int sum = 0;
    priority_queue<int,vector<int>, greater<int>> q;
    for (int i = 0; i < scoville.size(); i++)
    {
        q.push(scoville[i]);
    }
    
    while (!q.empty() && sum < K) {
        int a = q.top(); 
        q.pop();
        int b = q.top();
        q.pop();

        sum = a + (b * 2);

        answer++;
    }
    
    
    
    return answer;
}
