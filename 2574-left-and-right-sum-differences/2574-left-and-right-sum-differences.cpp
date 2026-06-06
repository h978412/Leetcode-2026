class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int>ls(nums.size(),nums[0]);
        for(int i=1;i<nums.size();i++){
            ls[i] = ls[i-1] + nums[i];
        }
        int lsum = 0;
        for(int i=0;i<ls.size();i++){
            int temp = ls[i];
            ls[i] = abs(lsum - (ls[ls.size()-1] - ls[i]));
            lsum = temp;
        }
        return ls;

    }
};