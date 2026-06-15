/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int count = 0;
    int ans;
    int k;
    // boolean isFound = false;
    public int kthSmallest(TreeNode root, int k) {
        this.k = k;
        this.func(root);
        return this.ans;
    }
    void func(TreeNode root){
        if(root == null) return;
        this.func(root.left);
        this.count++;
        if(this.count ==  this.k) this.ans = root.val;
        this.func(root.right);
    }
}