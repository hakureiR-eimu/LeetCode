import java.util.*;

public class Main {
    public static void main(String[] args) {
        TreeNode root = new TreeNode(3);
        root.left = new TreeNode(9);
        root.right = new TreeNode(20);
        Solution sol = new Solution();
        List<List<Integer>> ans = sol.zigzagLevelOrder(root);
        System.out.println(ans.toString());
    }
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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<>();

        Deque<TreeNode> que = new LinkedList<>();
        if (root == null) return ans;
        que.addLast(root);
        int sign = 1;
        while (!que.isEmpty()) {
            List<Integer> item = new ArrayList<>();
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                TreeNode node = que.pollFirst();
                item.add(node.val);
                if (node.left != null) que.addLast(node.left);
                if (node.right != null) que.addLast(node.right);
            }
            if (sign == -1) {
                Collections.reverse(item);
            }
            ans.add(item);
            sign = -sign;
        }
        return ans;
    }
}