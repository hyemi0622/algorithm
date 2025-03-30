#include <string>
#include <vector>

using namespace std;

vector<int> solution(int l, int r) {
    vector<int> answer;
    for (int i = l ; i <= r; i++)
    {
        string a = to_string(i);
        bool a1 = true;
        for (char c : a) {
            if (c != '0' && c != '5') {
                a1= false;
                break;
            }
        }
        if (a1) {
            answer.push_back(i);
        }
        
    }
    if (answer.empty()) {
        answer.push_back(-1);
    }

    return answer;
}
