class Solution {
public:
    int findMin(vector<int>& nums) {
        // if(nums[0] <= nums[nums.size()-1]) return nums[0];

        int i=0,j=nums.size()-1;
        while(i<j-1){
            int mid = (i+j)/2;
            if(nums[j] > nums[mid]){
                //right part is sorted, so minimum element is either mid or in left part
                j = mid;
            }else{
                //left part is sorted, so minimum will be either leftmost element or in the left array
                if(nums[i] < nums[j]) return nums[i];
                else i = mid;
            }
        }
        return min(nums[i],nums[j]);
        
    }
};