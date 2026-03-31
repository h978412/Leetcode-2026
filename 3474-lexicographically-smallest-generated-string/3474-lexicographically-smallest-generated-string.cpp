class Solution {
public:
    string generateString(string str1, string str2) {
        int wordSize = str1.size() + str2.size() -1;
        string word;
        word.append(wordSize,' ');

        for(int i=0;i<str1.size();i++){
            if(str1[i] == 'T'){
                for(int j=0;j<str2.size();j++){
                    if(word[i+j] == ' ') word[i+j] = str2[j];
                    else if(word[i+j] == str2[j]) continue;
                    else return "";
                }
            }
        }


        for(int i=0;i<str1.size();i++){
            int lastEmptyIndex = -1;
            bool isNotMatched = false;
            if(str1[i] == 'F'){
                for(int j=0;j<str2.size();j++){
                    if(word[i+j] == ' '){
                        lastEmptyIndex = i+j;
                        word[lastEmptyIndex] = 'a';
                    }
                    if(word[i+j] != str2[j]){
                        isNotMatched = true;
                        break;
                    }
                }
                if(isNotMatched) continue;
                else{
                    if(lastEmptyIndex == -1) return "";
                    else word[lastEmptyIndex] = 'b';
                }
            }
            
        }
        std::replace(word.begin(), word.end(), ' ','a');
        return word;
        
    }
};