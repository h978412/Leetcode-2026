class Solution {
public:
    int longestBalanced(string s) {
        int ans = 0;
        for(int i=0;i<s.size();i++){
            vector<int> map(26,0);
            for(int j=i;j<s.size();j++){
                map[s[j]-'a'] += 1;
                if(this->isBalanced(map)){
                    ans = max(ans,j-i+1);
                }
            }
        }
        return ans;
    }

    bool isBalanced(vector<int>& map){
        int firstCount = 0;
        for(int i=0;i<26;i++){
            if(map[i] == 0) continue;
            else if(firstCount == 0) firstCount = map[i];
            else if(map[i] != firstCount) return false;
            // return true;
        }
        return true;
    }
};