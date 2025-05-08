//송재현
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string before, string after) {
    bool answer = 0;
    sort(before.begin(),before.end());
    sort(after.begin(),after.end());
    answer = before == after ? 1:0;
    return answer;
}
