public class Main {
}

class Solution {
    public int numIslands(char[][] grid) {
        if (grid == null || grid.length == 0 || grid[0].length == 0) return 0;
        int ans = 0;
        int[][] visited = new int[grid.length][grid[0].length];
        for (int i = 0; i < grid.length; ++i) {
            for (int j = 0; j < grid[0].length; ++j) {
                ans += dfs(visited, grid, i, j);
            }
        }
        return ans;
    }

    public static int dfs(int[][] visited, char[][] grid, int i, int j) {
        if (i < 0 || i >= grid.length || j < 0 || j >= grid[0].length) return 0;
        if (grid[i][j] == '0' || visited[i][j] == 1) return 0;
        else {
            visited[i][j] = 1;
            dfs(visited, grid, i + 1, j);
            dfs(visited, grid, i - 1, j);
            dfs(visited, grid, i, j + 1);
            dfs(visited, grid, i, j - 1);
            return 1;
        }
    }
}