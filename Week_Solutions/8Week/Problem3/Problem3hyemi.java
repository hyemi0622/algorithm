import java.util.*;
class Solution {
    public int[] solution(int[] emergency) {
        int [] result = new int[emergency.length];
        PriorityQueue<Integer> pq = new PriorityQueue<>((x,y)->y-x);
        int i=1;
        for(int num : emergency){
            pq.offer(num);
        }
        HashMap<Integer,Integer>map = new HashMap<>();
        while(!pq.isEmpty()){
            map.put(pq.poll(),i);
            i++;
        }
        int check=0;
        while(check<result.length){
            result[check]=map.get(emergency[check]);
            check++;
        }
        return result;
    }
}
