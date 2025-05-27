import java.util.*;

class Solution {
    public int[] solution(int[] arr) {
       ArrayList<Integer>list = new ArrayList<>();
       int first=-1;
       for(int i=0;i<arr.length;i++){
           if(arr[i]==2){
               first=i;
               break;
           }
       }
       int end=-1;
       if(first!=-1)
         for(int i=first;i<arr.length;i++)
              if(i!=first && arr[i]==2)
                 end = i;
       if(first!=-1)
            for (int i = first; i <= end; i++) {
                   list.add(arr[i]);
            }
       if(list.isEmpty()){
           list.add(-1);
       }
       if(first!=-1 && end==-1){
           list.clear();
           list.add(2);
       }
       int [] result = list.stream().mapToInt(i -> i).toArray();
       return result;
    }
}
