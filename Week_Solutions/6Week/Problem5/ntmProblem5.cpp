#include <iostream>
#include <stack>
using namespace std;

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
