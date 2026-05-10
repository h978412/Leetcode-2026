class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        for(auto num : nums){
            m[num] += 1;
        }
        auto comparator = [&m](int a, int b){
            return m[a] > m[b];
        };

        priority_queue<int,vector<int>,decltype(comparator)> pq(comparator);
        for(auto const& [key, value] : m){
            pq.push(key);
            if(pq.size() > k) pq.pop();
        }

        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }

        return ans;


        
    }
};



