class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        for(int i=1;i<nums.size();i++){
            nums[i] = nums[i] + nums[i-1];
        }
        // double avg = nums[k-1]/k;
        int maxEl = nums[k-1];
        for(int i=k;i<nums.size();i++){
            int sum = nums[i]-nums[i-k];
            maxEl = std::max(maxEl,sum);
        }
        return (double(maxEl)/double(k));
    }
};