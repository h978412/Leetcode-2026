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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,pair<TreeNode*,bool>> m;
        // unordered_map<int,bool> mp;
        for(auto des : descriptions){
            int p = des[0];
            int c = des[1];
            bool isLeft = des[2];
            TreeNode* parent; TreeNode* child;
            if(m.find(p) != m.end()){
                parent = m[p].first;
            }else{
                parent = new TreeNode(p);
                m[p] = {parent,false};
            }

            if(m.find(c) != m.end()){
                child = m[c].first;
                m[c].second = true;
                
            }else{
                child = new TreeNode(c);
                m[c] = {child,true};
            }

            if(isLeft) parent->left = child;
            else parent->right = child;
        }

        for(auto const & [key, val] : m){
            if(val.second == false) return val.first;
        }

        return NULL;
        
    }
};