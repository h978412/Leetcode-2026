class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0;
        int y = 0;
        for(auto el : moves){
            if(el == 'U'){
                y += 1;
            }else if(el == 'D'){
                y -= 1;
            }else if(el == 'R'){
                x += 1;
            }else if(el == 'L'){
                x -= 1;
            }
        }

        if(x==0 && y==0) return true;
        return false;
        
    }
};