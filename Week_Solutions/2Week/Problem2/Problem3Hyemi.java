import java.util.*;

class Solution {
    boolean solution(String s) {
        Stack<String> stack = new Stack<>();
        
        for(String str : s.split("")){
            if(str.equals("(")){
                stack.push(str);
            } else{
                if(stack.isEmpty()){
                    return false;
                } else{
                        stack.pop();
                }
            }
        }
        if(stack.isEmpty()){
            return true;
        } else {
            return false;
        }
    }
}
