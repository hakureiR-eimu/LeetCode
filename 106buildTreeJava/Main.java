import java.util.*;

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
    int[] inorder;
    int[] postorder;
    Map<Integer, Integer> inorderMap = new HashMap<>();
    Map<Integer, Integer> postMap = new HashMap<>();

    public TreeNode buildTree(int[] inorder, int[] postorder) {
        if (inorder.length == 0) return null;
        this.inorder = inorder;
        this.postorder = postorder;
        for (int i = 0; i < inorder.length; ++i) {
            inorderMap.put(inorder[i], i);
        }
        TreeNode root = help(0, inorder.length - 1, 0, postorder.length - 1);
        return root;
    }

    public TreeNode help(int inorderLeft, int inorderRight, int postLeft, int postRight) {
        if (postLeft > postRight || inorderLeft > inorderRight) return null;
        else if (postLeft == postRight) return new TreeNode(postorder[postRight]);
        else {
            TreeNode node = new TreeNode(postorder[postRight]);
            int inorderIndex = inorderMap.get(postorder[postRight]);
            int leftTreeNum = inorderIndex - inorderLeft;
            int rightTreeNum = inorderRight - inorderIndex;
            node.left = help(inorderLeft, inorderIndex - 1, postLeft, postLeft + leftTreeNum - 1);
            node.right = help(inorderIndex + 1, inorderRight, postLeft + leftTreeNum, postRight - 1);
            return node;
        }
    }
}