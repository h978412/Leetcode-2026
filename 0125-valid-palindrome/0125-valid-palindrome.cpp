class Solution {
public:
    bool isPalindrome(string s) {
        int i=0,j=s.size()-1;
        int up= int('a');
        int lw = int('z');
        int UP = int('A');
        int LW = int('Z');
        int numup = int('0');
        int numlw = int('9');

        while(i<j){
            int left;
            int right;
            if(int(s[i]) >=up && int(s[i]) <= lw){
                left = lw-int(s[i]);
            }else if(int(s[i]) >=UP && int(s[i]) <= LW){
                left = LW - int(s[i]);
            }else if(int(s[i]) >=numup && int(s[i]) <= numlw){
                left = numlw - int(s[i]);
            }else{
                i++;
                continue;
            }
            if(int(s[j]) >=up && int(s[j]) <= lw){
                right = lw-int(s[j]);
            }else if(int(s[j]) >=UP && int(s[j]) <= LW){
                right = LW - int(s[j]);
            }else if(int(s[j]) >=numup && int(s[j]) <= numlw){
                right = numlw - int(s[j]);
            }else{
                j--;
                continue;
            }
            if(left != right){
                return false;
            }
            i++;j--;
        }
        return true;

    }
};