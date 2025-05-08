//송재현
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    int even_sum = 0;//짝수
    int odd_sum = 0;//홀수
    for(int i=0;i<num_list.size();i++){
        if(i % 2 ==0)
            even_sum += num_list[i];
        else
            odd_sum += num_list[i];
    }
    answer=(even_sum > odd_sum) ? even_sum : odd_sum;
    return answer;
}
