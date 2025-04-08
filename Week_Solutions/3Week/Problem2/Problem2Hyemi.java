import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        Deque<int[]> deque = new ArrayDeque<>();
        for (int i = 0; i < progresses.length; i++) {
            deque.add(new int[]{progresses[i], speeds[i]});
        }

        ArrayList<Integer> result = new ArrayList<>();

        while (!deque.isEmpty()) {
            for (int[] task : deque) {
                task[0] += task[1];  
            }

            int count = 0;
            while (!deque.isEmpty() && deque.peekFirst()[0] >= 100) {
                deque.pollFirst();  
                count++;
            }

            if (count > 0) {
                result.add(count);
            }
        }
        int[] arr1 = result.stream().mapToInt(i -> (int)i).toArray();
        return arr1;
    }
}
