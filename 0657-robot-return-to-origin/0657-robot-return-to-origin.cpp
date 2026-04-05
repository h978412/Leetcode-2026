class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0;
        int y = 0;
        for(auto el : moves){
            switch(el){
                case 'U':
                    y += 1;
                    break;
                case 'D':
                    y -= 1;
                    break;
                case 'R':
                    x += 1;
                    break;
                case 'L':
                    x -= 1;
                    break;
            }

        }

        if(x==0 && y==0) return true;
        return false;
        
    }
};