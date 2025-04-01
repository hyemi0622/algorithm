import java.util.*;
class Solution {
    public int[] solution(long n) {
        LinkedList list = new LinkedList<>();
        int digit = 1;
        long cur=n;
        while (cur > 0) {
            long data = cur % 10;
            list.add((int)data);
            cur = cur / 10;
        }
        int [] arr = list.stream().mapToInt(i -> (int)i).toArray();
        return arr;
    }
        
}
