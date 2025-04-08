// 지피티야 고마워.....

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> v, answer;
    
    for (int i=0; i<progresses.size(); i++) {
        v.push_back(100-progresses[i]);
    }
    
    for (int i=0; i<v.size(); i++) {
        if (v[i]%speeds[i]!=0) {
            v[i]= v[i]/speeds[i] + 1;
        }
        else {
            v[i]/=speeds[i];
        }
    }
    
    int count = 1;
    int standard = v[0];
    for (int i=1; i<v.size(); i++) {
        if (v[i]<=standard) {
            count++;
        }
        else {
            answer.push_back(count);
            standard=v[i];
            count=1;
        }
        
    }
    answer.push_back(count);
    
    return answer;
}
