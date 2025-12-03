class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<nums.size()-2;i++){
            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }
            int j=i+1,k=nums.size()-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k]; 
                if(sum == 0){
                    ans.push_back(vector<int>{nums[i],nums[j],nums[k]});
                    do{
                        j++;
                    }while(j<k && nums[j] == nums[j-1]);
                    do{
                        k--;
                    }while(k>j && nums[k+1] == nums[k]);

                }else if(sum > 0){
                    k--;
                }else{
                    j++;
                }
            }
        }
        return ans;
    }
};