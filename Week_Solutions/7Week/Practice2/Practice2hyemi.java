import java.util.*;

class Solution {
    public int solution(int[] d, int budget) {
       int result=d.length;
       ArrayList<Integer>list=new ArrayList<>();
       int sum=0;

       for(int num : d) {
           sum += num;
           list.add(num);
       }
       Collections.sort(list,Collections.reverseOrder());
       int check=0;
       int max;
       while (sum>budget) {
           max=list.get(0);
           list.remove(0);
           sum = sum - max;
           if (sum <= budget) {
               result = result - check-1;
               break;
           }
           else{
               check++;}
           }

           return result;
    }
}
