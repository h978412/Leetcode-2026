class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>>m(1001,vector<int>(1001));
        m[0][0] = 0;
        for(int i=1;i<=s1.size();i++) m[i][0] = m[i-1][0] + s1[i-1];
        for(int i=1;i<=s2.size();i++) m[0][i] = m[0][i-1] + s2[i-1];
        for(int i=1;i<=s1.size();i++){
            for(int j=1;j<=s2.size();j++){
                int count1=INT_MAX,count2=INT_MAX,count3=INT_MAX;
                if(s1[i-1] == s2[j-1]){
                    m[i][j] = m[i-1][j-1];
                }else{
                    m[i][j] = min(m[i-1][j] + s1[i-1],m[i][j-1] + s2[j-1]);
                }
            }
        }
        return m[s1.size()][s2.size()];
    }

};