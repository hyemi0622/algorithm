class Solution {
    public int solution(String my_string, String is_suffix) {
        int same = is_suffix.length();
        String submy="";
        if(is_suffix.length()<=my_string.length())
            submy = my_string.substring(my_string.length()-same, my_string.length());
        int answer = 0;
        if(is_suffix.equals(submy)){
            answer=1;
        }
        return answer;
    }
}
