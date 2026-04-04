class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int len = encodedText.size();
        int cols = len/rows;
        string ans = "";
        for(int j=0;j<cols;j++){
            for(int i=0;i<rows;i++){
                int currentIndex = (i*cols) + (j+i);
                if(currentIndex < len){
                    ans += encodedText[currentIndex];
                }
            }
        }

        while(ans.size()!=0 && ans[ans.size()-1] == ' '){
            ans.pop_back();
        }

        return ans;


    }

};