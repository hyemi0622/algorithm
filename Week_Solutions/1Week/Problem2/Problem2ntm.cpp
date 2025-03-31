#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers, string direction) {
    if (direction == "left") {
        numbers.push_back(numbers.front());
        numbers.erase(numbers.begin());
    }
    else if (direction == "right") {
        numbers.insert(numbers.begin(), numbers.back());
        numbers.pop_back();
    }
    return numbers;
}
