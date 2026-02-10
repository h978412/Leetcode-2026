class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            int oddCount = 0, evenCount = 0;
            vector<bool> map(100001,false);
            for(int j=i;j<nums.size();j++){
                if(!map[nums[j]]){
                    map[nums[j]] = true;
                    if((nums[j] & 1)) oddCount++;
                    else evenCount++;
                }
                if(oddCount == evenCount) ans  = max(ans,j-i+1);
            }
        }
        return ans;
        
    }
};