class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int>ans;
        auto comp = [&x] (int a, int b){
            int c = abs(x-a);
            int d = abs(x-b);
            if(c == d) return a < b;
            return c < d; 
        };
        priority_queue<int,vector<int>,decltype(comp)> pq(comp);

        for(auto& num : arr){
            pq.push(num);
            if(pq.size() > k) pq.pop();
        }

        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};