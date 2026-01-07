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
    int maxProduct(TreeNode* root) {
        long long mval = INT_MIN;
        long long tsum= totalsum(root);
        func(root,mval,tsum);
        int mod = pow(10,9) + 7;
        return mval%mod;
    }
    long long totalsum(TreeNode* root){
        if(root==NULL) return 0;
        long long sum=0;
        sum += totalsum(root->left);
        sum+=root->val;
        sum += totalsum(root->right);
        return sum;
    }
    long long func(TreeNode* root,long long& mval,long long& tsum){
        if(root==NULL) return 0;
        long long sum =0;
        sum+=func(root->left,mval,tsum);
        sum+=func(root->right,mval,tsum);
        sum+=root->val;
        mval = max(mval,((tsum-sum)*sum));
        return sum;
    }
};