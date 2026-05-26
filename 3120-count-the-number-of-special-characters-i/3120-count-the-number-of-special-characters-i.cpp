class Solution {
public:
    int numberOfSpecialChars(string word) {
        bool arr[128] = {false};
        for(auto c: word){
            arr[c] = true;
        }
        int count = 0;
        for(int i=0;i<26;i++){
            if(arr['a'+i] && arr['A'+i]) count++;
        }
        return count;
    }
};