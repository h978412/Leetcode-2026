class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>m(128,0);
        int l = 0;
        int r = 0;
        int ans = 0;
        while(r<s.size()){
            if(m[s[r]] != 0){
                while(s[r] != s[l]){
                    m[s[l]] = 0;
                    l++;
                }
                if(l<r){
                    l++;
                }
            }
            m[s[r]] = 1;
            ans = max(ans,(r-l+1));
            r++;
        }
        return ans;
        
    }
};