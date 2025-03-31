#include <vector>
#include<string>

using namespace std;

vector<int> solution(vector<int> numbers, string direction)
{
	if (direction == "right"){
        int end = numbers.back();
        for (int i = numbers.size() - 1; i > 0; i--) {
            numbers[i] = numbers[i - 1];
        }
        numbers.front() = end;
	}
    else if (direction == "left") {
        int first = numbers.front();
        for (int i = 0; i < numbers.size() - 1; i++) {
            numbers[i] = numbers[i + 1];
        }
        numbers.back() = first;
    }
    return numbers;
}
