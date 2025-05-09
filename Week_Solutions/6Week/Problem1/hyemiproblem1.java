import java.util.*;
class Solution {
    public String solution(String s) {
        HashMap<Character,Integer>map = new HashMap<>();
        for(char item : s.toCharArray()){
            if(map.containsKey(item)){
                map.put(item,map.get(item)+1);
            } else{
                map.put(item,1);
            }
        }
        List list = new ArrayList();
        for(char set : map.keySet()){
            if(map.get(set)==1){
                list.add(set);
            }
        }
        Collections.sort(list);
        String result="";
        for (int i = 0; i < list.size(); i++) {
            result+=list.get(i);
        }
        return result;
    }
}
