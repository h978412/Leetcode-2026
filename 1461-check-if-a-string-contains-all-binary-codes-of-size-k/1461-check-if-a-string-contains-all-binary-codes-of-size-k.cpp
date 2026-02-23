class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_map<string,bool> m;
        for(int i=0;i+k<=s.size();i++){
            string subString = "";
            for(int j=i;j<i+k;j++){
                subString += s[j];
            }

            if(m.find(subString) == m.end()) m[subString] = true;
        }

        int possiblities = pow(2,k);

        

        return possiblities <= m.size() ?  true :  false;
// 
        // return false;
        
    }
};