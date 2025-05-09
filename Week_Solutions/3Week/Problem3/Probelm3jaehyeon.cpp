//송재현
#include <string>
#include <vector>
#include <unordered_map> 
using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string,int> clothesMap;
    for(auto &item : clothes){
        string kind = item[1];
        clothesMap[kind]++;
    }
    int answer = 1;
    for(auto &i : clothesMap)
        answer *= (i.second+1);
    return answer-1;
}
