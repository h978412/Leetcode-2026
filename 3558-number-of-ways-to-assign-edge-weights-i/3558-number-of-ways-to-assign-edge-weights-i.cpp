class Solution {
public:
    // vector<int>
    int assignEdgeWeights(vector<vector<int>>& edges) {
        vector<vector<int>>m(edges.size()+2);
        for(auto edge : edges){
            m[edge[0]].push_back(edge[1]);
            m[edge[1]].push_back(edge[0]);
        }
        int h = this->dfs(1,0,m);
        long long ans = 1;
        while(--h){
            ans *= 2;
            ans %= 1000000007;
        }
        return ans;
    }

    int dfs(int n, int prv, vector<vector<int>>& m){
        int height = -1;
        for(auto el : m[n]){
            if(el != prv){
                height = max(this->dfs(el,n,m),height);
            }
        }
        return height+1;
    }
};