import java.util.ArrayList;
class Solution {
    public String[] solution(String[] strings, int n) {
        ArrayList<Character> list = new ArrayList<>();
        for (int i = 1; i < strings.length; i++) {
            for (int j = 0; j < strings.length-i; j++) {
                char [] temp1 = strings[j].toCharArray();
                char [] temp2 = strings[j+1].toCharArray();
                if(temp1[n]>temp2[n]){
                    String strtemp = strings[j];
                    strings[j]=strings[j+1];
                    strings[j+1]=strtemp;
                } else if(temp1[n]==temp2[n]){
                    if(strings[j].compareTo(strings[j+1])>0){
                        String temp = strings[j];
                        strings[j]=strings[j+1];
                        strings[j+1]=temp;
                    }
                }
            }
        }
        return strings;
    }
}
