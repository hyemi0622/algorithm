#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int n) {
    for (int i = 0; i < arr.size(); i++) {

        if (arr.size() % 2 == 1 && i % 2 == 0) {
            arr[i] += n;
        }

        else if (arr.size() % 2 == 0 && i % 2 == 1) {
            arr[i] += n;
        }
    }
    return arr;
}
