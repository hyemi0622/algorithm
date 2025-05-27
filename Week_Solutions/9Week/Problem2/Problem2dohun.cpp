#include <string>
#include <vector>

using namespace std;

void selectionSort(vector<int>& arr) {
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }

}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (int i = 0; i < 3; i++)
    {
        int a = commands[i][0] - 1;
        int b = commands[i][1] - 1;
        int c = commands[i][2] - 1;
        vector<int> v(array.begin() + a, array.begin() + b + 1);
        selectionSort(v);
        answer.push_back(v[c]);
    }
    
    
    return answer;
}
