class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int ans = 0;
        int uCount = 0;
        for(auto move : moves){
            if(move == 'L') ans--;
            else if(move == 'R') ans++;
            else uCount++;
        }

        return abs(ans)+uCount;
        
    }
};