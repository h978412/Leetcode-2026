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
    vector<int> m;
    int maxLevelSum(TreeNode* root) {
        vector<int>m(10001,INT_MIN);
        this->dfs(root,1,m);
        int i=1;
        int level = 1;
        int maxSum = INT_MIN;
        while(m[i] != INT_MIN){
            if(m[i] > maxSum){
                maxSum = m[i];
                level = i;
            }
            i++;
        }
        return level;

    }
    void dfs(TreeNode* root, int level,vector<int>& m){
        if(!root) return;
        if(m[level] == INT_MIN) m[level] = root->val;
        else m[level] += root->val;
        this->dfs(root->left,level+1,m);
        this->dfs(root->right,level+1,m);
    }
};