class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>>m(s1.size()+1,vector<int>(s2.size()+1,-1));
        return this->rec(s1,s2,s1.size(),s2.size(),m);

    }
    int rec(string& s1, string& s2, int i, int j,vector<vector<int>>& m){
        if(m[i][j] != -1) return m[i][j];
        if(i==0 && j==0) return 0;
        int count1=INT_MAX,count2=INT_MAX,count3=INT_MAX;
        if(i>0){
            count1 = this->rec(s1,s2,i-1,j,m) + s1[i-1];
        }
        if(j>0){
            count2 = this->rec(s1,s2,i,j-1,m) + s2[j-1];
        }
        if(i>0 && j> 0 && s1[i-1] == s2[j-1]){
            count3 = this->rec(s1,s2,i-1,j-1,m);
        }
        m[i][j] = min({count1,count2,count3});
        return m[i][j];
    }
};