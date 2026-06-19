class Solution {
    public int longestOnes(int[] nums, int k) {
        int start = 0,end = 0;
        int ans = 0;
        int size = nums.length;

        while(end<size){
            if(nums[end] == 0){
                if(k!=0) k--;
                else{
                    while(start <= end && k== 0){
                        if(nums[start] == 0) k++;
                        start++;
                    }
                    continue;
                }
            }
            ans = Math.max(ans,(end-start+1));
            end++;
        }


        return ans;

        
    }
}