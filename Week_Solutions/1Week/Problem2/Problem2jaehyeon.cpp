//송재현

#include <vector>
#include <string>
using namespace std;

vector<int> solution(vector<int> numbers, string direction) {
    int size = numbers.size();
    vector<int> result(size);

    if (direction == "right") {
        result[0] = numbers[size - 1]; 
        for (int i = 1; i < size; i++)
            result[i] = numbers[i - 1]; 
    }
    else { // direction == "left"
        result[size - 1] = numbers[0]; 
        for (int i = 0; i < size - 1; i++)
            result[i] = numbers[i + 1]; 
    }
    return result;
}
