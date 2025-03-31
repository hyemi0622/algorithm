// NodeBi 클래스 정의
class NodeBi {
    constructor(data, next = null, prev = null) {
        this.data = data;
        this.next = next;
        this.prev = prev;
    }
}

// DoublyLinkedList 클래스 정의
class DoublyLinkedList {
    constructor(node) {
        this.head = node;
        this.tail = node;
    }

    // 연결 리스트가 비었는지 확인
    isEmpty() {
        return this.head === null;
    }

    // 연결 리스트에 데이터 추가
    // beforeData가 null인 경우, 가장 뒤에 추가
    // beforeData에 값이 있는 경우, 해당 값을 가진 노드 앞에 추가
    addData(data, beforeData) {
        if (this.head === null) {
            this.head = new NodeBi(data, null, null);
            this.tail = this.head;
        } else if (beforeData === null) {
            this.tail.next = new NodeBi(data, null, this.tail);
            this.tail = this.tail.next;
        } else {
            let cur = this.head;
            let pre = cur;
            while (cur !== null) {
                if (cur.data === beforeData) {
                    if (cur === this.head) {
                        this.head = new NodeBi(data, this.head, null);
                        this.head.next.prev = this.head;
                    } else {
                        pre.next = new NodeBi(data, cur, pre);
                        cur.prev = pre.next;
                    }
                    break;
                }
                pre = cur;
                cur = cur.next;
            }
        }
    }

    // 연결 리스트에서 특정 값을 가진 노드 삭제
    removeData(data) {
        if (this.isEmpty()) {
            console.log("List is empty");
            return;
        }

        let cur = this.head;
        let pre = cur;

        while (cur !== null) {
            if (cur.data === data) {
                if (cur === this.head && cur === this.tail) {
                    this.head = null;
                    this.tail = null;
                } else if (cur === this.head) {
                    this.head = cur.next;
                    this.head.prev = null;
                } else if (cur === this.tail) {
                    this.tail = this.tail.prev;
                    this.tail.next = null;
                } else {
                    pre.next = cur.next;
                    cur.next.prev = pre;
                }
                break;
            }

            pre = cur;
            cur = cur.next;
        }
    }

    // 연결 리스트의 모든 데이터 출력 (head부터)
    showData() {
        if (this.isEmpty()) {
            console.log("List is empty!");
            return;
        }

        let cur = this.head;
        let result = '';
        while (cur !== null) {
            result += cur.data + " ";
            cur = cur.next;
        }
        console.log(result.trim());
    }

    // 연결 리스트의 모든 데이터 출력 (tail부터)
    showDataFromTail() {
        if (this.isEmpty()) {
            console.log("List is empty");
            return;
        }

        let cur = this.tail;
        let result = '';
        while (cur !== null) {
            result += cur.data + " ";
            cur = cur.prev;
        }
        console.log(result.trim());
    }
}

// 테스트 코드
const myList = new DoublyLinkedList(new NodeBi(1, null, null));
myList.showData();          // 1

myList.addData(2, null);
myList.addData(3, null);
myList.addData(4, null);
myList.addData(5, null);
myList.showData();          // 1 2 3 4 5
myList.showDataFromTail();  // 5 4 3 2 1

myList.addData(100, 1);
myList.addData(200, 2);
myList.addData(300, 3);
myList.addData(400, 4);
myList.addData(500, 5);
myList.showData();          // 100 1 200 2 300 3 400 4 500 5
myList.showDataFromTail();  // 5 500 4 400 3 300 2 200 1 100

myList.removeData(300);
myList.removeData(100);
myList.removeData(500);
myList.removeData(200);
myList.removeData(400);
myList.showData();          // 1 2 3 4 5
myList.showDataFromTail();  // 5 4 3 2 1

myList.removeData(3);
myList.removeData(1);
myList.removeData(5);
myList.removeData(2);
myList.removeData(4);
myList.showData();          // List is empty!
myList.showDataFromTail();  // List is empty!
