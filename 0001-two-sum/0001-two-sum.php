class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer[]
     */
    function twoSum($nums, $target) {
        $map = [];
        foreach($nums as $index => $num){
            $rem = $target-$num;
            if(isset($map[$rem])) return[$index,$map[$rem]];
            $map[$num] = $index;
        }
    }
}