public class Main {
    public static void main(String[] args) {

    }
}

class Solution {
    public int[] getNoZeroIntegers(int n) {
        for (int i = 1; i < n; ++i) {
            if (isHaveZero(i) && isHaveZero(n - i)) {
                int[] result = new int[2];
                result[0] = i;
                result[1] = n - i;
                return result;
            }
        }
        return null;
    }

    boolean isHaveZero(int num) {
        if (num == 0) return true;
        if (num % 10 == 0) return false;
        return isHaveZero(num / 10);
    }
}