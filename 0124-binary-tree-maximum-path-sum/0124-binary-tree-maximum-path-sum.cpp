/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxSum = INT_MIN;
    int maxPathSum(TreeNode* root) {
        this->rec(root);
        return maxSum;
        
    }
    int rec(TreeNode* root){
        if(!root) return 0;
        int leftSum = this->rec(root->left) + root->val;
        int rightSum = this->rec(root->right) + root->val;
        int sideSum = max(max(leftSum,rightSum),root->val);

        // maxSum = max(maxSum,root->val);
        maxSum = max(maxSum,sideSum);
        maxSum = max(maxSum,leftSum+rightSum-root->val);
        return sideSum;
    }
};