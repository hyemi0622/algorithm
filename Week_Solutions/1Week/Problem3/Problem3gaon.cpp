#include <string>
#include <vector>

using namespace std;

bool isValidNumber(const string& s) {
    for (char c : s) {
        if (c != '0' && c != '5') 
            return false;
    }
    return true;
}

vector<int> solution(int l, int r) {
    vector<int> number;
    vector<int> arr;
  
    for (int i = l; i <= r; i++) {
        number.push_back(i); // l부터 r까지 숫자 넣음
    }
    
    for (int i = 0; i < number.size(); i++) {
        string str = to_string(number[i]);  // number[i]를 string으로 바꿈
        if (isValidNumber(str)) {
            arr.push_back(number[i]);
        }
    }
    
    if (arr.empty()) {
        return {-1};  
    }
    
    return arr;  
}
