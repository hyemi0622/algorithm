// NodeBi 클래스 정의
class NodeBi {
    constructor(data, next = null, prev = null) {
        this.data = data;
        this.next = next;
        this.prev = prev;
    }
}

// CircularLinkedList 클래스 정의
class CircularLinkedList {
    constructor(node) {
        this.head = node;
        this.tail = node;
        node.next = this.head;
        node.prev = this.head;
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
            const newNodeBi = new NodeBi(data, null, null);
            this.head = newNodeBi;
            this.tail = newNodeBi;
            newNodeBi.next = newNodeBi;
            newNodeBi.prev = newNodeBi;
        } else if (beforeData === null) {
            const newNodeBi = new NodeBi(data, this.head, this.tail);
            this.tail.next = newNodeBi;
            this.head.prev = newNodeBi;
            this.tail = newNodeBi;
        } else {
            let cur = this.head;
            let pre = cur;
            do {
                if (cur.data === beforeData) {
                    if (cur === this.head) {
                        const newNodeBi = new NodeBi(data, this.head, this.tail);
                        this.tail.next = newNodeBi;
                        this.head.prev = newNodeBi;
                        this.head = newNodeBi;
                    } else {
                        const newNodeBi = new NodeBi(data, cur, pre);
                        pre.next = newNodeBi;
                        cur.prev = newNodeBi;
                    }
                    break;
                }
                pre = cur;
                cur = cur.next;
            } while (cur !== this.head);
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
        do {
            if (cur.data === data) {
                if (cur === this.head && cur === this.tail) {
                    this.head = null;
                    this.tail = null;
                } else if (cur === this.head) {
                    cur.next.prev = this.head.prev;
                    this.head = cur.next;
                    this.tail.next = this.head;
                } else if (cur === this.tail) {
                    pre.next = this.tail.next;
                    this.tail = pre;
                    this.head.prev = this.tail;
                } else {
                    pre.next = cur.next;
                    cur.next.prev = pre;
                }
                break;
            }

            pre = cur;
            cur = cur.next;
        } while (cur !== this.head);
    }

    // 연결 리스트의 모든 데이터 출력 (head부터)
    showData() {
        if (this.isEmpty()) {
            console.log("List is empty!");
            return;
        }

        let cur = this.head;
        let result = '';
        do {
            result += cur.data + " ";
            cur = cur.next;
        } while (cur !== this.head);

        console.log(result.trim());
    }
}

// 테스트 코드
const myList = new CircularLinkedList(new NodeBi(1, null, null));
myList.addData(2, null);
myList.addData(3, null);
myList.addData(4, null);
myList.addData(5, null);
myList.showData();  // 1 2 3 4 5

myList.addData(100, 1);
myList.addData(200, 2);
myList.addData(300, 3);
myList.addData(400, 4);
myList.addData(500, 5);
myList.showData();  // 100 1 200 2 300 3 400 4 500 5

myList.removeData(300);
myList.removeData(100);
myList.removeData(500);
myList.removeData(200);
myList.removeData(400);
myList.showData();  // 1 2 3 4 5

myList.removeData(3);
myList.removeData(1);
myList.removeData(5);
myList.removeData(2);
myList.removeData(4);
myList.showData();  // List is empty!
