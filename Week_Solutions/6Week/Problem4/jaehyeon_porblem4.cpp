//송재현
#include <string>

using namespace std;

int solution(string my_string, string is_suffix) {
    bool answer = 0;
    if(is_suffix.size()>my_string.size())
        return 0;
    string suffix = my_string.substr(my_string.length()-is_suffix.length());
    if(suffix==is_suffix)
        answer = 1;
return answer;
}
