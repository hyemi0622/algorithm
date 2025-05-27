class Solution {
    public long solution(long n) {
        long answer = 0;
        String str = Long.toString(n);
        char [] c = str.toCharArray();
        for(int i=1;i<c.length;i++){
            for (int j = i; j > 0 ; j--) {
                if(c[j]>c[j-1]){
                    char temp=c[j];
                    c[j]=c[j-1];
                    c[j-1]=temp;
                }
            }
        }
        for (int i = 0; i < c.length; i++) {
            answer=answer*10+(int)(c[i]-48);
        }
        return answer;
    }
}
