class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int>m;
        // vector<int> ans;
        for(auto& num : nums){
            m[num] += 1;
        }
        auto comp = [&m](int a, int b){
            int c = m[a];
            int d = m[b];
            if(c == d) return a < b;
            return c > d;
        };
        priority_queue<int,vector<int>,decltype(comp)>pq(comp);

        for(auto& num  : nums){
            pq.push(num);
        }
        int i =0;
        while(!pq.empty()){
            nums[i] = pq.top();
            pq.pop();i++;
        }

        return nums;
        
    }
};