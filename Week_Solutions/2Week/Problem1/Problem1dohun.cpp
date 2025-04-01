#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer= arr;
    
   
    answer.erase(unique(answer.begin(), answer.end()),answer.end());
        // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    for (auto i : answer) {
        cout << i << " ";
    }
    cout << "Hello Cpp" << endl;

    return answer;
}
