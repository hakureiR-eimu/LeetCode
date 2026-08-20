import java.util.Arrays;

class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        //K的范围 [1,piles.max]
        //K的范围[left,right]
        //寻找最小K 使得K.t<=h
        Arrays.sort(piles);
        int max = piles[piles.length - 1];

        int left = 1, right = max;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int t = 0;
            for (int i = 0; i < piles.length; ++i) {
                if (piles[i] % mid == 0) {
                    t += piles[i] / mid;
                } else {
                    t += piles[i] / mid + 1;
                }
            }
            //mid可能是最小K，排除掉[mid+1,right]
            if (t <= h) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    public static void main(String[] args) {
        int[] piles = {30, 11, 23, 4, 20};
        int h = 5;
        Solution sol = new Solution();
        System.out.println(sol.minEatingSpeed(piles, h));
    }
}