class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        for(auto& num : nums){
            vector<int>temp;
            while(num){
                temp.push_back(num%10);
                num /= 10;
            }
            std::reverse(temp.begin(), temp.end());
            for(auto& val : temp){
                ans.push_back(val);
            }
        }
        return ans;
    }
};