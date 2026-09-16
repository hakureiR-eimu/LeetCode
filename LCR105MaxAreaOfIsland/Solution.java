import java.util.Arrays;

class Solution {
    public int maxAreaOfIsland(int[][] grid) {
        if (grid.length == 0 || grid[0].length == 0) return 0;
        boolean[][] visited = new boolean[grid.length][grid[0].length];
        int maxArea = 0;
        for (int i = 0; i < grid.length; ++i) {
            for (int j = 0; j < grid[0].length; ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    int area = visit(grid, visited, i, j);
                    maxArea = Math.max(maxArea, area);
                }
            }
        }
        return maxArea;
    }

    private int visit(int[][] grid, boolean[][] visited, int i, int j) {
        if (visited[i][j] || grid[i][j] == 0) return 0;
        visited[i][j] = true;
        int upper = 0, button = 0, left = 0, right = 0;
        if (i - 1 >= 0) button = visit(grid, visited, i - 1, j);
        if (i + 1 < grid.length) upper = visit(grid, visited, i + 1, j);
        if (j - 1 >= 0) left = visit(grid, visited, i, j - 1);
        if (j + 1 < grid[0].length) right = visit(grid, visited, i, j + 1);
        return upper + button + left + right + 1;
    }
}