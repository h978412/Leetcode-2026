class Solution {
public:
    string longestPalindrome(string s) {
        int maxLen = INT_MIN;
        vector<vector<int>> m(s.size(),vector<int>(s.size(),0));
        int startIndex = 0, endIndex = 0;
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(this->isPalindrome(i,j,s,m)){
                    if((j-i+1) > maxLen){
                        maxLen = j-i+1;
                        startIndex = i;
                        endIndex = j;
                    }
                }
            }
        }
        return s.substr(startIndex,maxLen);   
    }

    bool isPalindrome(int i, int j, string& s,vector<vector<int>>& m){
        if(j<i || i==j) return true;
        if(m[i][j] == 0){
            if(s[i] == s[j] && this->isPalindrome(i+1,j-1,s,m)) m[i][j] = 1;
            else m[i][j] = -1;
        }
        if(m[i][j] == -1){
            return false;
        }
        return true;
    }
    
};