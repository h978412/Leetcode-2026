class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> track(n+1,0);
        for(int i=0;i<nums.size();i++){
            track[nums[i]]++;
        }
        vector<int> ans;
        for(int i=1;i<n+1;i++){
            if(track[i] == 0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};