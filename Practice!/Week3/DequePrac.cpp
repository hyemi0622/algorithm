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
