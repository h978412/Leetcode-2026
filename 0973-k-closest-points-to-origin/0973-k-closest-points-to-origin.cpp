class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> pq;

        for(int i=0;i<points.size();i++){
            int d = (points[i][0]*points[i][0] + points[i][1]*points[i][1]);
            pq.push({d,i});
            if(pq.size() > k) pq.pop();
        }

        vector<vector<int>>ans(k,vector<int>(2,0));

        int i = 0;
        while(!pq.empty()){
            int index = pq.top().second;
            pq.pop();
            ans[i] = points[index];
            i++;
        }

        return ans;
        
    }
};