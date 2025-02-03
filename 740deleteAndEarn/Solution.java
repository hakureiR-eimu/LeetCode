import java.util.*;

class Solution {
    public int deleteAndEarn(int[] nums) {
        int maxVal = -1;
        for (int i : nums) {
            maxVal = Math.max(maxVal, i);
        }

        int[] sum = new int[maxVal + 1];
        for (int i : nums) {
            sum[i] += i;
        }
        return rob(sum);

    }

    public static int rob(int[] sum) {
        int f0 = 0;
        int f1 = 0;
        for (int x : sum) {
            int newF = Math.max(f1, f0 + x);
            f0 = f1;
            f1 = newF;
        }
        return f1;
    }
}