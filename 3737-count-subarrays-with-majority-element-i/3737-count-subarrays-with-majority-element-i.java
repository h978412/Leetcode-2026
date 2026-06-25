class Solution {
    public int countMajoritySubarrays(int[] nums, int target) {
        // HashMap<Integer,Integer>hm =new HashMap<Integer,Integer>();
        int ans = 0;
        int mejCount = 0;

        for(int i=0;i<nums.length;i++){
            for(int j=i;j<nums.length;j++){
                if(nums[j] == target){
                    mejCount++;
                }
                if(mejCount > (j-i+1)/2) ans++;
            }
            mejCount = 0;
        }
        return ans;
        
    }
}