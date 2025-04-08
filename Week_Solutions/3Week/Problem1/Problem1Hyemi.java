import java.util.ArrayDeque;
import java.util.Deque;
class Solution {
    public int solution(int[] numbers, int k) {
        Deque deque = new ArrayDeque();
        for(int i:numbers){
            deque.add(i);
        }
        int num=-1;
        int j=0;
        while(j!=k){
            num=(int)deque.removeFirst();
            deque.addLast(num);
            int dup=(int)deque.removeFirst();
            deque.addLast(dup);
            j++;
        }
        return num;
    }
}
