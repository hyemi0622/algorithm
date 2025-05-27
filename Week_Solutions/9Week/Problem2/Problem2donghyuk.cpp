#include<iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer,temp;
    for (int i = 0; i < commands.size(); i++)
    {
        for (int j = commands[i][0]-1; j < commands[i][1]; j++)
        {
            temp.push_back(array[j]);
        }

        for (int i = 0; i < temp.size(); i++) {
            int min = i;
            for (int j = min; j < temp.size(); j++)
            {
                if (temp[min] > temp[j])
                    min = j;
            }
            swap(temp[min], temp[i]);
        }
        answer.push_back(temp[commands[i][2] - 1]);
        temp.clear();
    }
    return answer;
}
