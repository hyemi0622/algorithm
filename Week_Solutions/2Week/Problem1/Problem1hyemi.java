import java.util.*;

public class Solution {
    public int[] solution(int []arr) {
        ArrayList list = new ArrayList();
        Stack<Integer> stack = new Stack();
        for(Integer num : arr){
            if(stack.isEmpty()){
                stack.push(num);
            }
            else if(stack.peek()!=num){
                stack.push(num);
            }
        }
        while(!stack.isEmpty()){
            list.add(stack.pop());
        }
        Collections.reverse(list);
        int[] arr1 = list.stream().mapToInt(i -> (int)i).toArray();
        return arr1;
    }
}
