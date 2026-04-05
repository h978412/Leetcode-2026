class Solution {
public:
    bool judgeCircle(string moves) {
        int dx[128] = {0};
        int dy[128] = {0};
        dy['U'] =1; dy['D'] = -1;
        dx['L'] = -1; dx['R'] = 1;
        int x = 0;
        int y = 0;
        for(auto el : moves){
            x += dx[el];
            y += dy[el];
        }

        if(x==0 && y==0) return true;
        return false;
        
    }
};