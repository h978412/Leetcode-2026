class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,bool> s;
        for(int i=0;i<nums.size();i++){
            if(s.find(nums[i]) != s.end()){
                return true;
            }else{
                s[nums[i]] = true;
            }
        }
        return false;
    }
};