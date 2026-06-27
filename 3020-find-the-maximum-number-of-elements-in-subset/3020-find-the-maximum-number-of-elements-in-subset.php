class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function maximumLength($nums) {
        $map = [];
        foreach($nums as $num){
            if(empty($map[$num])) $map[$num] = 1;
            else $map[$num] += 1;
        }
        $maxCount = 0;
        $maxCount = empty($map[1])?0:(($map[1]&1)?$map[1]:$map[1]-1);
        unset($map[1]);

        foreach($map as $value => $key){
            $currCount = 0;
            $newNode = $value;
            // print_r($newNode);
            while(true){
                if(empty($map[$newNode])) break;
                if($map[$newNode] == 1) {$currCount +=1;break;}
                else{
                    $newNode = $newNode ** 2;
                    if(!empty($map[$newNode])) $currCount += 2;
                    else{
                        $currCount += 1;
                        break;
                    }
                }
            }
            $maxCount = max($maxCount,$currCount);
        }

        return $maxCount;

        
    }
}