class Solution {
public:
vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        this->rec(candidates,target,0,curr);
        return ans;
        
    }
    void rec(vector<int>& candidates, int target, int i, vector<int>& curr){
        if(target == 0){
            ans.push_back(curr);
            return;
        }
        if(i >= candidates.size()) return;
        this->rec(candidates,target,i+1,curr);
        if(candidates[i] <= target){
            curr.push_back(candidates[i]);
            this->rec(candidates,target-candidates[i],i,curr);
            curr.pop_back();

        }
    }
};