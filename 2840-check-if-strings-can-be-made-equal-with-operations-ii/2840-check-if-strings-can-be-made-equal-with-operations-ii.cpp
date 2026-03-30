class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<int> m(52,0);
        // vector<int> even(26,0);

        for(int i=0;i<s1.size();i++){
            if(i&1){
                //odd index
                m[(s1[i]-'a')] += 1;
                m[(s2[i]-'a')] -= 1;
            }else{
                //even index
                m[(26+(s1[i]-'a'))] += 1;
                m[(26+(s2[i]-'a'))] -= 1;
            }
        }

        for(auto num : m){
            if(num) return false;
        }

        return true;
        
    }
};
