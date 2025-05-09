#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    int answerodd = 0;
    for (int i = 0; i < num_list.size(); i++)
    {
        if (i % 2 == 0) {
            answer += num_list[i];
        }
        else {
            answerodd += num_list[i];
        }
    }
   
    return max(answer,answerodd);
}

