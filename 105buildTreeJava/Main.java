import java.util.*;

public class Main {
    public static void main(String[] args) {
        int[] preoder = {3, 9, 20, 15, 7};
        int[] inorder = {9, 3, 15, 20, 7};

        Solution sol = new Solution();
        TreeNode root = sol.buildTree(preoder, inorder);
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
    Map<Integer, Integer> inorderMap = new HashMap<>();

    public TreeNode buildTree(int[] preorder, int[] inorder) {
        if (preorder.length == 0) return null;
        for (int i = 0; i < inorder.length; ++i) {
            inorderMap.put(inorder[i], i);
        }

        TreeNode root = buildTree(preorder, inorder, 0, preorder.length - 1, 0, inorder.length - 1);
        //3 9 20 15 7
        //9 ,20 15 7
        //9 ,

        return root;
    }

    TreeNode buildTree(int[] preorder, int[] inorder, int preorderLeft, int preorderRight, int inorderLeft, int inorderRight) {
        if (preorderLeft > preorderRight) {
            return null;
        } else if (preorderLeft == preorderRight) {
            TreeNode node = new TreeNode(preorder[preorderLeft]);
            return node;
        } else {
            TreeNode root = new TreeNode(preorder[preorderLeft]);
            int pos = inorderMap.get(preorder[preorderLeft]);
            if (pos > inorderLeft) {
                int num = pos - inorderLeft;
                root.left = buildTree(preorder, inorder, preorderLeft + 1, preorderLeft + num, pos - num, pos - 1);
            }
            if (pos < inorderRight) {
                int num = inorderRight - pos;//4-1=3 4->2
                root.right = buildTree(preorder, inorder, preorderRight - num + 1, preorderRight, pos + 1, pos + num);
            }
            return root;
        }
    }
}