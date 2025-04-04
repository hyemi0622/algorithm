// Practice1
// 카드 섞기
// 1부터 N 까지의 번호로 구성된 N장의 카드가 있다.
// 1번 카드가 가장 위에 그리고 N번 카드는 가장 아래의 상태로 카드가 순서대로 쌓여있다.
// 아래의 동작을 카드 한 장만 남을 때까지 반복했을 때, 가장 마지막 남는 카드 번호를 출력하시오.
// 1. 가장 위의 카드는 버린다.
// 2. 그 다음 위의 카드는 쌓여 있는 카드의 가장 아래에 다시 넣는다.
#include <iostream>
#include <queue>
using namespace std;

int findLastCard(int N) {
  //여기에 코드 작성  
  return null;
}

int main() {
    // Test code
    cout << findLastCard(4) << endl; // 출력: 4
    cout << findLastCard(7) << endl; // 출력: 6
    cout << findLastCard(9) << endl; // 출력: 2

    return 0;
}



// Practice2
// 요세푸스 문제
// N과 K가 주어졌을 때 (N, K) 요세푸스 순열을 구하시오.
// N과 K는 N >= K 를 만족하는 양의 정수이다.
// 1부터 N 번까지 N명이 순서대로 원을 이루어 모여 있다.
// 이 모임에서 원을 따라 순서대로 K번째 사람을 제외한다.
// 모든 사람이 제외될 때까지 반복하며 이 때, 제외되는 순서가 요세푸스 순열이다.

// 예시 입력
// 입력: N = 5, K = 2
// 결과: 2, 4, 1, 5, 3

// 입력: N = 7, K = 3
// 결과: 3, 6, 2, 7, 5, 1, 4
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> getJosephusPermutation(int N, int K) {
    queue<int> q;
    vector<int> result;
    //여기에 코드 작성
     return result;
}

int main() {
    // Test code
    vector<int> result1 = getJosephusPermutation(5, 2);
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> result2 = getJosephusPermutation(7, 3);
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}


    return result;
}

int main() {
    // Test code
    vector<int> result1 = getJosephusPermutation(5, 2);
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> result2 = getJosephusPermutation(7, 3);
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

