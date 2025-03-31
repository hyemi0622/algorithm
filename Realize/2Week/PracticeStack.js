// MyStack 클래스 정의
class MyStack {
    constructor(size) {
        this.arr = new Array(size);
        this.top = -1;
    }

    // 스택이 비었는지 확인
    isEmpty() {
        return this.top === -1;
    }

    // 스택이 가득 찼는지 확인
    isFull() {
        return this.top === this.arr.length - 1;
    }

    // 스택에 데이터 추가
    push(data) {
        if (this.isFull()) {
            console.log("Stack is full!");
            return;
        }
        this.top += 1;
        this.arr[this.top] = data;
    }

    // 스택에서 데이터 꺼내기
    pop() {
        if (this.isEmpty()) {
            console.log("Stack is empty!");
            return null;
        }
        const data = this.arr[this.top];
        this.top -= 1;
        return data;
    }

    // 스택의 가장 위 데이터 확인
    peek() {
        if (this.isEmpty()) {
            console.log("Stack is empty!");
            return null;
        }
        return this.arr[this.top];
    }

    // 스택의 데이터 출력
    printStack() {
        let result = '';
        for (let i = 0; i <= this.top; i++) {
            result += this.arr[i] + ' ';
        }
        console.log(result.trim());
    }
}

// 테스트 코드
const myStack = new MyStack(5);

console.log(myStack.isEmpty()); // true

myStack.push(1);
myStack.push(2);
myStack.push(3);
myStack.push(4);
myStack.push(5);
myStack.push(6); // Stack is full!

myStack.printStack(); // 1 2 3 4 5

console.log(myStack.peek()); // 5
myStack.printStack(); // 1 2 3 4 5

console.log(myStack.pop()); // 5
console.log(myStack.pop()); // 4
myStack.printStack(); // 1 2 3

console.log(myStack.pop()); // 3
console.log(myStack.pop()); // 2
console.log(myStack.pop()); // 1
myStack.printStack(); // (빈 스택)
