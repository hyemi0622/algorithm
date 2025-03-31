#include <string>
#include <vector>

using namespace std;

vector<int> solution(int l, int r) {
    vector<int> answer;
    
    for (int i = l; i <= r; i++) {
        string  str = to_string(i);
        bool t_f = 1;
        
        for (int j = 0; j < str.length(); j++) {
            if (str[j] != '5' && str[j] != '0') {
                t_f = 0;
                break;
            }
        }
        if (t_f)
            answer.push_back(i);
    }
    
    if (answer.empty())
        return {-1};
    
    return answer;
}
