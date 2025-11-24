class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int,int> hash;
        for(int i=0;i<nums.size();i++){
            int findVal = (target-nums[i]);
            auto it = hash.find(findVal);
            if(it != hash.end()){
                return vector<int>{hash[findVal], i};
            }
            hash[nums[i]] = i;
        }
        
    return vector<int>{1,2};
    }
};