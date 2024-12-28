import java.util.*;

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

    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> list = new ArrayList<>();
        if (root == null) return list;
        Queue<TreeNode> que = new ArrayDeque<>();
        que.offer(root);
        while (!que.isEmpty()) {
            int size = que.size();
            TreeNode node = null;
            for (int i = 0; i < size; ++i) {
                node = que.poll();
                if (node.left != null) que.add(node.left);
                if (node.right != null) que.add(node.right);
            }
            list.add(node.val);
        }
        return list;
    }
}