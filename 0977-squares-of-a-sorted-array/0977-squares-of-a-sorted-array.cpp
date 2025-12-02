class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i=0,j=0;
        bool isFound = false;
        nums[0] = nums[0]*nums[0];
        for(int i=1;i<nums.size();i++){
            nums[i] = nums[i]*nums[i];
            if(nums[i] > nums[i-1] && !isFound){
                isFound = true;
                j = i-1;
            }
        }
        vector<int>ans;
        if(!isFound){
            j= nums.size()-1;
            while(j>=0){
                ans.push_back(nums[j]);
                j--;
            }
            return ans;
        }
        i = j+1;
        // cout << i << " " << j << endl;
        while(i<nums.size() && j >= 0){
            if(nums[i] >= nums[j]){
                ans.push_back(nums[j]);
                j--;
            }else{
                ans.push_back(nums[i]);
                i++;
            }
        }
        while(i<nums.size()){
            ans.push_back(nums[i]);
            i++;
        }

        while(j>=0){
            ans.push_back(nums[j]);
            j--;
        }
        return ans;
        
        
    }
};