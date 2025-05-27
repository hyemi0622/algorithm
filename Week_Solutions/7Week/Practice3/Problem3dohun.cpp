#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    for (int i=0; i<arr.size(); i++)
    {
        answer.push_back(arr[i]);
    }
    int index = -1;

    for (int i = 0; i < answer.size(); i++)
    {
        if (answer[i] == 2) {
            index = i;
        }
    }
    if (index == -1) return {-1}; 
    for (int i = 0; i < index;) {
        if (answer[0] != 2) { 
            answer.erase(answer.begin());
            index--; 
        }
        else {
            break;
        }
    }

    int pos = -1;
    for (int i = answer.size()-1; i >= 0; --i) {
        if (answer[i] == 2) {
            pos = i;
            break;
        }
    }
    while (answer.size() > pos + 1) {
        answer.pop_back(); 
    }
    return answer;
}

