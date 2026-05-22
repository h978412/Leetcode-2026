class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1;
        while(i<=j){
            int mid = (i+j)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < nums[j]){
                //Right sorted
                if(target >= nums[mid] && target <= nums[j]) i =mid+1;
                else j = mid-1;
            }else{
                //Left sorted
                if(target >= nums[i] && target <= nums[mid]) j = mid-1;
                else i = mid+1;
            }
        }
        return -1;
    }
};