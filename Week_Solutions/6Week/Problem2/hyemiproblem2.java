class Solution {
    public int solution(String before, String after) {
        int answer = 0;
        int [] checkbe = new int [before.length()];
        int [] checkaf = new int [after.length()];
        char [] be = before.toCharArray();
        char [] af = after.toCharArray();
        int cnt=0;
        for (int i = 0; i < be.length; i++) 
            for (int j = 0; j < af.length; j++) 
                if(be[i]==af[j] && checkbe[i]==0 && checkaf[j]==0){
                    checkbe[i]=1;
                    checkaf[j]=1;
                    cnt++;
                }
        if(cnt==after.length())
            answer=1;
        return answer;
    }
}
