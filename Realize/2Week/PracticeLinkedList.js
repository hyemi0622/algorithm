// 노드 클래스
class Node {
    constructor(data, next = null) {
        this.data = data;
        this.next = next;
    }
}

// 연결 리스트 클래스
class LinkedList {
    constructor(node = null) {
        this.head = node;
    }

    // 연결 리스트가 비었는지 확인
    isEmpty() {
        return this.head === null;
    }

    // 연결 리스트의 맨 뒤에 데이터 추가
    addData(data) {
        if (this.head === null) {
            this.head = new Node(data, null);
        } else {
            let cur = this.head;
            while (cur.next !== null) {
                cur = cur.next;
            }
            cur.next = new Node(data, null);
        }
    }

    // 연결 리스트의 맨 뒤의 데이터 삭제
    removeData() {
        if (this.isEmpty()) {
            console.log("List is empty");
            return;
        }

        let cur = this.head;
        let prev = null;

        // 리스트의 끝까지 이동
        while (cur.next !== null) {
            prev = cur;
            cur = cur.next;
        }

        if (cur === this.head) {
            this.head = null; // 리스트가 하나만 있을 때
        } else {
            prev.next = null; // 맨 마지막 노드를 삭제
        }
    }

    // 연결 리스트에서 데이터 찾기
    findData(data) {
        if (this.isEmpty()) {
            console.log("List is empty");
            return;
        }

        let cur = this.head;
        while (cur !== null) {
            if (cur.data === data) {
                console.log("Data exist!");
                return;
            }
            cur = cur.next;
        }
        console.log("Data not found!");
    }

    // 연결 리스트의 모든 데이터 출력
    showData() {
        if (this.isEmpty()) {
            console.log("List is empty!");
            return;
        }

        let cur = this.head;
        let result = [];
        while (cur !== null) {
            result.push(cur.data);
            cur = cur.next;
        }
        console.log(result.join(' '));
    }
}

// 테스트 코드
let myList = new LinkedList(new Node(1));

myList.showData();  // 1

myList.addData(2);
myList.addData(3);
myList.addData(4);
myList.addData(5);
myList.showData();  // 1 2 3 4 5

myList.findData(3);  // Data exist!
myList.findData(100);  // Data not found!

myList.removeData();
myList.removeData();
myList.removeData();
myList.showData();  // 1 2

myList.removeData();
myList.removeData();
myList.removeData();  // List is empty
