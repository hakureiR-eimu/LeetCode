import java.util.*;

class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        int lineNum = matrix.length;
        int colNum = matrix[0].length;
        List<Integer> ans = new ArrayList<>();
        int left = 0, right = colNum - 1;
        int top = 0, button = lineNum - 1;
        while (left <= right && top <= button) {
            for (int i = left; i <= right; ++i) ans.add(matrix[top][i]);
            top++;
            for (int i = top; i <= button; ++i) ans.add(matrix[i][right]);
            right--;
            if (top <= button)
                for (int i = right; i >= left; --i) ans.add(matrix[button][i]);
            button--;
            if (left <= right)
                for (int i = button; i >= top; --i)
                    ans.add(matrix[i][left]);
            left++;
        }
        return ans;
    }
}