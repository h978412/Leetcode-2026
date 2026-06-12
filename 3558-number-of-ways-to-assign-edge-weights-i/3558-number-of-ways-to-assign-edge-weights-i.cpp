class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        vector<vector<int>> tree = this->buildTree(edges);
        int height = this->dfs(tree,1,0);
        return this->powOfTwo(height-1);


    }
    int powOfTwo(int n){
        long long base = 2;
        int mod = 1000000007;
        long long result = 1;
        while(n){
            if(n&1) 
                result = (result*base) % mod;
            
            base = (base*base) % mod;
            n >>= 1;
        }
        return result;
    }
    int dfs(vector<vector<int>>& tree, int n, int p){
        int height = -1;
        for(const auto& el : tree[n]){
            if(el^p){
                height = max(height,this->dfs(tree,el,n));
            }
        }
        return height+1;
    }
    vector<vector<int>> buildTree(vector<vector<int>>& edges){
        vector<vector<int>>tree(edges.size()+2);
        for(const auto& edge : edges){
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }

        return tree;
    }
};