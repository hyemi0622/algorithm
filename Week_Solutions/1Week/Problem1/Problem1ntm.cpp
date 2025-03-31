#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int n) {
    vector<int> answer = arr;
    int size = arr.size();
    
    if (size % 2 != 0) {
        for (int i = 0; i < size; i += 2) {
            answer[i] += n;
        }
    } else {
        for (int i = 1; i < size; i += 2) {
            answer[i] += n;
        }
    }
    
    return answer;
}
