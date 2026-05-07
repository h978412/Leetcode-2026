class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxArr(n, nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            maxArr[i] = max(maxArr[i - 1], nums[i]);
        }
        vector<int> ans(n, maxArr[n - 1]);
        map<int, int> m;
        m.insert({nums[n - 1], n - 1});
        ans[n-1] = maxArr[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            auto it = m.lower_bound(nums[i]);
            if (it == m.begin()) {
                auto it1 = m.lower_bound(maxArr[i]);
                if (it1 == m.begin()) {
                    ans[i] = maxArr[i];
                } else {
                    it1 = --it1;
                    ans[i] = ans[m[it1->first]];
                }
                m.insert({nums[i], i});
            } else {
                it = --it;
                ans[i] = ans[m[it->first]];
            }
        }
        return ans;
    }
};