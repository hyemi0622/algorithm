#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    int tmp = 0;
    sort(d.begin(), d.end());
    for (int i = 0; i < d.size(); i++) {
        tmp += d[i];
        if (tmp <= budget) {
            ++answer;
        }
        else
            break;
    }
    return answer;
}
