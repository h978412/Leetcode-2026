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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        vector<pair<int,int>> m(501);
        this->rec(root,m);
        while(m[root->val].first != m[root->val].second){
            if(m[root->val].first > m[root->val].second ) root = root->left;
            else root = root->right;
            
        }
        return root;
    }
    int rec(TreeNode* root,vector<pair<int,int>>& m){
        if(root == NULL) return 0;
        int left = this->rec(root->left,m);
        int right = this->rec(root->right,m);
        m[root->val] = {left,right};
        return (max(left,right)+1);
    }
};