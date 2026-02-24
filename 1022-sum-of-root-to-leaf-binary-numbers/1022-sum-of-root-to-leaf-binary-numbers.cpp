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
    int ans = 0;
public:
    int sumRootToLeaf(TreeNode* root) {
        this->preorder(root,0);
        return ans;
    }
    void preorder(TreeNode* root, int sum){
        if(root == NULL) return;
        int val = root->val;
        sum = sum*2 + val;
        this->preorder(root->left,sum);
        this->preorder(root->right,sum);

        if(root->left == NULL && root->right == NULL) ans += sum;
    }
};