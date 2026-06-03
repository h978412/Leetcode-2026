class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        string temp = "";
        vector<string> temparr;
        vector<string> ans;
        int pt =0;
        while(pt<words.size()){
            temp = temp + words[pt];
            if(temp.size() <= maxWidth){
                temparr.push_back(words[pt]);
                temp += " ";
            }else{
                ans.push_back(this->formatString(temparr,maxWidth));
                temp = words[pt]+ " ";
                temparr.clear();
                temparr.push_back(words[pt]);
            }
            pt++;
        }
        string str = "";
        if(temparr.size()!=0){
            for(int i=0;i<temparr.size();i++) str += (temparr[i]+" ");
        }
        if(str != "") str.pop_back();

        int gap = maxWidth-str.size();
        while(gap--){
            str += " ";
        }
        ans.push_back(str);

        return ans;
    }

    string formatString(vector<string> arr, int maxWidth){
        int size = arr.size()-1;
        string str = "";
        int totalCharSize = 0;
        for(auto c : arr){
            totalCharSize += c.size();
        }
        int spaceSize = maxWidth-totalCharSize;
        if(size == 0){
            str = arr[0];
            while(spaceSize--){
                str += " ";
            }
            return str;
        }

        int eq = spaceSize/size;
        int rem = spaceSize%size;

        for(int i=0;i<arr.size()-1;i++){
            str += arr[i];
            for(int j=0;j<eq;j++){
                str += " ";
            }
            if(rem){
                str += " ";
                rem--;
            }
        }

        return str + arr[arr.size()-1];

    }
};