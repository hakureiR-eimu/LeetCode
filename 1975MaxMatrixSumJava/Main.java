class Solution {
    public long maxMatrixSum(int[][] matrix) {
        /**
         * 如果有偶数个非负，可以转换成偶数个负
         * 如果有奇数个非负，取最靠近0的数
         */
        int n = matrix.length;
        long sum = 0;
        int notPostiveNum = 0;
        int minNotNegative=Integer.MAX_VALUE;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                sum += Math.abs(matrix[i][j]);
                if (matrix[i][j] <= 0) {
                    notPostiveNum++;
                }
            }
        }
        if (notPostiveNum % 2 == 0)
            return sum;
        else {
            for(int i=0;i<n;++i){
                for(int j=0;j<n;++j){
                    minNotNegative=Math.min(minNotNegative,Math.abs(matrix[i][j]));
                }
            }
            return sum-=minNotNegative*2;
        }
    }
}

class Main {
    public static void main(String[] args) {
        /**
         * 2,9,3
         * 5,4,-4
         * 1,7,1
         */
        int[][] matrix = new int[][] { { 2, 9, 3 }, { 5, 4, -4 }, { 1, 7, 1 } };
        Solution sol = new Solution();
        long res = sol.maxMatrixSum(matrix);
        System.out.println(res);
    }
}