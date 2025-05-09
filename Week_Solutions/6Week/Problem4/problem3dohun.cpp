#include <string>
#include <vector>

using namespace std;
int solution(string my_string, string is_suffix) {
    int answer = 1;
    int a = my_string.length();
    int b = is_suffix.length();

    if (b > a) {
        answer = 0;
    }

    for (int i = 0; i < b; i++) {
        if (my_string[a - b + i] != is_suffix[i]) {
            answer = 0;
        }
    }

    return answer;
}
