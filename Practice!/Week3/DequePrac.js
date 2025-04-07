// Practice1
// 데이터 재정렬
// D_0 -> D_1 -> ... -> D_n-1 -> D_n 순으로 되어 있는 데이터를
// D_0 -> D_n -> D_1 -> D_n-1 -> ... 순이 되도록 재정렬 하시오.

// 입력 예시)
// 입력 데이터: 1 -> 2 -> 3 -> 4 -> 5
// 출력 데이터: 1 -> 5 -> 2 -> 4 -> 3
function reorderData(arr) {
    let deque = []; // 덱을 배열로 구현
    //여기에 코드 작성
}

// Test code
reorderData([1, 2, 3, 4, 5]); // 출력: 1 -> 5 -> 2 -> 4 -> 3
reorderData([1, 2, 3, 4, 5, 6, 7]); // 출력: 1 -> 7 -> 2 -> 6 -> 3 -> 5 -> 4



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
function checkPalindrome(str) {
    // Add code here
    return false; // Placeholder
}

// Test code
console.log(checkPalindrome("a"));       // true
console.log(checkPalindrome("aba"));     // true
console.log(checkPalindrome("abba"));    // true
console.log(checkPalindrome("abab"));    // false
console.log(checkPalindrome("abcba"));   // true
console.log(checkPalindrome("abccba"));  // true
console.log(checkPalindrome("madam"));   // true




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
class MyDeque {
    constructor(size) {
        this.arr = new Array(size + 1);  // Deque with size+1 to handle circular structure
        this.front = 0;
        this.rear = 0;
    }

    isEmpty() {
        return this.front === this.rear;
    }

    isFull() {
        return (this.rear + 1) % this.arr.length === this.front;
    }

    addFirst(data) {
        if (this.isFull()) {
            console.log("Deque is full!");
            return;
        }
        this.front = (this.front - 1 + this.arr.length) % this.arr.length;
        this.arr[this.front] = data;
    }

    addLast(data) {
        if (this.isFull()) {
            console.log("Deque is full!");
            return;
        }
        this.rear = (this.rear + 1) % this.arr.length;
        this.arr[this.rear] = data;
    }

    addMiddle(data) {
        //여기에 코드 작성
    }

    removeFirst() {
        if (this.isEmpty()) {
            console.log("Deque is empty!");
            return null;
        }
        this.front = (this.front + 1) % this.arr.length;
        return this.arr[this.front];
    }

    removeLast() {
        if (this.isEmpty()) {
            console.log("Deque is empty!");
            return null;
        }
        let data = this.arr[this.rear];
        this.rear = (this.rear - 1 + this.arr.length) % this.arr.length;
        return data;
    }

    printDeque() {
        let start = (this.front + 1) % this.arr.length;
        let end = (this.rear + 1) % this.arr.length;

        while (start !== end) {
            console.log(this.arr[start]);
            start = (start + 1) % this.arr.length;
        }
    }
}

// Test code
let myDeque1 = new MyDeque(5);
myDeque1.addLast(1);
myDeque1.addLast(2);
myDeque1.addLast(3);
myDeque1.addLast(4);
myDeque1.printDeque();

myDeque1.addMiddle(10);
myDeque1.printDeque();

let myDeque2 = new MyDeque(5);
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



// Practice4
// 데크 리사이즈
// 기본 데크 구조에서 데크 공간이 full 일 때 데이터를 추가하는 경우,
// 데크 공간을 2배 씩 늘려주는 코드를 작성하세요.
class MyDeque2 {
    constructor(size) {
        this.arr = new Array(size + 1);  // Deque with size+1 to handle circular structure
        this.front = 0;
        this.rear = 0;
    }

    isEmpty() {
        return this.front === this.rear;
    }

    isFull() {
        return (this.rear + 1) % this.arr.length === this.front;
    }

    increaseSize() {
        //여기에 코드 작성
    }

    addFirst(data) {
        if (this.isFull()) {
            console.log("Deque is full!");
            return;
        }

        this.arr[this.front] = data;
        this.front = (this.front - 1 + this.arr.length) % this.arr.length;
    }

    addLast(data) {
        if (this.isFull()) {
            console.log("Deque is full!");
            return;
        }

        this.rear = (this.rear + 1) % this.arr.length;
        this.arr[this.rear] = data;
    }

    removeFirst() {
        if (this.isEmpty()) {
            console.log("Deque is empty!");
            return null;
        }

        this.front = (this.front + 1) % this.arr.length;
        return this.arr[this.front];
    }

    removeLast() {
        if (this.isEmpty()) {
            console.log("Deque is empty!");
            return null;
        }

        let data = this.arr[this.rear];
        this.rear = (this.rear - 1 + this.arr.length) % this.arr.length;
        return data;
    }

    printDeque() {
        let start = (this.front + 1) % this.arr.length;
        let end = (this.rear + 1) % this.arr.length;

        while (start !== end) {
            console.log(this.arr[start]);
            start = (start + 1) % this.arr.length;
        }
    }
}

// Test code
let myDeque = new MyDeque2(5);

myDeque.addLast(1);
myDeque.addLast(2);
myDeque.addLast(3);
myDeque.addLast(4);
myDeque.addLast(5);
myDeque.printDeque();

myDeque.addLast(6);
myDeque.addLast(7);
myDeque.addLast(8);
myDeque.addLast(9);
myDeque.addLast(10);
myDeque.printDeque();

myDeque.removeLast();
myDeque.removeLast();
myDeque.addFirst(100);
myDeque.addFirst(200);
myDeque.printDeque();

myDeque.addFirst(300);
myDeque.addFirst(400);
myDeque.addFirst(500);
myDeque.printDeque();
