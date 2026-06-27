class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer[]
     */
    function productExceptSelf($nums) {
        $isZFound = false;
        $product = 1;
        foreach($nums as $num){
            if($num == 0){
                if($isZFound) $product = 0;
                else $isZFound = true;
            }
            else $product *= $num;
        }
        $ans = [];
        foreach($nums as $num){
            if($isZFound){
                if($num) array_push($ans,0);
                else array_push($ans,$product);
            }
            else array_push($ans,$product/$num);
        }

        return $ans;
        
    }
}