class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        vector<long long> ans(nums.size(),0);
        vector<pair<int, long long>>lMap(nums.size());
        vector<pair<int, long long>>rMap(nums.size());
        map<int,pair<int,long long>>m;


        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i]) == m.end()){
                lMap[i] = pair<int,long long>{0,0};
                m[nums[i]] = pair<int,long long>{1,i};
            }else{
                lMap[i] = pair<int,long long>{m[nums[i]].first,m[nums[i]].second};
                m[nums[i]] = pair<int,long long>{m[nums[i]].first+1,m[nums[i]].second+i};
            }
        }

        for(int i=0;i<nums.size();i++){
            long long totalICount = m[nums[i]].first;
            long long totalISum = m[nums[i]].second;
            long long leftICount = lMap[i].first;
            long long leftISum  = lMap[i].second;
            long long rightICount = totalICount-leftICount-1;
            long long rightISum = totalISum - leftISum - i;


            ans[i] = (abs(leftISum - leftICount*i) + abs(rightISum - rightICount*i));
        }

        return ans;
        
    }
};