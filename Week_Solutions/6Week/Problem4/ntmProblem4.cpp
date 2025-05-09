#include <iostream>
#include <stack>
using namespace std;


//어떤 문자열에 대해서 접미사는 특정 인덱스부터 시작하는 문자열을 의미합니다.
//예를 들어, "banana"의 모든 접미사는 "banana", "anana", "nana", "ana", "na", "a"입니다.
//문자열 my_string과 is_suffix가 주어질 때, is_suffix가 my_string의 접미사라면 1을, 아니면 0을 return 하는 solution 함수를 작성해 주세요.


int solution(const char* my_string, const char* is_suffix) {
    int answer = 0;
    stack<char> arr1, arr2;
    for (int i = 0; ; i++) {
        if (my_string[i] == '\0')
            break;
        arr1.push(my_string[i]);
    }

    for (int i = 0; ; i++) {
        if (is_suffix[i] == '\0')
            break;
        arr2.push(is_suffix[i]);
    }

    while (!arr2.empty()) {
        if (arr1.top() == arr2.top()) {
            arr1.pop();
            arr2.pop();
        }
        else {
            return 0;
        }
    }
    return 1;
}
