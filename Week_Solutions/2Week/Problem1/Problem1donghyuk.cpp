#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int i=0;
    while(i<arr.size()){
        answer.push_back(arr[i]);
        i++;
        while(arr[i-1]==arr[i]&&i<arr.size())
            i++;
    }    
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
}
