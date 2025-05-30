// Practice1
// 종이 접기
// 종이를 반으로 접었을 때, 안으로 파인 부분은 0, 볼록 튀어나온 부분은 1이라고 하자.
// 종이를 접을 때는 오른쪽에서 왼쪽으로 접는다.
// 종이를 N번 접었을 때의 접힌 상태를 출력하는 문제를 작성하세요.

// 입출력 예시
// 입력: 1
// 출력: 0

// 입력: 2
// 출력: 0, 0, 1

// 입력: 3
// 출력: 0, 0, 1, 0, 0, 1, 1
#include <iostream>
using namespace std;

void solution(int n) {
    // 작성 (함수 더 필요하면 알아서 만드세요.)
}

int main() {
    // Test code
    solution(1);
    solution(2);
    solution(3);

    return 0;
}



// Practice2
// 각각의 에지에 가중치가 있는 포화 이진 트리가 있다.
// 루트에서 각 리프까지의 경로 길이를 모두 같게 설정하고,
// 이 때, 모든 가중치들의 총합이 최소가 되도록 하는 프로그램을 작성하세요.
void solution(int h, vector<int>& w) {
    // 작성 (함수 더 필요하면 알아서 만드세요.)
}

int main() {
    // Test code
    int h = 2;
    vector<int> w = {2, 2, 2, 1, 1, 3};
    solution(h, w);
    cout << endl;

    h = 3;
    w = {1, 2, 1, 3, 2, 4, 1, 1, 1, 1, 1, 1, 1, 1};
    solution(h, w);

    return 0;
}
