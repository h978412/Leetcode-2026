class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        vector<bool> m(s.size(),false);
        int counter = 0;
        int maxCounter = 0;
        for(int i=0;i<s.size();i++){
            if(s[i] == '('){
                st.push(i);
            }else{
                if(!st.empty()){
                    m[i] = true;
                    m[st.top()] = true;
                    st.pop();
                }
            }
        }
        for(auto i : m){
            if(i){
                counter++;
            }else{
                maxCounter = max(counter,maxCounter);
                counter = 0;
            }
        }
        return max(counter,maxCounter);

        
    }
};