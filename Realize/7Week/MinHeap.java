import java.util.ArrayList;

// 비선형자료구조 - 힙
// ArrayList 로 최소 힙 구현
class MinHeap{
    ArrayList<Integer>heap;
    public MinHeap(){
        this.heap=new ArrayList<>();
        this.heap.add(0);
    }public void insert(int data){
        heap.add(data);
        int cur=heap.size()-1;
        while(cur>1 && heap.get(cur/2)>heap.get(cur)){ //cur>1 인 이유는  heap의 0번째는 더미값이기 때문  부모노드 값이 더 클 때 반복 진행
            int parentVal = heap.get(cur/2);
            heap.set(cur/2,data);
            heap.set(cur,parentVal);
            cur/=2; //위쪽으로 올라가서 다시 체크
        }
    }
    public void printTree(){
        for (int i = 1 ; i < this.heap.size() ; i++) {
            System.out.print(this.heap.get(i)+" ");
        }
        System.out.println();
    }

    public Integer delete(){
        if(heap.size()==1){
            System.out.println("Heap is empty!");
            return null;
        }
        int target = heap.get(1);
        heap.set(1,heap.get(heap.size()-1));
        heap.remove(heap.size()-1);
        int cur =1;
        while(true){
            int leftIdx=cur*2;
            int rightIdx=cur*2+1;
            int targetIdx = -1;

            if(rightIdx<heap.size()){
                targetIdx = heap.get(leftIdx)<heap.get(rightIdx)?leftIdx:rightIdx;
            } else if(leftIdx<heap.size()){
                targetIdx = cur * 2;
            }else{
                break;
            }
            if(heap.get(cur)<heap.get(targetIdx)){
                break;
            } else{
                int parentVal = heap.get(cur);
                heap.set(cur,heap.get(targetIdx));
                heap.set(targetIdx,parentVal);
                cur=targetIdx;
            }
        }
        return target;
    }
}

public class Main {
    public static void main(String[] args) {
        // Test code
        MinHeap minHeap = new MinHeap();
        System.out.println("== 데이터 삽입 ==");
        minHeap.insert(30);
        minHeap.insert(40);
        minHeap.insert(10);
        minHeap.printTree();
        minHeap.insert(50);
        minHeap.insert(60);
        minHeap.insert(70);
        minHeap.printTree();
        minHeap.insert(20);
        minHeap.printTree();
        minHeap.insert(30);
        minHeap.printTree();

        System.out.println();
        System.out.println("== 데이터 삭제 ==");
        System.out.println("삭제: " + minHeap.delete());
        minHeap.printTree();
        System.out.println("삭제: " + minHeap.delete());
        minHeap.printTree(); 
        System.out.println("삭제: " + minHeap.delete());
        minHeap.printTree();
    }
}
