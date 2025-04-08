#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int solution(vector<int> numbers, int k) {
    deque<int> dq(numbers.begin(), numbers.end());


    for (int i = 1; i < k; i++) {
        int a = dq.front();
        dq.pop_front();
        dq.push_back(a);

        a = dq.front();
        dq.pop_front();
        dq.push_back(a);
    }

    return dq.front();
}


