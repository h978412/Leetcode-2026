class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int prefix = 0;
        int count = 0;
        for(int i=0;i<nums.size();i++){
            prefix += nums[i];
            if(prefix == k) count++;
            if(m.find((prefix-k)) != m.end()) count += m[(prefix-k)];
            if(m.find(prefix) != m.end()) m[prefix] += 1;
            else m[prefix] = 1;
        }
        return count;
    }
};