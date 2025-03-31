class MyQueue2 {
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

    enqueue(data) {
        if (this.isFull()) {
            console.log("Queue is full!");
            return;
        }
        this.rear = (this.rear + 1) % this.size;
        this.arr[this.rear] = data;
    }

    dequeue() {
        if (this.isEmpty()) {
            console.log("Queue is empty!");
            return null;
        }
        this.front = (this.front + 1) % this.size;
        return this.arr[this.front];
    }

    printQueue() {
        let start = (this.front + 1) % this.size;
        let end = (this.rear + 1) % this.size;
        let i = start;
        let result = "";
        while (i !== end) {
            result += this.arr[i] + " ";
            i = (i + 1) % this.size;
        }
        console.log(result.trim());
    }
}

const myQueue = new MyQueue2(5);
myQueue.enqueue(1);
myQueue.enqueue(2);
myQueue.enqueue(3);
myQueue.enqueue(4);
myQueue.enqueue(5);
myQueue.enqueue(6); // Queue is full!

myQueue.printQueue(); // 1 2 3 4 5

console.log(myQueue.dequeue()); // 1
myQueue.printQueue(); // 2 3 4 5

console.log(myQueue.dequeue()); // 2
myQueue.printQueue(); // 3 4 5

myQueue.enqueue(6);
myQueue.enqueue(7);
myQueue.printQueue(); // 3 4 5 6 7

console.log(myQueue.dequeue()); // 3
console.log(myQueue.dequeue()); // 4
console.log(myQueue.dequeue()); // 5
myQueue.printQueue(); // 6 7
console.log(myQueue.dequeue()); // 6
console.log(myQueue.dequeue()); // 7
myQueue.dequeue(); // Queue is empty!
