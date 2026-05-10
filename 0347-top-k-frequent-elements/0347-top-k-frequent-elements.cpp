class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        vector<int> ans;
        for(auto num : nums) m[num] += 1;
        priority_queue<pair<int,int>> pq;
        for(auto const& [num, freq] : m){
            pq.push({freq,num});
        }
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;


        
    }
};



