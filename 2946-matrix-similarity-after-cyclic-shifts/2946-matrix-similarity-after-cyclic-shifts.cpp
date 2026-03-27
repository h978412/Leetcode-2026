class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        k = (k % n);
        if(k==0) return true;
        for(int j=0;j<m;j++){
            if(j%2==0){
                for(int i=0;i<n;i++){
                    if(i<k && mat[j][i] != mat[j][n-k+i]) return false;
                    if(i>=k && mat[j][i] != mat[j][i-k]) return false;
                }
            }
            else{
                int newIterator;
                for(int i=n;i>0;i--){
                    newIterator = n-i;
                    if(newIterator < k && mat[j][i-1] != mat[j][k-newIterator-1]) return false;
                    if(newIterator >=k && mat[j][i-1] != mat[j][i+k-1]) return false;
                }

            }
        }

        return true;

    }
};