#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer = strings;
    int temp = n;
    for (int i = 0; i < answer.size() - 1; i++) {
        for (int j = 0; j < answer.size() - i - 1; j++) {
            if(answer[j][n] == answer[j + 1][n]) {
                n = 0;
            }
            while (answer[j][n] == answer[j + 1][n])
                n++;
            if (answer[j][n] > answer[j + 1][n]) {
                swap(answer[j], answer[j + 1]);
            }
            n = temp;
        }
    }

    return answer;
}
