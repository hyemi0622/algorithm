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



// Practice3
// 데크 변형
// 기본 데크 구조에서 중간에 데이터를 추가하는 기능을 구현하세요.
// 단, 추가적인 자료구조 생성하지 말고 구현

// 입력 예시)
// 초기 데크 상태 (size: 5)
// -> 1, 2, 3, 4
// 중간 입력: 10
// 결과 데크
// -> 1, 2, 10, 3, 4
#include <iostream>
#include <vector>

using namespace std;

class MyDeque {
private:
    vector<int> arr;
    int front = 0;
    int rear = 0;

public:
    MyDeque(int size) {
        arr.resize(size + 1);  // Deque with size+1 to handle circular structure
    }

    bool isEmpty() {
        return front == rear;
    }

    bool isFull() {
        return (rear + 1) % arr.size() == front;
    }

    void addFirst(int data) {
        if (isFull()) {
            cout << "Deque is full!" << endl;
            return;
        }
        front = (front - 1 + arr.size()) % arr.size();
        arr[front] = data;
    }

    void addLast(int data) {
        if (isFull()) {
            cout << "Deque is full!" << endl;
            return;
        }
        rear = (rear + 1) % arr.size();
        arr[rear] = data;
    }

    void addMiddle(int data) {
        //여기에 코드 작성
    }

    int removeFirst() {
        if (isEmpty()) {
            cout << "Deque is empty!" << endl;
            return -1;
        }
        front = (front + 1) % arr.size();
        return arr[front];
    }

    int removeLast() {
        if (isEmpty()) {
            cout << "Deque is empty!" << endl;
            return -1;
        }
        int data = arr[rear];
        rear = (rear - 1 + arr.size()) % arr.size();
        return data;
    }

    void printDeque() {
        int start = (front + 1) % arr.size();
        int end = (rear + 1) % arr.size();

        for (int i = start; i != end; i = (i + 1) % arr.size()) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    // Test code
    MyDeque myDeque1(5);
    myDeque1.addLast(1);
    myDeque1.addLast(2);
    myDeque1.addLast(3);
    myDeque1.addLast(4);
    myDeque1.printDeque();

    myDeque1.addMiddle(10);
    myDeque1.printDeque();

    MyDeque myDeque2(5);
    myDeque2.addLast(10);
    myDeque2.addLast(10);
    myDeque2.addLast(10);
    myDeque2.addLast(10);
    myDeque2.addLast(10);
    myDeque2.removeFirst();
    myDeque2.removeFirst();
    myDeque2.removeFirst();
    myDeque2.removeFirst();
    myDeque2.addLast(11);
    myDeque2.addLast(12);
    myDeque2.addLast(13);
    myDeque2.printDeque();

    myDeque2.addMiddle(100);
    myDeque2.printDeque();
}
