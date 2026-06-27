class Solution {
    function subarraySum($nums, $k) {
        $count = 0;
        $sum = 0;
        
        // 1. Pre-seed the base case to remove the inner if($target == 0) check
        $map = [0 => 1]; 

        foreach ($nums as $num) {
            $sum += $num;
            
            // 2. Calculate directly in the check
            if (isset($map[$sum - $k])) {
                $count += $map[$sum - $k];
            }
            
            // 3. In-place modification instead of ternary reassignment
            if (isset($map[$sum])) {
                $map[$sum]++;
            } else {
                $map[$sum] = 1;
            }
        }

        return $count;
    }
}