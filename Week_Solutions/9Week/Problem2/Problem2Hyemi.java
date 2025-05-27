import java.util.ArrayList;
class Solution {
    public int[] solution(int[] array, int[][] commands) {
        ArrayList<Integer> answer = new ArrayList();
        for(int [] com : commands){
            ArrayList<Integer> list = new ArrayList();
            for (int i = com[0]-1; i < com[1]; i++) {
                list.add(array[i]);
            }
            for (int i = 0; i < list.size()-1; i++) {
                int min = i;
                for (int j = i+1; j < list.size() ; j++) {
                    if(list.get(j)<list.get(min)){
                        min=j;
                    }
                }
                int temp= list.get(min);
                list.remove(min);
                list.add(min,list.get(i));
                list.remove(i);
                list.add(i,temp);
            }
            answer.add(list.get(com[2]-1));
        }
        int [] a = answer.stream().mapToInt(i->(int)i).toArray();
        return a;
    }
}
