class Solution {
    public int countMajoritySubarrays(int[] nums, int target) {
        HashMap<Integer,Integer>hm =new HashMap<Integer,Integer>();
        int ans = 0;

        for(int i=0;i<nums.length;i++){
            for(int j=i;j<nums.length;j++){
                if(hm.containsKey(nums[j])){
                    hm.put(nums[j],hm.get(nums[j])+1);
                }else{
                    hm.put(nums[j],1);
                }
                if(hm.containsKey(target) && hm.get(target)>(j-i+1)/2) ans++;
                // System.out.println(hm);
            }
            hm.clear();
        }
        return ans;
        
    }
}