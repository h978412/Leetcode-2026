class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        int i =1;
        while(i<=s.size()){
            this->rotate(s);
            if(s == goal) return true;
            i++;
        }

        return false;
        
    }

    void rotate(string &s){
        char temp = s[0];
        for(int i=1;i<s.size();i++){
            s[i-1] = s[i];
        }
        s[s.size()-1] = temp;
    }
};