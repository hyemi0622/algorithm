// Practice1
// 데이터 재정렬
// D_0 -> D_1 -> ... -> D_n-1 -> D_n 순으로 되어 있는 데이터를
// D_0 -> D_n -> D_1 -> D_n-1 -> ... 순이 되도록 재정렬 하시오.

// 입력 예시)
// 입력 데이터: 1 -> 2 -> 3 -> 4 -> 5
// 출력 데이터: 1 -> 5 -> 2 -> 4 -> 3
#include <iostream>
#include <deque>
using namespace std;

void reorderData(int arr[], int n) {
    deque<int> dq;
    //여기에 코드 작성
}

int main() {
    // Test code
    int arr1[] = {1, 2, 3, 4, 5};
    reorderData(arr1, 5); // 출력: 1 -> 5 -> 2 -> 4 -> 3

    int arr2[] = {1, 2, 3, 4, 5, 6, 7};
    reorderData(arr2, 7); // 출력: 1 -> 7 -> 2 -> 6 -> 3 -> 5 -> 4

    return 0;
}




// Practice2
// Palindrome 찾기
// Palindrome 이면 true, 아니면 false 를 반환하세요.
// Palindrome: 앞으로 읽어도 거꾸로 읽어도 같은 문자열

// 입출력 예시)
// 입력: a
// 결과: true

// 입력: madam
// 결과: true

// 입력: abab
// 결과: false

#include <iostream>
#include <deque>
#include <string>

using namespace std;

bool checkPalindrome(const string& str) {
    // Add code here
    return false;  // Placeholder
}

int main() {
    // Test code
    cout << checkPalindrome("a") << endl;       // true
    cout << checkPalindrome("aba") << endl;     // true
    cout << checkPalindrome("abba") << endl;    // true
    cout << checkPalindrome("abab") << endl;    // false
    cout << checkPalindrome("abcba") << endl;   // true
    cout << checkPalindrome("abccba") << endl;  // true
    cout << checkPalindrome("madam") << endl;   // true
}

