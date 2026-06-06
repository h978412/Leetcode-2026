class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int>ls(nums.size());
        vector<int>rs(nums.size());
        int lsum = 0;
        int rsum = 0;
        for(int i=0;i<nums.size();i++){
            ls[i] = lsum;
            rs[nums.size()-i-1] = rsum;
            lsum += nums[i];
            rsum += nums[nums.size()-i-1];
        }

        vector<int> ans(nums.size());
        for(int i=0;i<nums.size();i++){
            ans[i] = abs(ls[i] - rs[i]);
        }

        return ans;



        
    }
};