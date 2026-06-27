class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $k
     * @return Integer
     */
    function subarraySum($nums, $k) {
        $sum = 0;
        $map = [];
        $count = 0;

        foreach($nums as $num){
            $sum += $num;
            $target = $sum-$k;
            if(isset($map[$target])) $count += $map[$target];
            if($target == 0) $count++;
            $map[$sum] = isset($map[$sum])?$map[$sum]+1:1;
        }

        return $count;
        
    }
}