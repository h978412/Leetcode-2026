class Solution {
public:
    bool canJump(vector<int>& nums) {
        int lp = nums.size()-1;
        for(int i=nums.size()-2;i>=0;i--){
            if(i+nums[i] >= lp){
                lp = i;
            }
        }
        return (lp == 0);
    }
};