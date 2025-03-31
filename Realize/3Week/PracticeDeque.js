class MyDeque2 {
    constructor(size) {
        this.size = size + 1;
        this.arr = new Array(this.size).fill(0);
        this.front = 0;
        this.rear = 0;
    }

    isEmpty() {
        return this.rear === this.front;
    }

    isFull() {
        return (this.rear + 1) % this.size === this.front;
    }

    addFirst(data) {
        if (this.isFull()) {
            console.log("Deque is full!");
            return;
        }
        this.front = (this.front - 1 + this.size) % this.size;
        this.arr[this.front] = data;
    }

    addLast(data) {
        if (this.isFull()) {
            console.log("Deque is full!");
            return;
        }
        this.arr[this.rear] = data;
        this.rear = (this.rear + 1) % this.size;
    }

    removeFirst() {
        if (this.isEmpty()) {
            console.log("Deque is empty!");
            return;
        }
        const data = this.arr[this.front];
        this.front = (this.front + 1) % this.size;
        return data;
    }

    removeLast() {
        if (this.isEmpty()) {
            console.log("Deque is empty!");
            return;
        }
        this.rear = (this.rear - 1 + this.size) % this.size;
        return this.arr[this.rear];
    }

    printDeque() {
        if (this.isEmpty()) {
            console.log("Deque is empty!");
            return;
        }
        let i = this.front;
        while (i !== this.rear) {
            process.stdout.write(this.arr[i] + " ");
            i = (i + 1) % this.size;
        }
        console.log();
    }
}

// 테스트 코드
const myDeque = new MyDeque2(5);

// Front 부분 입력
myDeque.addFirst(1);
myDeque.addFirst(2);
myDeque.addFirst(3);
myDeque.printDeque();  // 3 2 1

// Rear 부분 입력
myDeque.addLast(10);
myDeque.addLast(20);
myDeque.addLast(30);  // Deque is full!
myDeque.printDeque();  // 3 2 1 10 20

// Front 부분 출력
console.log(myDeque.removeFirst());  // 3
myDeque.printDeque();  // 2 1 10 20

// Rear 부분 출력
console.log(myDeque.removeLast());   // 20
myDeque.printDeque();  // 2 1 10

console.log(myDeque.removeLast());   // 10
console.log(myDeque.removeLast());   // 1
console.log(myDeque.removeLast());   // 2
myDeque.removeLast();  // Deque is empty!
