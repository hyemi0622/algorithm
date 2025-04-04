// Practice1
// 단방향 연결 리스트에서 중복 데이터를 찾아 삭제하세요.

// 입출력 예시)
// 입력 연결 리스트: 1, 3, 3, 1, 4, 2, 4, 2
// 결과 연결 리스트: 1, 3, 4, 2

class Node {
  constructor(data) {
    this.data = data;
    this.next = null;
  }
}

class LinkedList {
  constructor() {
    this.head = null;
  }

  addData(data) {
    if (!this.head) {
      this.head = new Node(data);
      return;
    }

    let current = this.head;
    while (current.next) {
      current = current.next;
    }
    current.next = new Node(data);
  }

  findData(data) {
    let current = this.head;
    while (current) {
      if (current.data === data) return true;
      current = current.next;
    }
    return false;
  }

  showData() {
    let current = this.head;
    const result = [];
    while (current) {
      result.push(current.data);
      current = current.next;
    }
    console.log(result.join(" "));
  }
}

function removeDup(listBefore) {
  //여기에 코드 작성
  return null;
}

// Test code
const linkedList = new LinkedList();
linkedList.addData(1);
linkedList.addData(3);
linkedList.addData(3);
linkedList.addData(1);
linkedList.addData(4);
linkedList.addData(2);
linkedList.addData(4);
linkedList.addData(2);

console.log("Before removing duplicates:");
linkedList.showData();

const result = removeDup(linkedList);

console.log("After removing duplicates:");
result.showData();
