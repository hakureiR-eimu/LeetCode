class Solution {
    public int minimumOperations(int[][] grid) {
        int count = 0;
        int lineNum = grid.length, colNum = grid[0].length;
        for (int i = 0; i < colNum; ++i) {
            int num = grid[0][i];
            for (int j = 1; j < lineNum; ++j) {
                int operationNum = 0;
                if (grid[j][i] <= num) {
                    operationNum = num - grid[j][i] + 1;
                    grid[j][i] = num + 1;
                }
                num = grid[j][i];
                count += operationNum;
            }
        }
        return count;
    }
}