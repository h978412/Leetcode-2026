class Solution {
public:
    unordered_map<int,vector<int>>m;
    int assignEdgeWeights(vector<vector<int>>& edges) {
        for(auto edge:edges){
            this->insert(edge[0],edge[1]);
            this->insert(edge[1],edge[0]);
        }
        int height= this->dfs(1,0)-1;
        long long ans =1;
        while(--height){
            ans *= 2;
            ans %=1000000007; 
        }
        return ans;
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
};