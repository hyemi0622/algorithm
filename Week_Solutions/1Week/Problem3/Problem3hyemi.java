import java.util.ArrayList;
import java.util.Arrays;
class Solution {
    public int[] solution(int l, int r) {
        int num = l;
        int digit = 1;
        ArrayList<Integer> list = new ArrayList<>();
        while (num <= r) {
            boolean check = true;
            int temp = num;
            while (temp > 0) {
                int digitNum = temp % 10;
                if (digitNum != 0 && digitNum != 5) {
                    check = false;
                    break;
                }
                temp /= 10;
            }
            if (check) {
                list.add(num);
            }
            digit = 1;
            num++;
        }
        if(list.isEmpty()){
            list.add(-1);
        }
        int[] result = list.stream().mapToInt(i -> i).toArray();
        return result;
    }
}
