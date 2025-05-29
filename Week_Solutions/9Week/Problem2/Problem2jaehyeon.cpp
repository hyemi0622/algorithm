//송재현
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
void selectionSort(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        int min = i;
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[j] < arr[min])
                min = j;
        }
        swap(arr[i], arr[min]);
    }
} 

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (int m = 0; m < commands.size(); m++) {
        int i = commands[m][0];
        int j = commands[m][1];
        int k = commands[m][2];

        // array의 i번째 ~ j번째 자르기 (주의: 0-index니까 i-1부터 j까지)
        vector<int> temp(array.begin() + i - 1, array.begin() + j);

        selectionSort(temp); 

        // k번째 원소 뽑아서 answer에 추가 (k도 1-index니까 k-1)
        answer.push_back(temp[k - 1]);
    }

    return answer;
}

