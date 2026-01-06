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
    int maxLevelSum(TreeNode* root) {  
        unordered_map<int,int> m;
        queue<pair<TreeNode*, int>> q;
        q.push({root,1});
        while(!q.empty()){
            TreeNode* node = q.front().first; 
            if(node){
                int level = q.front().second;
                q.push({node->left,level+1});
                q.push({node->right,level+1});
                if(m.find(level) != m.end()){
                    m[level] += node->val;
                }else{
                    m[level] = node->val;
                }
            }
            q.pop();
        }
        int i=1;
        int maxSum = INT_MIN;
        int level = 1;
        while(m.find(i) != m.end()){
            if(m[i] > maxSum){
                level = i;
                maxSum = m[i];
            }
            i++;
        }
        return level;
    }
};