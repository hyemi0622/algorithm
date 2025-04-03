//송재현

#include <vector>
using namespace std;

vector<int> solution(vector<int> arr, int n) {
    int size = arr.size();

    for (int i = 0; i < size; i++)
        if (i % 2 != size % 2) arr[i] += n;

    return arr; 
}
