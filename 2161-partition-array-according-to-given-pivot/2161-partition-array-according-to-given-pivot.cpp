class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans(nums.size());
        int pt = 0;
        for(auto num : nums){
            if(num < pivot) {ans[pt] = num;pt++;}
        }
        for(auto num : nums){
            if(num == pivot) {ans[pt] = num;pt++;}
        }
        for(auto num : nums){
            if(num > pivot) {ans[pt] = num;pt++;}
        }
        return ans;
    }
};