class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int len = encodedText.size();
        int cols = len/rows;
        string ans = "";
        cout << cols;
        for(int j=0;j<cols;j++){
            for(int i=0;i<rows;i++){
                int row = i;
                int col = j+row;

                int currentIndex = (row*cols) + col;
                if(currentIndex < len){
                    ans += encodedText[currentIndex];
                }
            }
        }



        return this->trim_right(ans);

    }

    string trim_right(string& s){
        if(s.size() == 0 || s[s.size()-1] != ' ') return s;
        s.pop_back();
        return this->trim_right(s);

    }
};