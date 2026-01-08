class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        vector<int> m(s.size(),0);
        int counter = 0;
        int maxCounter = 0;
        for(int i=0;i<s.size();i++){
            if(s[i] == '('){
                st.push(i);
            }else{
                if(!st.empty()){
                    m[i] = 1;
                    m[st.top()] = 1;
                    st.pop();
                }
            }
        }
        for(int i=0;i<m.size();i++){
            if(m[i] == 1){
                counter++;
            }else{
                maxCounter = max(counter,maxCounter);
                counter = 0;
            }
        }
        return max(counter,maxCounter);

        
    }
};