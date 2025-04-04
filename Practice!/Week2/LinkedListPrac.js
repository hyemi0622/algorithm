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



// Practice2
// Palindrome 연결 리스트
// 추가 자료구조 없이 연결 리스트만으로 풀어보기 Practice1에서 만든 단일연결리스트 사용(내장 LinkedList말고)
// Palindrome: 앞으로 읽어도 뒤로 읽어도 같은 문자열
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


function checkPalindrome(linkedList) {
   //여기에 코드 작성
  return false;
}

// Test code
const linkedList1 = new LinkedList();
linkedList1.addData(1);
linkedList1.addData(3);
linkedList1.addData(5);
linkedList1.addData(3);
linkedList1.addData(1);
console.log(checkPalindrome(linkedList1)); // true

const linkedList2 = new LinkedList();
linkedList2.addData(3);
linkedList2.addData(5);
linkedList2.addData(5);
linkedList2.addData(3);
console.log(checkPalindrome(linkedList2)); // true

const linkedList3 = new LinkedList();
linkedList3.addData(1);
linkedList3.addData(3);
linkedList3.addData(5);
linkedList3.addData(1);
console.log(checkPalindrome(linkedList3)); // false

