// Practice1
// 주어진 이진 탐색 트리에서 N 번째로 작은 수 구하기

// 입력 트리: 3, 1, 4, null, 2
// N: 1
// 결과: 1

// 입력 트리: 5, 3, 6, 2, 4, null, null, 1
// N: 3
// 결과: 3

import java.lang.reflect.Array;
import java.util.ArrayList;

class Node {
    int key;
    Node left;
    Node right;

    Node(int key, Node left, Node right) {
        this.key = key;
        this.left = left;
        this.right = right;
    }
}

class BinarySearchTree {
    Node head;

    BinarySearchTree() {}
    BinarySearchTree(int key) {
        this.head = new Node(key, null, null);
    }

    public void addNode(int key) {
        this.head = this.addNode(this.head, key);
    }

    public Node addNode(Node cur, int key) {
        if (cur == null) {
            return new Node(key, null, null);
        }

        if (key < cur.key) {
            cur.left = addNode(cur.left, key);
        } else {
            cur.right = addNode(cur.right, key);
        }

        return cur;
    }
}

public class Practice1 {
    public static void solution(Integer[] data, int n) {
        // 여기 코드 작성. 필요시 다른 함수 생성도 가능
    }
    
    public static void main(String[] args) {
        // Test code
        Integer[] data = {3, 1, 4, null, 2};
        int n = 1;
        solution(data, n);

        data = new Integer[]{5, 3, 6, 2, 4, null, null, 1};
        n = 3;
        solution(data, n);
    }
}


// Practice2
// 주어진 BST 에서 노드 간의 차이값 중 최소 값을 구하세요.

// 입력 트리: 4, 2, 6, 1, 3
// 출력: 1

// 입력 트리: 5, 1, 48, null, null, 12, 51
// 출력: 3

import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;

public class Practice2 {

    public static void solution(Integer[] data) {
       //코드 작성 필요시 함수 더 추가 가능

    }


    public static void main(String[] args) {
        // Test code
        Integer[] data = {3, 1, 4, null, 2};
        solution(data);

        data = new Integer[]{5, 1, 48, null, null, 12, 51};
        solution(data);
    }
}
