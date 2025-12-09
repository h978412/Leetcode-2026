class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int j=0,k;
        bool isFound = false;
        for(int i=1;i<nums.size();i++){
            nums[i] += nums[i-1];
            if(!isFound && nums[i] >= target){
                k = i; 
                isFound = true;
            }
        }
        if(nums[nums.size()-1] == target) return nums.size();
        if(!isFound) return 0;
        int ans = k+1;

        while(j<nums.size() && k< nums.size()){
            if(nums[k]-nums[j] >= target){
                ans = min(ans,(k-j));
                j++;
            }else{
                k++;
            }
        }

        return ans;
        

    }
};