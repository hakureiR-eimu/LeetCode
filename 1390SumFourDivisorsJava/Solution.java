class Solution {
    public int sumFourDivisors(int[] nums) {
        int res = 0;
        for (int i = 0; i < nums.length; ++i) {
            Divisor divisor = new Divisor(nums[i]);
            if (divisor.count == 4)
                res += divisor.sum;
        }
        return res;
    }

    class Divisor {
        int count = 0;
        int sum = 0;

        Divisor(int num) {
            for (int i = 1; i * i <= num; ++i) {
                if (num % i == 0) {
                    int small = i;
                    int large = num / i;
                    if (small == large) {
                        count++;
                        sum += small;
                    } else {
                        count += 2;
                        sum += small;
                        sum += large;
                    }
                }
            }
        }
    }

    public static void main(String[] args) {
        int[] nums = new int[] { 21, 4, 7 };
        Solution sol = new Solution();
        int res = sol.sumFourDivisors(nums);
        System.out.println(res);
    }
}