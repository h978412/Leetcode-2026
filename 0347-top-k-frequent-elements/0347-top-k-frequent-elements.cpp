class Solution {
public:
    struct Compare{
        map<int,int>& m;
        Compare(map<int,int>& mapRef) : m(mapRef){}
        bool operator()(int a, int b){
            return m.at(a) > m.at(b);
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>m;
        for(auto num : nums){
            m[num] += 1;
        }

        priority_queue<int,vector<int>,Compare> pq((Compare(m)));
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



