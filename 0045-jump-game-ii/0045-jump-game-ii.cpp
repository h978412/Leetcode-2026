class Solution {
public:
    int jump(vector<int>& nums) {
        int pt = nums.size()-1;
        nums[pt] = 0;
        for(int i=nums.size()-2;i>=0;i--){
            int step = nums[i+1]+1;
            int lastIndex = i+nums[i];
            if(lastIndex >= nums.size()-1){
                nums[i] = 1;
                continue;
            }
            for(int j=i+1;j<=(i+nums[i]);j++){
                step = min(step,(nums[j]+1));
            }
            nums[i] = step;
        }
        return nums[0];
        
    }
};