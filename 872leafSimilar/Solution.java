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
    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        List<Integer> list1 = new ArrayList<Integer>();
        if(root1!=null) dfs(root1,list1);

        List<Integer> list2 = new ArrayList<Integer>();
        if(root2!=null) dfs(root2,list2);

        return list1.equals(list2);
    }

    void dfs(TreeNode root, List<Integer> list) {
        if (root == null) return;
        dfs(root.left, list);
        dfs(root.right, list);
        if (root.left == null && root.right == null) {
            list.add(root.val);
        }
    }
}