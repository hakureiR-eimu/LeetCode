
public class Main {
}

class Solution {
    public boolean isGood(int[] nums) {
        int n = nums.length - 1;
        //1-n为有效位
        int[] map = new int[n + 1];
        for (int i = 1; i <= n; ++i) {
            if (i == n) {
                map[i] = 2;
            } else {
                map[i] = 1;
            }
        }
        for (int item : nums) {
            if (item > n | item < 1) {
                return false;
            } else {
                map[item]--;
                if (map[item] < 0) return false;
            }
        }
        return true;
    }
}