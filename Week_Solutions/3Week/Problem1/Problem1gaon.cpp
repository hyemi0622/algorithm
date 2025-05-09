#include <string>
#include <queue>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int k) {
    queue<int> q;
    for (int n: numbers) {
        q.push(n);
    }
    for (int i=0; i<k-1; i++) {
        int first = q.front();
        q.pop();
        q.push(first);
        int second = q.front();
        q.pop();
        q.push(second);
    }
    return q.front();
}
