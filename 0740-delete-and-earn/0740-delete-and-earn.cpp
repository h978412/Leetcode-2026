class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int>m(20001,0);
        for(int i=0;i<nums.size();i++){
            m[nums[i]] += nums[i];
        }
        int ans = 0;
        int prv = m[1];
        int prvprv = m[0];
        // ans = max(prv,prvprv);
        for(int i=2;i<m.size();i++){
            // int temp = prvprv;
            int temp = max(m[i]+prvprv,prv);
            prvprv = prv;
            prv = temp;
            // prvprv = 
            ans  = max(prv,prvprv);
        }
        return ans;
    }
};