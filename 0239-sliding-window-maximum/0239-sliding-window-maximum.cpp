class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int,int> m;
        for(int i=0;i<k;i++){
            m[nums[i]] += 1;
        }
        vector<int>ans;
        ans.push_back(m.rbegin()->first);
        for(int i=k;i<nums.size();i++){
            m[nums[i-k]] -= 1;
            if(!m[nums[i-k]]) m.erase(nums[i-k]);
            // s.erase(s.find(nums[i-k]));
            m[nums[i]] += 1;
            ans.push_back(m.rbegin()->first);
        }
        return ans;
    }
};