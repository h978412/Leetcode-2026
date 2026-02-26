class Solution {
public:
    int numSteps(string s) {
        int i=(int)s.size()-1;
        int count = 0;
        while(s.size() > 1){
            if(s[i] == '0') s.pop_back();
            else{
                while(i >= 0 && s[i] == '1'){
                    s[i] = '0';
                    i--;
                }
                if(i == -1) s.insert(0,"1");
                else s[i] = '1';
            }
            count++;
            i = s.size()-1;
            // cout << s << endl;
        }
        return count;
    }
};