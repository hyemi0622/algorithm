import java.util.*;
class Solution {
    public int solution(int[] scoville, int K) {
        int answer = 0;
        PriorityQueue<Integer>pq = new PriorityQueue<>();
        for(int num : scoville){
            pq.offer(num);
        }

        while(pq.peek()<K && pq.size()>=2) {
            int small1 = pq.poll();
            int small2 = pq.poll();
            pq.offer(small1+(small2*2));
            answer++;
            if(pq.peek()<K && pq.size()<2){
                answer=-1;
            }
        }
        return answer;
    }
}
