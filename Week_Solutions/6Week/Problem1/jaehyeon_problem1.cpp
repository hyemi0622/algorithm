//송재현
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    vector<int> count(26,0);
    
    for(char c : s){
        count[c-'a']++;
    }
    string answer;
    for(int i=0;i<26;i++){
        if(count[i]==1)
            answer += (char)('a'+i);
    }
    return answer;
}
