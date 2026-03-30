class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<int> odd(26,0);
        vector<int> even(26,0);

        for(int i=0;i<s1.size();i++){
            if(i&1){
                //odd index
                odd[(int)(s1[i]-'a')] += 1;
                odd[(int)(s2[i]-'a')] -= 1;
            }else{
                //even index
                even[(int)(s1[i]-'a')] += 1;
                even[(int)(s2[i]-'a')] -= 1;
            }
        }

        for(int i=0;i<26;i++){
            if(odd[i] || even[i]) return false;
        }

        return true;
        
    }
};
