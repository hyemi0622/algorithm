using System;

public class Solution {
    public int solution(int[] number) {
        int answer = 0;
        int size = number.Length;
        int a = 0, b = 1, c = 2;
        if(number[a]+number[b]+number[c] == 0){
               answer++;
        }
                
        while((a != size-3) || (b != size-2) || (c != size-1)){  
            if((a == size-3) && (b == size-2) && (c == size-1))
                break;
            else if((b == size-2) && (c == size-1)){
                a++;
                b = a+1;
                c = a+2;
            }
            else if((c == size-1)){
                b++;
                c = b+1;
            }
            else {
                c++;
            }
            if(number[a]+number[b]+number[c] == 0){
                answer++;
            }
        }
        return answer;
    }
}
