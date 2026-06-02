class Solution {
public:
    vector<string> ans;
    vector<string> map = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> letterCombinations(string digits) {
        this->rec(digits,0,"");
        return ans;
    }

    void rec(string& digits,int i, string tempAns){
        if(i==digits.size()){
            ans.push_back(tempAns);
            return;
        }
        int digitIndex = digits[i]-'0';
        for(int j=0;j<map[digitIndex].size();j++){
            this->rec(digits,i+1,(tempAns+map[digitIndex][j]));
        }
    }
};