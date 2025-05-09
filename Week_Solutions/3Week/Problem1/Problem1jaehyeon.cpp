//송재현
//3주차 자료구조 안씀
#include <string>
#include <vector>
using namespace std;

int solution(vector<int> numbers, int k) {
    return numbers[2*(k-1)%numbers.size()];
}
