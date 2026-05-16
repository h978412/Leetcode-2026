class Solution {
public:
    int findMin(vector<int>& nums) {
        return this->rec(nums,0,nums.size()-1);
    }

    int rec(vector<int>&nums,int i, int j){
        if(i == j) return nums[i];
        if(i==j-1) return std::min(nums[i],nums[j]);
        int mid = (i+j)/2;
        if(nums[j] > nums[mid]){
            return this->rec(nums,i,mid);
        }else if(nums[i] < nums[mid]){
            return std::min(this->rec(nums,mid,j),nums[i]);
        }
        return std::min(this->rec(nums,i,mid),this->rec(nums,mid,j));
        
    }
};