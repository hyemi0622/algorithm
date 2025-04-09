#include <string>
#include <vector>
#include<unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string, int> um;
    
    
    for (auto& item : clothes) {
        string kind1 = item[1];
        um[kind1]++;
        
    }
    int mix = 1;
    for (const auto& item : um) {
        string kind1 = item.first;
        int count = item.second;
        mix *= (count + 1);
    }
    
    return mix - 1;
}
