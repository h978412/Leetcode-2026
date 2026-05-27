class Solution {
public:
    int numberOfSpecialChars(string word) {
        std::vector<bool> U(26, false); // Uppercase seen
        std::vector<bool> L(26, false); // Lowercase seen
        std::vector<bool> C(26, true);

        for(auto c : word){
            if(c >= 'A' && c <= 'Z')U[c-'A'] = true;
            else{
                if(U[c-'a']) C[c-'a'] = false;
                else L[c-'a'] = true;   
            }
        }
        int count = 0;
        for(int i=0;i<26;i++){
            if(L[i] && U[i] && C[i]) count++;
        }
        return count;
    }
};