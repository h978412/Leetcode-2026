class Solution {

    /**
     * @param Integer $numCourses
     * @param Integer[][] $prerequisites
     * @return Boolean
     */
    function canFinish($numCourses, $prerequisites) {
        $adjMat = [];
        foreach($prerequisites as $pre){
            if(empty($adjMat[$pre[0]])){
                $adjMat[$pre[0]] = [$pre[1]];
            }else{
                $adjMat[$pre[0]][] = $pre[1];
            }
        }
        $visited = array_fill(0,$numCourses,0);
        foreach($visited as $node=>$isVisited){
            if(!$isVisited){
                $pathVisited = array_fill(0,$numCourses,0);
                if($this->detectCycle($adjMat,$pathVisited,$visited,$node)) return false;
            }
        }
        return true;
    }

    function detectCycle(&$adjMat, &$pathVisited ,&$visited, $node){
        if(empty($adjMat[$node])) return false;
        if($pathVisited[$node] == 1) return true;
        if($visited[$node] == 1) return false;
        $pathVisited[$node] = 1;
        $visited[$node] = 1;
        foreach($adjMat[$node] as $newNode){
            if($this->detectCycle($adjMat,$pathVisited,$visited,$newNode)){
                return true;
            }
        }
        $pathVisited[$node] = 0;
        return false;

    }
}