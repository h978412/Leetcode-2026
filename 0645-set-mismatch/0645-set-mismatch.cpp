class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            sum += nums[i];
        }
        int repeat;

        for(int i=0;i<n;i++){
            if(nums[abs(nums[i])-1] < 0){
                repeat = abs(nums[i]);
                break;
            }
            nums[abs(nums[i])-1] *= -1;

        }
        int expectedSum = (n*(n+1))/2;

        return vector<int>{repeat,repeat+ expectedSum-sum};
        
    }
};