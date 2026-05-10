class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        vector<int>m(nums.size(),0);
        for(int i=nums.size()-2;i>=0;i--){
            int maxjump = -1;
            for(int j=i+1;j<nums.size();j++){
                if(abs(nums[i]-nums[j]) <= target && m[j] != -1){
                    maxjump = max(maxjump, m[j]+1);
                }
            }
            m[i] = maxjump;
        }

        for(auto val : m){
            cout << val << " ";
        }
        return m[0];   
    }
};