//송재현

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int l, int r) {
    vector<int> answer;
    for(int i=l;i<=r;i++)
    {
        string temp = to_string(i);
        bool check = true;
        
        for(char j : temp)
        {
            if(j!='0'&&j!='5'){
                check = false;
                break;
            }
        }
        if(check)
            answer.push_back(i);
    }
    if(answer.empty())
        answer.push_back(-1);
    return answer;
}
