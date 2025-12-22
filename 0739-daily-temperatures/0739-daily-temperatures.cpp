class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int temp[101];
        vector<int> ans(t.size(),0);
        stack<int> s;
        for(int i=t.size()-1;i>=0;i--){
            temp[t[i]] = i;
            while(!s.empty() && s.top()<= t[i]){
                s.pop();
            }
            if(s.empty()) ans[i] = 0;
            else ans[i] = temp[s.top()] - i;
            s.push(t[i]);
        }
        return ans;
        
    }
};