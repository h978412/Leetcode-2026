class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int low = INT_MAX;
        int high = INT_MIN;
        for(auto num : nums){
            low = min(low,num);
            high = max(high,num);
        }
        // long long diff = high-low;

        return 1LL*(high-low)*k; 
    }
};