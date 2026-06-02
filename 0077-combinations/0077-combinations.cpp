class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        this->rec(n,k,1,temp);
        return ans;
    }

    void rec(int n, int k, int i, vector<int>& temp){
        if(temp.size() == k) {ans.push_back(temp);return;}
        if(i > n) return;
        this->rec(n,k,i+1,temp);
        temp.push_back(i);
        this->rec(n,k,i+1,temp);
        temp.pop_back();
    }
};