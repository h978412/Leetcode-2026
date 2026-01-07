class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto num : nums) sum+= num;
        if(sum %2 !=0) return false;
        int targetSum = sum/2;
        vector<vector<int>> m(nums.size()+1,vector<int>(targetSum+1,-1));
        return this->rec(nums,nums.size(),targetSum,m);

    }
    bool rec(vector<int>& nums, int i, int targetSum,vector<vector<int>>& m){
        if(targetSum == 0) return true;
        if(i == 0) return false;

        if(m[i][targetSum] != -1)  return m[i][targetSum]==1?true:false;

        bool r1 = false, r2 = false;
        //if i chose the element
        if(nums[i-1] <=  targetSum){
            r1 = this->rec(nums,i-1,targetSum-nums[i-1],m);
        }

        //if i don't chose the element
        r2 = this->rec(nums,i-1,targetSum,m);
        m[i][targetSum] = (r1||r2)?1:0;
        return m[i][targetSum]==1?true:false;

    }
};