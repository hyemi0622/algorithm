#include <string>
#include <vector>

using namespace std;
void bubbleSort(vector<string>& strings, int n) {
    
    for (int i = 0; i < strings.size() - 1; i++)
    {
        for (int j = 0; j < strings.size() - 1 - i; j++)
        {
            char a = strings[j][n];
            char b = strings[j + 1][n];
            if (a > b)
            {
                swap(strings[j], strings[j + 1]);
            
            }
            else if (a == b)
            {
                if (strings[j] > strings[j + 1])
                {
                    swap(strings[j], strings[j + 1]);
                }
            }
            
        }
    }
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer= strings;
    bubbleSort(answer, n);
    return answer;
}
