class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        for(int i=1;i<nums.size();i++){
            nums[i] = nums[i-1] + nums[i];
        }
        int lsum = 0;
        for(int i=0;i<nums.size();i++){
            int temp = nums[i];
            nums[i] = abs(lsum - (nums[nums.size()-1] - nums[i]));
            lsum = temp;
        }
        return nums;

    }
};