class Solution {

    /**
     * @param Integer[] $arr
     * @return Integer
     */
    function maximumElementAfterDecrementingAndRearranging($arr) {
        sort($arr);
        $arr[0] = 1;
        $prv = 1;
        foreach($arr as &$num){
            if($num != $prv){
                $prv++;
                $num = $prv;
            }
        }
        return $prv; 
    }
}