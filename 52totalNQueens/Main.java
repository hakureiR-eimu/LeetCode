public class Main {
    public static void main(String[] args) {
        int n = 4;
        Solution sol = new Solution();
        int ans = sol.totalNQueens(4);
        System.out.println(ans);
    }
}

class Solution {
    int ans=0;

    public int totalNQueens(int n) {
        int[][] path = new int[n][n];
        backTrace(n, 0, path);
        return ans;
    }

    void backTrace(int n, int row, int[][] path) {
        if (row == n) {
            ans++;
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (isValid(path, row, i)) {
                path[row][i] = 1;
                backTrace(n, row + 1, path);
                path[row][i] = 0;
            }
        }
    }

    boolean isValid(int[][] path, int row, int col) {
        for (int i = 0; i < row; ++i) {
            if (path[i][col] == 1) return false;
        }

        for (int i = row - 1, j = col + 1; i >= 0 && j < path.length; --i, ++j) {
            if (path[i][j] == 1) return false;
        }

        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
            if (path[i][j] == 1) return false;
        }

        return true;
    }

}