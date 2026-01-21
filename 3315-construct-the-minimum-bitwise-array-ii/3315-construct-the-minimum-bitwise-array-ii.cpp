class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans(nums.size(),-1);
        for(int i=0;i<nums.size();i++){
            if((nums[i] & 1)){
                ans[i] = this->getBitwiseOR(nums[i]);
            }
        }
        return ans;
        
    }
    int getBitwiseOR(int n){

        int pos =1;
        while(n >> pos){
            if(((n >> pos) & 1)){
                pos++;
            }else{
                break;
            }
        }

        if(!(n >> pos)){
            return n >> 1;
        }

        return (n & (~(1 << (pos-1))));
    }
};