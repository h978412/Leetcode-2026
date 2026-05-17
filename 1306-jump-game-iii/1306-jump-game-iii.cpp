class Solution {
public:
    bool visited[100000] = {false};
    bool canReach(vector<int>& arr, int start) {
        if((start >= arr.size())  || (start < 0)) return false;
        if(this->visited[start]) return false;
        if(arr[start] == 0) return true;
        this->visited[start] = true;
        return (this->canReach(arr,start+arr[start]) || this->canReach(arr,start-arr[start]));
    }
};