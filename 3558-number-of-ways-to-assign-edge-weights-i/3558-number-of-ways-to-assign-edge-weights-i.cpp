class Solution {
public:
    unordered_map<int,vector<int>>m;
    int assignEdgeWeights(vector<vector<int>>& edges) {
        for(auto edge:edges){
            this->insert(edge[0],edge[1]);
            this->insert(edge[1],edge[0]);
        }
        int height= this->dfs(1,0)-1;
        return this->pow(2,height-1);

    }

    int dfs(int n,int pre){
        int height = 0;
        for(auto el: m[n]){
            if(el != pre){
                height = max(this->dfs(el,n),height);
            }
        }
        return height+1;
    }

    void insert(int u, int v){
        if(m.find(u) == m.end()){
            m[u] = vector<int>{v};
        }else{
            m[u].push_back(v);
        }
    }

    long long pow(long long base, int exp) {
        long long res = 1;

        while (exp) {
            if (exp & 1)
                res = res * base % 1000000007;

            base = base * base % 1000000007;
            exp >>= 1;
        }

        return res;
    }
};