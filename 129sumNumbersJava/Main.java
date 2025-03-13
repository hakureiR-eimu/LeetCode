public class Main {
}

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {
    }

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {

    public int sumNumbers(TreeNode root) {
        return dfs(root, 0);
    }

    private int dfs(TreeNode root, int ans) {
        if (root.left == null && root.right == null) {
            return ans * 10 + root.val;
        } else if (root.left == null) {
            int next = 10 * ans + root.val;
            return dfs(root.right, next);
        } else if (root.right == null) {
            int next = 10 * ans + root.val;
            return dfs(root.left, next);
        } else {
            int next = 10 * ans + root.val;
            return dfs(root.left, next) + dfs(root.right, next);
        }
    }
}