class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int>maxArr(n,nums[0]);
        for(int i=1;i<nums.size();i++){
            maxArr[i] = max(maxArr[i-1],nums[i]);
        }
        vector<int>ans(n,maxArr[n-1]);
        set<int> s;
        map<int,int> m;

        for(int i=n-1;i>=0;i--){
            if(s.empty()){
                s.insert(nums[i]);
                m.insert({nums[i],i});
                ans[i] = maxArr[i];
            }else{
                auto it = s.lower_bound(nums[i]);
                    if(it == s.begin()){
                        auto it1 = s.lower_bound(maxArr[i]);
                        if(it1 == s.begin()){
                            ans[i] = maxArr[i];
                        }else{
                            it1 = --it1;
                            int el = *it1;
                            ans[i] = ans[m[el]];
                        }

                        s.insert(nums[i]);
                        m.insert({nums[i],i});
                    }else{
                        it = --it;
                        int el = *it;
                        ans[i] = ans[m[el]];
                    }
            }
        }
     return ans;   
    }
};