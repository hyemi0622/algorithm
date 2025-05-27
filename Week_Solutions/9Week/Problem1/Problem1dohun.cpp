#include <string>
#include <vector>

using namespace std;

void insertionSort(vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int index = i - 1;
        while (index >= 0 && arr[index] < key) {
            arr[index + 1] = arr[index];
            index--;
        }
        arr[index + 1] = key;
    }
}
long long solution(long long n) {
    vector<int> v;
    while (n > 0) {
        v.push_back(n%10);
        n /= 10;
    }
    long long answer = 0;
    
    insertionSort(v);
 
    for (int i = 0; i < v.size(); i++)
    {
        answer = answer * 10 + v[i];
    }
    return answer;
}
