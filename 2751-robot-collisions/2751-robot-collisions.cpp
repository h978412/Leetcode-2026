class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        map<int,pair<int,int>> m;
        vector<int> ans;
        stack<pair<int,int>> st;
        for(int i=0;i<positions.size();i++){
            healths[i] *= directions[i] == 'L'? -1 : 1;
            m[positions[i]] = pair<int,int>{healths[i],i};
        }

        for(auto el : m){
            this->rec(st,el.second);
        }
        m.clear();
        map<int,int> newMap;
        while(!st.empty()){
            newMap[st.top().second] = st.top().first;
            st.pop();
        }

        for(auto el : newMap){
            ans.push_back(abs(el.second));
        }

        return ans;        
    }

    void rec(stack<pair<int,int>>& st, pair<int,int>el){
        if(st.empty() || st.top().first < 0 || el.first > 0){
            st.push(el);
            return;
        }

        auto top = st.top();
        st.pop();
        if(abs(top.first) == abs(el.first)) return;
        else if(abs(top.first) > abs(el.first)) this->rec(st,pair<int,int>{top.first + (top.first/(-1*abs(top.first))),top.second});
        else this->rec(st,pair<int,int>{el.first + (el.first/(-1*abs(el.first))),el.second});
    }
};