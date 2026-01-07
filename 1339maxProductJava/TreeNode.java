import java.util.ArrayDeque;
import java.util.Deque;
import java.util.HashMap;
import java.util.Map;

public class TreeNode {
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

/**
 * 1
 * null 2
 * 
 */
class Solution {
    Map<TreeNode, Long> map = new HashMap<>();

    public int maxProduct(TreeNode root) {
        long sum = getSum(root);
        dfs(root);
        Deque<TreeNode> queue = new ArrayDeque<>();
        queue.addLast(root);
        long max = Long.MIN_VALUE;
        while (!queue.isEmpty()) {
            int n = queue.size();
            for (int i = 0; i < n; ++i) {
                TreeNode item = queue.pollFirst();
                if (item.left != null && item.right != null) {
                    queue.addLast(item.left);
                    queue.addLast(item.right);
                    long left, right;
                    // 删除左边
                    left = map.get(item.left);
                    right = sum - left;
                    max = Math.max(left * right, max);
                    // 删除右边
                    right = map.get(item.right);
                    left = sum - right;
                    max = Math.max(left * right, max);
                } else if (item.left != null && item.right == null) {
                    queue.addLast(item.left);
                    // 删除左边
                    long left, right;
                    left = map.get(item.left);
                    right = sum - left;
                    max = Math.max(left * right, max);
                } else if (item.left == null && item.right != null) {
                    queue.addLast(item.right);
                    // 删除右边
                    long left, right;

                    right = map.get(item.right);
                    left = sum - right;
                    max = Math.max(left * right, max);
                } else {

                }
            }
        }

        return (int) (max % (1e9 + 7));
    }

    long dfs(TreeNode treeNode) {
        if (treeNode == null)
            return 0;
        else if (map.containsKey(treeNode))
            return map.get(treeNode);
        long left = dfs(treeNode.left);
        long right = dfs(treeNode.right);
        long sum = treeNode.val + left + right;
        map.put(treeNode, sum);
        return sum;
    }

    long getSum(TreeNode treeNode) {
        if (treeNode == null)
            return 0;
        long left = dfs(treeNode.left);
        long right = dfs(treeNode.right);
        long sum = treeNode.val + left + right;
        return sum;
    }
}

class Main {
    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        root.right = new TreeNode(2);
        root.right.left = new TreeNode(3);
        root.right.right = new TreeNode(4);
        root.right.right.left = new TreeNode(5);
        root.right.right.right = new TreeNode(6);
        Solution sol = new Solution();
        int res = sol.maxProduct(root);
        System.out.println(res);
    }
}