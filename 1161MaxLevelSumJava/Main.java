import java.util.ArrayDeque;
import java.util.Deque;

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
    public int maxLevelSum(TreeNode root) {
        Deque<TreeNode> dq = new ArrayDeque<>();
        if (root == null)
            return 0;
        dq.addLast(root);
        int depth = 1;
        long sumMax = Long.MIN_VALUE;
        int maxDepth = 1;
        while (!dq.isEmpty()) {
            long sumCur = 0;
            int n = dq.size();
            for (int i = 0; i < n; ++i) {
                TreeNode tn = dq.pollFirst();
                sumCur += tn.val;
                if (tn.left != null) {
                    dq.addLast(tn.left);
                }
                if (tn.right != null) {
                    dq.addLast(tn.right);
                }
            }
            if (sumCur > sumMax) {
                sumMax = sumCur;
                maxDepth = depth;
            }
            depth++;
        }
        return maxDepth;
    }
}

public class Main {
    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        TreeNode item = root;
        item.left = new TreeNode(7);
        item.right = new TreeNode(0);
        Solution sol = new Solution();
        int res = sol.maxLevelSum(root);
        System.out.println(res);
    }

}