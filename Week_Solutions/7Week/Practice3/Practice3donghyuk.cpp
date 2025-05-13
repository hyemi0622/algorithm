#include <string>
#include <vector>
#include <deque>
using namespace std;
vector<int> solution(vector<int> arr) {
    deque<int> index;
    vector<int> result;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == 2)
            index.push_back(i);
    }
    if (index.empty()) {
        result.push_back(-1);
        return result;
    }
        

    for (int i=index.front(); i <= index.back(); i++) {
        result.push_back(arr[i]);
    }
    return result;
}
