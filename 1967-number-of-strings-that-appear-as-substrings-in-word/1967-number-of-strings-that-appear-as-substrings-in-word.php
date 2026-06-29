class Solution {

    /**
     * @param String[] $patterns
     * @param String $word
     * @return Integer
     */
    function numOfStrings($patterns, $word) {

        $count = 0;
        foreach($patterns as $str){

            if(str_contains($word,$str)) $count++;
        }
        return $count;


        
    }
}