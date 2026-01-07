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
    int MOD = 1000000007;
    int maxProduct(TreeNode* root) {
        int totalSum = this->sum(root);
        long long maxProduct = 0;
        this->maxSum(root,totalSum,maxProduct);
        return maxProduct%MOD;
    }
    int maxSum(TreeNode* root, int& totalSum, long long& maxProduct){
        if(root == NULL) return 0;
        int sum = root->val + this->maxSum(root->left,totalSum,maxProduct) + maxSum(root->right,totalSum,maxProduct);
        long long product = (long long)(totalSum-sum)* (long long)sum;
        maxProduct = product>maxProduct ? product : maxProduct;
        return sum;
    }
    int sum(TreeNode* root){
        if(root == NULL) return 0;
        return root->val + this->sum(root->left) + this->sum(root->right);
    }

};