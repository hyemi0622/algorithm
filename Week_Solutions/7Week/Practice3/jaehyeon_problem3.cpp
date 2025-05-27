//송재현
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    int first = -1;
    int last = -1;
    
    for(int i=0;i<arr.size();i++){
        if(arr[i]==2){
            if(first==-1)
                first=i;
            last=i;
        }
    }
    if(first == -1)
            return vector<int>{-1};
    vector<int> result;
    for(int i=first;i<=last;i++)
    {
        result.push_back(arr[i]);
    }
    return result;
}
