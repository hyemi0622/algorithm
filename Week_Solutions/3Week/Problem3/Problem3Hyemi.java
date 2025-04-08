import java.util.HashMap;
class Solution {
    public int solution(String[][] clothes) {
         HashMap<String, Integer> clothesMap = new HashMap<>();
        for(String [] clo : clothes){
            clothesMap.put(clo[1],clothesMap.getOrDefault(clo[1],0)+1);
        }
        int answer=1;
        for(int cnt : clothesMap.values()){
            answer=answer*(cnt+1);
        }
        return answer-1;
    }
}
