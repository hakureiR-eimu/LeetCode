public class Main {
    public static void main(String[] args) {
        char[][] board = {{'a'}, {'a'}};
        String word = "aaa";
        Solution sol = new Solution();
        boolean ans = sol.exist(board, word);
        System.out.println(ans);
    }
}

class Solution {
    public boolean exist(char[][] board, String word) {

        for (int i = 0; i < board.length; ++i) {
            for (int j = 0; j < board[0].length; ++j) {
                boolean[][] visited = new boolean[board.length][board[0].length];
                visited[i][j] = true;
                if (check(board, word, 0, i, j, visited)) return true;
            }
        }
        return false;
    }

    boolean check(char[][] board, String word, int s, int i, int j, boolean[][] visited) {
        if (board[i][j] != word.charAt(s)) {
            return false;
        } else if (s == word.length() - 1) return true;
        int rows = board.length, cols = board[0].length;
        boolean result = false;
        int[][] dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (int[] dir : dirs) {
            int dx = i + dir[0], dy = j + dir[1];
            if (dx >= 0 && dx < rows && dy >= 0 && dy < cols && !visited[dx][dy]) {
                visited[dx][dy] = true;
                boolean flag = check(board, word, s + 1, dx, dy, visited);
                if (flag) {
                    return true;
                }
                visited[dx][dy] = false;
            }
        }
        return false;
    }
}