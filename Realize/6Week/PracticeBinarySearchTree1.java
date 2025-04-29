// 비선형 자료구조 - 이진 탐색 트리

import java.util.LinkedList;
import java.util.Queue;

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

    BinarySearchTree(int key) {
        this.head = new Node(key, null, null);
    }

    public void addNode(int key) {
        if(this.head==null){
            this.head=new Node(key,null,null);
        } else{
            Node cur = this.head;
            while(true){
                Node pre = cur;
                if(key<cur.key){
                    cur=cur.left;
                    if(cur==null){
                        pre.left=new Node(key,null,null);
                        break;
                    }
                }else{
                    cur=cur.right;
                    if(cur==null){
                        pre.right=new Node(key,null,null);
                        break;
                    }
                }
            }
        }
    }

    public void removeNode(int key) {
        Node parent=null; // 부모노드 쪽
        Node sucessor = null; //
        Node predecessor = null;
        Node child = null;

        Node cur = this.head;
        while(cur!=null){
            if(key==cur.key){
                break;
            }
            parent = cur;
            if(key<cur.key){
                cur=cur.left;
            } else{
                cur=cur.right;
            }
        }
        if(cur == null){
            System.out.println("key에 해당하는 노드 없음");
            return;
        }

        if(cur.left == null && cur.right == null){ //Leaf 노드인 경우
            if(parent == null){
                this.head = null;
            }else {
                if(parent.left==cur){
                    parent.left=null;
                } else {
                    parent.right = null;
                }
            }
        } else if(cur.left!=null && cur.right == null || cur.left==null && cur.right!=null){ //자식 노드가 하나인 경우
            if(cur.left!=null){
                child = cur.left;
            }else{
                child=cur.right;
            }
            if(parent==null){
                this.head=child;
            } else{
                if(parent.left==cur){
                    parent.left=child;
                } else{
                    parent.right=child;
                }
            }
        }
        else{ //자식 노드가 2개인 경우
            predecessor = cur;
            sucessor = cur.left; //좌측 서브트리에서 가장 큰 값을 가지게 될 애
            while(sucessor.right!=null){
                predecessor=sucessor;
                sucessor=sucessor.right;
            }
            predecessor.right=sucessor.left;
            sucessor.left=cur.left;
            sucessor.right=cur.right;
            if(parent==null){
                this.head=sucessor;
            } else{
                if(parent.left==cur){
                    parent.left=sucessor;
                } else {
                    parent.right=sucessor;
                }
            }
        }
    }

    public void levelOrder(Node node) {
        Queue<Node> queue = new LinkedList();
        queue.add(node);
        while (!queue.isEmpty()) {
            Node cur = queue.poll();

            System.out.print(cur.key + " ");
            if (cur.left != null) {
                queue.offer(cur.left);
            }

            if (cur.right != null) {
                queue.offer(cur.right);
            }
        }
        System.out.println();
    }

}


public class Main {
    public static void main(String[] args) {
        // Test code
        // 노드 삽입
        BinarySearchTree bst = new BinarySearchTree(20);
        bst.addNode(10);
        bst.addNode(30);
        bst.addNode(1);
        bst.addNode(15);
        bst.addNode(25);
        bst.addNode(13);
        bst.addNode(35);
        bst.addNode(27);
        bst.addNode(40);
        bst.levelOrder(bst.head);

        // 노드 삭제
        bst.removeNode(40);
        bst.levelOrder(bst.head);
        bst.removeNode(25);
        bst.levelOrder(bst.head);
        bst.removeNode(20);
        bst.levelOrder(bst.head);
    }
}
