class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int num1 = nums[1], num2 = nums[2];
        for(int i=3;i<nums.size();i++){
            if(num1 > nums[i]){
                int storedValue = num1;
                num1 = nums[i];
                num2 = storedValue < num2 ? storedValue : num2;
            }else if(num2 > nums[i]){
                int storedValue = num2;
                num2 = nums[i];
                num1 = storedValue < num1 ? storedValue : num1;                
            }
        }


        return (nums[0] + num1 + num2);
        
    }
};