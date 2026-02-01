class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int minEl = std::min(nums[1],nums[2]);
        int maxEl = std::max(nums[1],nums[2]);
        for(int i=3;i<nums.size();i++){
            if(nums[i]<maxEl){
                int storedMinVal = minEl;
                minEl = std::min(minEl,nums[i]);
                maxEl = std::max(storedMinVal,nums[i]);
            }
            cout << minEl << " " << maxEl << endl;
        }

        return maxEl + minEl + nums[0];

        // int num1 = nums[1], num2 = nums[2];
        // for(int i=3;i<nums.size();i++){
        //     if(num1 > nums[i]){
        //         int storedValue = num1;
        //         num1 = nums[i];
        //         num2 = storedValue < num2 ? storedValue : num2;
        //     }else if(num2 > nums[i]){
        //         int storedValue = num2;
        //         num2 = nums[i];
        //         num1 = storedValue < num1 ? storedValue : num1;                
        //     }
        // }


        // return (nums[0] + num1 + num2);
        
    }
};