class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<std::string> ans;
        stack<int> s;
        int p =0;
        for(int i=1;i<=n;i++){
            s.push(i);
            ans.push_back("Push");
            if(s.top() == target[p]){
                p++;
                if(p == target.size()) break;
            }else{
                s.pop();
                ans.push_back("Pop");
            }
        }
        return ans;
        
    }
};