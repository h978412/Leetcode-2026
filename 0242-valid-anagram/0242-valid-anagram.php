class Solution {

    /**
     * @param String $s
     * @param String $t
     * @return Boolean
     */
    function isAnagram($s, $t) {
        if(strlen($s) != strlen($t)) return false;
        $map = [];
        foreach(str_split($s) as $char){
            if(isset($map[$char])) $map[$char] += 1;
            else $map[$char] = 1;
        }
        foreach(str_split($t) as $char){
            if(isset($map[$char])) $map[$char] -= 1;
            else $map[$char] = -1;
        }
        foreach($map as $index=>$value){
            if($value != 0) return false;
        }
        return true;
    }
}