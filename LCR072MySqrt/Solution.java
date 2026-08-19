class Solution {
    public int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }
        if (x == 1) {
            return 1;
        }
        //在[1,x]寻找第一个v使得v*v>x 返回v-1
        int left = 1, right = x;
        while (left < right) {
            long mid = left + (right - left) / 2;
            if (mid * mid > x) {
                right = (int) mid;
            } else {
                left = (int) mid + 1;
            }
        }
        return left - 1;
    }
}