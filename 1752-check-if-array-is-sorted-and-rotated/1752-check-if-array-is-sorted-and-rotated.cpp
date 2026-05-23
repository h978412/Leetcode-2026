class Solution {
public:
    bool check(vector<int>& nums) {
        int minima = -1;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1] > nums[i]){
                if(minima != -1) return false;
                else minima = i;
            }
        }
        if(minima == -1) return true;

        if(nums[0] >= nums[nums.size()-1]) return true;

        return false;


        
    }
};