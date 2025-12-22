class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int temp[101];
        // vector<int> ans(t.size(),0);
        stack<int> s;
        for(int i=t.size()-1;i>=0;i--){
            int curr = t[i];
            temp[curr] = i;
            while(!s.empty() && s.top()<= curr){
                s.pop();
            }
            if(s.empty()) t[i] = 0;
            else t[i] = temp[s.top()] - i;
            s.push(curr);
        }
        return t;
        
    }
};