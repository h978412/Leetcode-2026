class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long long low = nums[0];
        long long high = nums[nums.size()-1];

        return (high-low)*k; 
    }
};