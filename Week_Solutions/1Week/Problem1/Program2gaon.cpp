// 배열 회전시키기
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers, string direction) {
    int n = numbers.size()
        
    if (direction == "right") {
        for (int i=n-1; i>0; i--) {
            numbers[i] = numbers[i-1];
        }
        numbers[0]=numbers[n-1];
    }
    else if (direction == "left") {
        for (int i=0; i<n; i++) {
            numbers[i] = numbers[i+1];
        }
        numbers[n-1]=numbers[0];
    }
        
    return numbers;
}
