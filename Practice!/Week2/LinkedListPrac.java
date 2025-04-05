// Practice1
// 단방향 연결 리스트에서 중복 데이터를 찾아 삭제하세요.

// 입출력 예시)
// 입력 연결 리스트: 1, 3, 3, 1, 4, 2, 4, 2
// 결과 연결 리스트: 1, 3, 4, 2

class Node {
    int data;
    Node next;

    Node() {}
    Node(int data, Node next) {
        this.data = data;
        this.next = next;
    }
}

class LinkedList {
    Node head;

    LinkedList() {}
    LinkedList(Node node) {
        this.head = node;
    }

    public boolean isEmpty() {
        return this.head == null;
    }

    public void addData(int data) {
        if (this.head == null) {
            this.head = new Node(data, null);
        } else {
            Node cur = this.head;
            while (cur.next != null) {
                cur = cur.next;
            }
            cur.next = new Node(data, null);
        }
    }

    public void removeData(int data) {
        /*if (this.isEmpty()) {
            System.out.println("List is empty");
            return;
        }*/

        Node cur = this.head;
        Node pre = cur;
        while (cur != null) {
            if (cur.data == data) {
                if (cur == this.head) {
                    this.head = cur.next;
                } else {
                    pre.next = cur.next;
                }
                break;
            }

            pre = cur;
            cur = cur.next;
        }
    }

    public boolean findData(int data) {
        /*if (this.isEmpty()) {
            System.out.println("List is empty");
        }*/

        Node cur = this.head;
        while (cur != null) {
            if (cur.data == data) {
                return true;
            }
            cur = cur.next;
        }
        return false;
    }

    public void showData() {
       // if (this.isEmpty()) {
          //  System.out.println("List is empty!");
          //  return;
      //  }
        Node cur = this.head;
        while (cur != null) {
            System.out.print(cur.data + " ");
            cur = cur.next;
        }
        System.out.println();
    }
}

public class Practice1 {
    public static LinkedList removeDup(LinkedList listBefore) {
        // 여기에 코드 작성
        return null;
    }

    public static void main(String[] args) {
        // Test code
        LinkedList linkedList = new LinkedList();
        linkedList.addData(1);
        linkedList.addData(3);
        linkedList.addData(3);
        linkedList.addData(1);
        linkedList.addData(4);
        linkedList.addData(2);
        linkedList.addData(4);
        linkedList.addData(2);
        linkedList.showData();  // 1 3 3 1 4 2 4 2

        linkedList = removeDup(linkedList);
        linkedList.showData();  // 1 3 4 2

    }
}



// Practice2
// Palindrome 연결 리스트
// 추가 자료구조 없이 연결 리스트만으로 풀어보기 Practice1에서 만든 단일연결리스트 사용(내장 LinkedList말고)
// Palindrome: 앞으로 읽어도 뒤로 읽어도 같은 문자열

// 입력 예시)
// 입력 연결 리스트: 1, 3, 5, 3, 1
// 결과: true

// 입력 연결 리스트: 3, 5, 5, 3
// 결과: true

// 입력 연결 리스트: 1, 3, 5, 1
// 결과: false


public class Practice {
    public static boolean checkPalindrome(LinkedList list) {
        //여기에 코드 작성
        return false;
    }

    public static void main(String[] args) {
        // Test code
        LinkedList linkedList = new LinkedList();
        linkedList.addData(1);
        linkedList.addData(3);
        linkedList.addData(5);
        linkedList.addData(3);
        linkedList.addData(1);
        System.out.println(checkPalindrome(linkedList));

        LinkedList linkedList2 = new LinkedList();
        linkedList2.addData(3);
        linkedList2.addData(5);
        linkedList2.addData(5);
        linkedList2.addData(3);
        System.out.println(checkPalindrome(linkedList2));

        LinkedList linkedList3 = new LinkedList();
        linkedList3.addData(1);
        linkedList3.addData(3);
        linkedList3.addData(5);
        linkedList3.addData(1);
        System.out.println(checkPalindrome(linkedList3));

    }
}

// Practice3
// 연결 리스트 부분 뒤집기
// 주어진 연결 리스트에서 시작 위치부터 끝 위치 사이의 노드들을 뒤집으시오.

// 입력 예시)
// 입력 연결 리스트: 1, 2, 3, 4, 5
// 시작 위치: 2
// 끝 위치: 4
// (처음 위치는 1부터라고 가정)
// 결과 연결 리스트: 1, 4, 3, 2, 5


public class Practice3 {
    public static LinkedList reverseList(LinkedList list, int left, int right) {
        //여기에 코드 작성
        return list;
    }

    public static void main(String[] args) {
        LinkedList linkedList = new LinkedList();
        linkedList.addData(1);
        linkedList.addData(2);
        linkedList.addData(3);
        linkedList.addData(4);
        linkedList.addData(5);
        linkedList.showData();

        linkedList = reverseList(linkedList, 2, 4);
        linkedList.showData();


        LinkedList linkedList2 = new LinkedList();
        linkedList2.addData(1);
        linkedList2.addData(2);
        linkedList2.addData(3);
        linkedList2.addData(4);
        linkedList2.addData(5);
        linkedList2.addData(6);
        linkedList2.addData(7);
        linkedList2.showData();

        linkedList2 = reverseList(linkedList2, 3, 5);
        linkedList2.showData();

    }
}


