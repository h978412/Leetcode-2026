class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        int zeroCount = 0;
        int zeroPosition = -1;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0){
                zeroCount++;
                zeroPosition = i;
            }else{
                product *= nums[i];
            }
        }
        // cout<< zeroPosition << endl;
        if(zeroCount > 1){
            return vector<int>(nums.size(),0);
        }else if(zeroCount > 0){
             vector<int>ans(nums.size(),0);
             ans[zeroPosition] = product;
             return ans;
        }
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            ans.push_back(product/nums[i]);
        }
        return ans;
        
    }
};