class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i =0 ,j=0;
        while(j<nums.size()){
            if(nums[j] != 0){
            // cout << j << endl;
                while(i<j){
                    // cout << i << " " << j <<endl;
                    if(nums[i] == 0){
                        int temp = nums[i];
                        nums[i] = nums[j];
                        nums[j] = temp;
                        break;
                    }
                    i++;
                }
            }
            j++;
        }
        
    }
};