//#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int first, last;
    first = find(arr.begin(), arr.end(), 2) - arr.begin();
    reverse(arr.begin(), arr.end());
    last = find(arr.begin(), arr.end(), 2) - arr.begin();
    last = arr.size() - last - 1;
    reverse(arr.begin(), arr.end());
    for (int i = first; i <= last; i++) {
        answer.push_back(arr[i]);
    }
    if (answer.empty())
        answer.push_back(-1);
    return answer;
}
